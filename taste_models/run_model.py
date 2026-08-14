#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import common
import subprocess
import time
import os
import sys
from pygdbmi.gdbcontroller import GdbController
from termcolor import cprint, colored

# Fixed configuration
TARGET_HARDWARE = "samrh71"
BINARY_SUB_PATH = "work/binaries/partition_1"
UART_XONXOFF    = False
UART_TIMEOUT    = 1
UART_TTY_CONFIG = ["115200", "cs8", "parenb", "raw", "-echo"]

# Defaults
DEFAULT_GDB_BINARY_PATH = "/opt/taste-rtems-qdp-arm/bin/arm-rtems6-gdb"
DEFAULT_MAKE_RECIPE = "debug"
DEFAULT_GDB_SERVER_TCP_PORT = "127.0.0.1:2331"
DEFAULT_GDB_VERBOSE = False
DEFAULT_UART_LISTEN_DEVICE = "/dev/ttyUSB0"
DEFAULT_SSH_FOR_UART = None

# Default configuration - can be overridden by arguments
gdb_binary_path = os.getenv("GDB_BINARY_PATH", default=DEFAULT_GDB_BINARY_PATH)
gdb_server_tcp_port = os.getenv("SAMRH71_REMOTE_GDBSERVER", default=DEFAULT_GDB_SERVER_TCP_PORT)
model_name = None
build_recipe = DEFAULT_MAKE_RECIPE
skip_build = False
uart_listen_device = os.getenv("SAMRH71_UART_DEVICE", default=DEFAULT_UART_LISTEN_DEVICE)
gdb_verbose = DEFAULT_GDB_VERBOSE
ssh_for_uart = os.getenv("SAMRH71_SSH_FOR_UART", default=DEFAULT_SSH_FOR_UART)


# Runs a command on the host that holds the UART device.
# command should be a list of parts, e.g. ["ls", "-l", "/dev/ttyUSB0"]
def start_target_host_process(command):

    # Adjust the command to take into account any requuired tunneling to the target host
    command = ["ssh", "-T", ssh_for_uart] + [" ".join(command)] if ssh_for_uart else command

    # Start the process, using Popen() to allow for non-blocking execution
    print(colored(f"Running command (non-blocking): {' '.join(command)}", "yellow"), flush=True)
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

    # Return the process handle
    return process


# Runs a command on the host that holds the UART device.
# command should be a list of parts, e.g. ["ls", "-l", "/dev/ttyUSB0"]
def run_target_host_command(command):

    # Adjust the command to take into account any requuired tunneling to the target host
    command = ["ssh", "-T", ssh_for_uart] + command if ssh_for_uart else command
    print(colored(f"Running command {' '.join(command)}", "yellow"), flush=True)

    # Blocking request, so use subprocess.run()
    process = subprocess.run(command, capture_output=True, text=True, bufsize=1) # line-buffered

    # Return the stdout output of the command
    return process.stdout.strip()


# Runs a command on the open gdb session, and prints the output to the console
def gdb_command(gdbmi, command, description=None, timeout=3):

    if not description:
        description = command
    print(colored(description + " ... ", "magenta"), end="", flush=True)
    gdbmi.write(command)
    try:
        responses = gdbmi.get_gdb_response(timeout_sec=timeout)
        for msg in responses:
            if msg["type"] == "output":
                message = msg["payload"].strip()
                if message:
                    cprint(f"[GDB]: {message}", "cyan", attrs=[])
            elif gdb_verbose:
                cprint(f"[GDB]: {msg}", "cyan", attrs=['dark'])
    except:
        pass
    print(colored("done", "magenta"), flush=True)


# Build the model using the specified recipe
def build():

    # Perform a make-clean on the model build folders
    print("make clean ... ", end="", flush=True)
    common.do_clean_build(model_name)
    print("done", flush=True)

    # Perform a make on the intended target recipe, and ensure success
    print(f"make {TARGET_HARDWARE} {build_recipe} ... ", end="", flush=True)
    build = common.do_build(model_name, [TARGET_HARDWARE, build_recipe])
    stderr = build.stderr.decode("utf-8")
    assert build.returncode == 0, f"Compilation errors: \n{stderr}"
    print("done", flush=True)

    # Report end of building process
    cprint("\nBuild finished\n", "green", attrs=['bold'])


