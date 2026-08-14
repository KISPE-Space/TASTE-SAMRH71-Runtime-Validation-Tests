#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import argparse
import common
import subprocess
import json
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
GCDA_OUTPUT_PATH = "test_output/coverage_tmp"
TEST_RESULTS_OUTPUT_PATH = "test_output/test_results.log"

# Defaults
DEFAULT_GDB_BINARY_PATH = "/opt/taste-rtems-qdp-arm/bin/arm-rtems6-gdb"
DEFAULT_MAKE_RECIPE = "debug"
DEFAULT_GDB_SERVER_TCP_PORT = "127.0.0.1:2331"
DEFAULT_GDB_VERBOSE = False
DEFAULT_UART_LISTEN_DEVICE = "/dev/ttyUSB0"
DEFAULT_SSH_FOR_UART = None
DEFAULT_SKIP_BUILD = False
DEFAULT_GDB_COMMAND_TIMEOUT = 3

# Global variable for SSH login for the host that has the SAMRH71 UART device, if needed
uart_ssh_login = DEFAULT_SSH_FOR_UART


# Processes line output received over UART
def process_uart_lines(uart_listener):

    for line in uart_listener.stdout:
        cprint(line, color="blue", attrs=['bold'], end="")
    return

    # Ensure that the output paths exist
    os.makedirs(GCDA_OUTPUT_PATH, exist_ok=True)
    os.makedirs(os.path.dirname(TEST_RESULTS_OUTPUT_PATH), exist_ok=True)

    # Parse the lines to extract test results and GCDA files
    test_results = []
    gcda_files = []
    for line in uart_listener.stdout:
        if line.startswith("TEST_RESULT:"):
            test_results.append(line)
        elif line.startswith("GCDA_FILENAME:"):
            filename = line.split(":")[1]
            gcda_files.append(filename)
        elif line.startswith("GCDA_HEX:"):
            hex_data = line.split(":")[1]
            # Write out the hex data as a file on disk in the output folder
            if gcda_files:
                gcda_filename = gcda_files[-1]
                output_path = f"{GCDA_OUTPUT_PATH}/{gcda_filename}"
                with open(output_path, 'wb') as gcda_file:
                    gcda_file.write(bytes.fromhex(hex_data))
                    print(f"Wrote GCDA file: {gcda_filename} ({len(bytes.fromhex(hex_data))} bytes)")

    # Also write any test results to the output folder as test_results.log
    if test_results:
        with open(TEST_RESULTS_OUTPUT_PATH, 'w') as test_results_file:
            for test_result in test_results:
                test_results_file.write(f"{test_result}\n")
            print(f"Wrote {len(test_results)} test results to: {TEST_RESULTS_OUTPUT_PATH}")


# Runs a command on the host that holds the UART device.
# command should be a list of parts, e.g. ["ls", "-l", "/dev/ttyUSB0"]
def start_target_host_process(command):

    # Adjust the command to take into account any requuired tunneling to the target host
    command = ["ssh", "-T", uart_ssh_login] + [" ".join(command)] if uart_ssh_login else command

    # Start the process, using Popen() to allow for non-blocking execution
    print(colored(f"Running command (non-blocking): {' '.join(command)}", "yellow"), flush=True)
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

    # Return the process handle
    return process


# Runs a command on the host that holds the UART device.
# command should be a list of parts, e.g. ["ls", "-l", "/dev/ttyUSB0"]
def run_target_host_command(command):

    # Adjust the command to take into account any requuired tunneling to the target host
    command = ["ssh", "-T", uart_ssh_login] + command if uart_ssh_login else command
    print(colored(f"Running command {' '.join(command)}", "yellow"), flush=True)

    # Blocking request, so use subprocess.run()
    process = subprocess.run(command, capture_output=True, text=True, bufsize=1) # line-buffered

    # Return the stdout output of the command
    return process.stdout.strip()


def print_gdb_responses(responses, gdb_verbose=DEFAULT_GDB_VERBOSE):
    for msg in responses:
        if type(msg) is not dict:
            message = msg["payload"].strip()
        else:
            message = json.dumps(msg["payload"]).strip().strip('"')
        if msg["type"] == "output":
            if message:
                cprint(f"[GDB]: {message}", "cyan", attrs=[])
        elif gdb_verbose:
            if msg["type"] == "log":
                color = "yellow"
            elif msg["type"] == "console":
                color = "light_grey"
            elif msg["type"] == "result":
                color = "green"
            else:
                color = "white"
            cprint(f"[GDB]: {message}", color, attrs=['dark'])


# Runs a command on the open gdb session, and prints the output to the console
def gdb_command(gdbmi, command, description=None, timeout=DEFAULT_GDB_COMMAND_TIMEOUT, gdb_verbose=DEFAULT_GDB_VERBOSE):

    if not description:
        description = command
    print(colored(description, "magenta"), end="\n", flush=True)
    #gdbmi.write(command)

    # Execute the command and capture responses
    responses = gdbmi.write(command)

    # Specifically look for the completion record
    while True:
        print_gdb_responses(responses, gdb_verbose=gdb_verbose)
        found_result = False
        for r in responses:
            if r["type"] == "result":
                found_result = True
                break
        if found_result:
            break

        # Try again to fetch responses, with a timeout to avoid hanging indefinitely
        responses = gdbmi.get_gdb_response(timeout_sec=1)


