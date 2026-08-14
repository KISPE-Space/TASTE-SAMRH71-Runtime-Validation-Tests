#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import common
import time
import os
import sys
from pygdbmi.gdbcontroller import GdbController
from termcolor import cprint, colored

# Fixed configuration
TARGET_HARDWARE = "samrh71"
BINARY_SUB_PATH = "work/binaries/partition_1"
DEFAULT_GDB_BINARY_PATH = "/opt/taste-rtems-qdp-arm/bin/arm-rtems6-gdb"
DEFAULT_MAKE_RECIPE = "debug"
DEFAULT_GDB_SERVER_TCP_PORT = "127.0.0.1:2331"
DEFAULT_GDB_VERBOSE = False

# Default configuration - can be overridden by arguments
gdb_binary_path = os.getenv("GDB_BINARY_PATH", default=DEFAULT_GDB_BINARY_PATH)
gdb_server_tcp_port = os.getenv("SAMRH71_REMOTE_GDBSERVER", default=DEFAULT_GDB_SERVER_TCP_PORT)
model_name = None
build_recipe = DEFAULT_MAKE_RECIPE
skip_build = False
gdb_verbose = DEFAULT_GDB_VERBOSE


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

        # Run the model
        gdb_command(gdbmi, "c", "Running the model")

        # PLACEHOLDER: Wait a little for the output to be generated (in future can watch to see when the data transmission is complete)
        time.sleep(0.1)

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
        elif arg == "--skip_build":
            skip_build = True

    # Assert that a model name is provided, otherwise exit with an error
    if model_name is None:
        print("Error: model_name is not set")
        sys.exit(1)

    # Perform the build
    if not skip_build:
        build()

    # Perform the deployment
    deploy()
