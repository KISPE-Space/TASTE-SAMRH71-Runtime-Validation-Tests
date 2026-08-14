#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import common
import time
import os
from pygdbmi.gdbcontroller import GdbController
from termcolor import cprint, colored

DO_BUILD = False
MODEL_NAME = "model-stacks"
TARGET_HARDWARE = "samrh71"
MAKE_RECIPE = "debug"   # Change to "coverage to get coverage"
GDB_BINARY_PATH = "/opt/taste-rtems-qdp-arm/bin/arm-rtems6-gdb"
GDB_SERVER_TCP_PORT = os.getenv("SAMRH71_REMOTE_GDBSERVER", default="127.0.0.1:2331")
MODEL_BINARY_FILE_PATH = MODEL_NAME + "/work/binaries/partition_1"


def gdb_command(gdbmi, command, description=None, timeout=3):

    if not description:
        description = command
    print(colored(description + " ... ", "magenta"), end="", flush=True)
    gdbmi.write(command)
    try:
        responses = gdbmi.get_gdb_response(timeout_sec=timeout)
        for msg in responses:
            cprint(f"[GDB]: {msg}", "cyan", attrs=['dark'])
    except:
        pass
    print(colored("done", "magenta"), flush=True)


def build():

    # Perform a make-clean on the model build folders
    print("make clean ... ", end="", flush=True)
    common.do_clean_build(MODEL_NAME)
    print("done", flush=True)

    # Perform a make on the intended target recipe, and ensure success
    print(f"make {TARGET_HARDWARE} {MAKE_RECIPE} ... ", end="", flush=True)
    build = common.do_build(MODEL_NAME, [TARGET_HARDWARE, MAKE_RECIPE])
    stderr = build.stderr.decode("utf-8")
    assert build.returncode == 0, f"Compilation errors: \n{stderr}"
    print("done", flush=True)


def deploy():

    # Start a gdb session
    print(colored(f"Starting gdb session with {GDB_BINARY_PATH} ... ", "yellow"), end="", flush=True)
    gdbmi = GdbController(command=[GDB_BINARY_PATH, "--interpreter=mi2"])
    print(colored("done", "yellow"), flush=True)
    #print(gdbmi.command)  # print actual command run as subprocess

    # Configure gdb with the location of the server
    gdb_command(gdbmi, f"target extended-remote {GDB_SERVER_TCP_PORT}")

    # Tell gdb to pull in the binary file
    gdb_command(gdbmi, f"file {MODEL_BINARY_FILE_PATH}")

    # Reset the target
    gdb_command(gdbmi, "monitor reset")

    # Reset HARDER!
    #common.target_extended_reset(gdbmi)

    # Load the model onto the target
    gdb_command(gdbmi, "load")

    # Run the model
    gdb_command(gdbmi, "c", "Running the model")

    # Wait a few seconds for the output to be generated (in future can watch to see when the data transmission is complete)
    time.sleep(1)

    cprint("\nAll done!\n", "green")


if __name__ == "__main__":
    if DO_BUILD:
        build()
    deploy()