# Build the model using the specified recipe
def build(
        model_name,
        build_recipe=DEFAULT_MAKE_RECIPE,
):

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
def deploy(
        model_name,
        gdb_binary_path=DEFAULT_GDB_BINARY_PATH,
        gdb_server_tcp_port=DEFAULT_GDB_SERVER_TCP_PORT,
        uart_listen_device=DEFAULT_UART_LISTEN_DEVICE,
        gdb_verbose=DEFAULT_GDB_VERBOSE,
):

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
        gdb_command(gdbmi, f"target extended-remote {gdb_server_tcp_port}", gdb_verbose=gdb_verbose)

        # Tell gdb to pull in the binary file
        gdb_command(gdbmi, f"-file-exec-and-symbols {model_binary_path}", gdb_verbose=gdb_verbose)

        # Reset the target
        gdb_command(gdbmi, "monitor reset", gdb_verbose=gdb_verbose)
        #gdb_command(gdbmi, "-thread-info", gdb_verbose=gdb_verbose)

        # Ensure that full reset occurs, to avoid spurious errors in the model execution
        #common.target_extended_reset(gdbmi)

        # Tell gdb not to ask for any confirmations
        gdb_command(gdbmi, "set confirm off", gdb_verbose=gdb_verbose)

        # Load the model onto the target
        gdb_command(gdbmi, "load", gdb_verbose=gdb_verbose)

        # Connect to the UART listen device, before the model starts running
        uart_listener = start_target_host_process(["stty", "-F", uart_listen_device] + UART_TTY_CONFIG + ["&&", "awk '{print} /END_OF_OUTPUT/{exit}'", uart_listen_device])
        if not uart_listener:
            raise RuntimeError(f"Failed to start UART listener on {uart_listen_device}")

        # Run the model
        gdb_command(gdbmi, "c", "Running the model", gdb_verbose=gdb_verbose)

        # Process the stdout we receive from the listener
        process_uart_lines(uart_listener)

        # Likely not necessary, but added here so its clear that we intend for the object to be cleaned up
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
    parser = argparse.ArgumentParser(
        description="Build and deploy a TASTE model to the target hardware.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    parser.add_argument("--model", default=None, help="Name of the model to build and deploy")
    parser.add_argument("--build_recipe", default=DEFAULT_MAKE_RECIPE, help="Make recipe to use for the build")
    parser.add_argument("--gdb_binary_path", default=os.getenv("GDB_BINARY_PATH", default=DEFAULT_GDB_BINARY_PATH), help="Path to the GDB binary")
    parser.add_argument("--gdb_server_tcp_port", default=os.getenv("SAMRH71_REMOTE_GDBSERVER", default=DEFAULT_GDB_SERVER_TCP_PORT), help="TCP endpoint for the GDB remote target")
    parser.add_argument("--gdb_verbose", action="store_true", default=DEFAULT_GDB_VERBOSE, help="Enable verbose GDB output")
    parser.add_argument("--uart_listen_device", default=os.getenv("SAMRH71_UART_DEVICE", default=DEFAULT_UART_LISTEN_DEVICE), help="UART device to use for monitoring model output")
    parser.add_argument("--skip_build", action="store_true", default=DEFAULT_SKIP_BUILD, help="Skip the build step")
    parser.add_argument("--uart_ssh_login", default=os.getenv("SAMRH71_SSH_FOR_UART", default=None), help="SSH login for the host that has the SAMRH71 UART device, if needed")
    args = parser.parse_args()

    # Capture the SSH login for the host that has the SAMRH71 UART device, if one was provided
    uart_ssh_login = args.uart_ssh_login

    # Assert that a model name is provided, otherwise exit with an error
    if args.model is None:
        print("Error: model_name is not set")
        sys.exit(1)

    # Assert that we have a valid UART listen device
    device_match_lines = run_target_host_command(["ls", args.uart_listen_device])
    if args.uart_listen_device not in device_match_lines:
        print(f"Error: UART listen device {args.uart_listen_device} not found")
        sys.exit(1)

    # Ensure that nothing is running on the UART listen device before we start the model, by running the linux lsof command
    lsof_output = run_target_host_command(["lsof", args.uart_listen_device])
    if lsof_output:
        lines = lsof_output.splitlines()
        lines = [line for line in lines if not line.startswith("COMMAND")]
        if lines:
            print(f"Error: UART listen device {args.uart_listen_device} is already in use")
            print("\n".join(lines))
            sys.exit(1)

    # Perform the build
    if not args.skip_build:
        build(args.model, build_recipe=args.build_recipe)

    # Perform the deployment
    deploy(args.model,
        gdb_binary_path=args.gdb_binary_path,
        gdb_server_tcp_port=args.gdb_server_tcp_port,
        uart_listen_device=args.uart_listen_device,
        gdb_verbose=args.gdb_verbose
    )