# Deploy the model to the target hardware using gdb
def deploy():

    # Fail if model_name is not set
    if model_name is None:
        print("Error: model_name is not set")
        sys.exit(1)

    # Determine the path to the model binary
    model_binary_path = model_name + "/" + BINARY_SUB_PATH

    # Catch all gdb errors
    try:

        # Start a gdb session
        print(colored(f"Starting gdb session with {gdb_binary_path} ... ", "yellow"), end="", flush=True)
        gdbmi = GdbController(command=[gdb_binary_path, "--interpreter=mi2"])
        print(colored("done", "yellow"), flush=True)
        #print(gdbmi.command)  # print actual command run as subprocess

        # Configure gdb with the location of the server
        gdb_command(gdbmi, f"target extended-remote {gdb_server_tcp_port}")

        # Tell gdb to pull in the binary file
        gdb_command(gdbmi, f"file {model_binary_path}")

        # Reset the target
        gdb_command(gdbmi, "monitor reset")

        # Load the model onto the target
        gdb_command(gdbmi, "load")

        # Connect to the UART listen device, before the model starts running
        uart_listener = start_target_host_process(["stty", "-F", uart_listen_device] + UART_TTY_CONFIG + ["&&", "exec", "cat", uart_listen_device])
        if not uart_listener:
            raise RuntimeError(f"Failed to start UART listener on {uart_listen_device}")

        # Run the model
        gdb_command(gdbmi, "c", "Running the model")

        # Fetch all the output from the UART listen device process, from stdout
        for line in uart_listener.stdout:
            cprint(line, color="blue", attrs=['bold'], end="")

            if "END_OF_OUTPUT" in line:
                uart_listener.terminate()  # or uart_listener.kill()
                break

        # Optional: wait for process to exit and clean up
        uart_listener.wait()

        # Report end of deployment process
        cprint("\nDeployment finished\n", "green", attrs=['bold'])

    # Report any errors that occur during the gdb session
    except Exception as e:
        cprint(f"\nError during deployment: {e}\n", "red", attrs=['bold'])

    # Ensure we always exit gdb cleanly, even if an error occurs
    finally:
        gdbmi.exit()


if __name__ == "__main__":

    # Parse the arguments
    for arg in sys.argv[1:]:
        if arg.startswith("--model="):
            model_name = arg.split("=")[1]
        elif arg.startswith("--build_recipe="):
            build_recipe = arg.split("=")[1]
        elif arg.startswith("--gdb_binary_path="):
            gdb_binary_path = arg.split("=")[1]
        elif arg.startswith("--gdb_server_tcp_port="):
            gdb_server_tcp_port = arg.split("=")[1]
        elif arg.startswith("--gdb_verbose="):
            gdb_verbose = arg.split("=")[1].lower() in ("true", "1", "yes")
        elif arg.startswith("--uart_listen_device="):
            uart_listen_device = arg.split("=")[1]
        elif arg == "--skip_build":
            skip_build = True
        elif arg == "--help" or arg == "-h":
            print("Usage: python run_model.py [--model=<model_name>] [--build_recipe=<recipe>] [--gdb_binary_path=<path>] [--gdb_server_tcp_port=<port>] [--gdb_verbose=<true|false>] [--uart_listen_device=<device>] [--skip_build]")
            sys.exit(0)

    # Assert that a model name is provided, otherwise exit with an error
    if model_name is None:
        print("Error: model_name is not set")
        sys.exit(1)

    # Assert that we have a valid UART listen device
    device_match_lines = run_target_host_command(["ls", uart_listen_device])
    if uart_listen_device not in device_match_lines:
        print(f"Error: UART listen device {uart_listen_device} not found")
        sys.exit(1)

    # Ensure that nothing is running on the UART listen device before we start the model, by running the linux lsof command
    lsof_output = run_target_host_command(["lsof", uart_listen_device])
    if lsof_output:
        lines = lsof_output.splitlines()
        lines = [line for line in lines if not line.startswith("COMMAND")]
        if lines:
            print(f"Error: UART listen device {uart_listen_device} is already in use")
            print("\n".join(lines))
            sys.exit(1)
    print(colored(f"done", "yellow"), end="", flush=True)

    # Perform the build
    if not skip_build:
        build()

    # Perform the deployment
    deploy()
