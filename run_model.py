#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# The tests rely on a UART connection from FLEXCOM1 ("uart1") on the SAMRH71 target, to a host machine. The UART device
# is configured via the argument --uart_listen_device, which defaults to /dev/ttyUSB0. The host machine must have a GDB server 
# running on it, which is connected to the target hardware. The GDB server is configured via the argument --gdb_server_tcp_port, 
# which defaults to 127.0.0.1:2331.
#
# This script can be run on that host machine, or else can connect to it over ssh (via the argument --uart_ssh_login).

# This script builds models locally in its own environment and should therefore be run within the environment where the 
# TASTE toolchain is available (e.g. taste-rtems-qdp-arm). In some cases this may be within a docker container, in which 
# case the container must have network access to the host machine for the UART device (e.g. /dev/ttyUSB0)

import argparse
import subprocess
import json
import shutil
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
SUPPORTED_RECIPES = ["debug", "coverage"]
MODELS_FOLDER = "taste_models"
LOGS_FOLDER = 'logs'

# Defaults
DEFAULT_GDB_BINARY = "gdb-multiarch"
DEFAULT_MAKE_RECIPE = "debug"
DEFAULT_GDB_SERVER_TCP_PORT = "127.0.0.1:2331"
DEFAULT_GDB_VERBOSE = False
DEFAULT_UART_LISTEN_DEVICE = "/dev/ttyUSB0"
DEFAULT_SSH_FOR_UART = None
DEFAULT_SKIP_BUILD = False
DEFAULT_GDB_COMMAND_TIMEOUT = 3

# UART lines that signal something to the script
UART_CMD__RESET_AND_RERUN = "RESET_AND_RERUN"
UART_CMD__END_OF_OUTPUT = "END_OF_OUTPUT"

# Global variable for SSH login for the host that has the SAMRH71 UART device, if needed
uart_ssh_login = DEFAULT_SSH_FOR_UART

# Test results buffer
test_results = {}


def do_build(test_name, arguments):
    """
    Build TASTE project from test_name directory
    This function executes `make` inside test_name directory,
    test_name -- Name of the test and also directory with test project.
    arguments -- A list of arguments for make - usually the targets
    """

    # Prepare directory for logs
    logs_dir = os.path.join(".", LOGS_FOLDER)
    os.makedirs(logs_dir, exist_ok=True)

    # Initialize logs
    test_path = os.path.join(".", MODELS_FOLDER, test_name)
    stdout_file = "{}_stdout.log".format(os.path.basename(os.path.normpath(test_name)))
    stderr_file = "{}_stderr.log".format(os.path.basename(os.path.normpath(test_name)))

    stdout_filepath = os.path.join(logs_dir, stdout_file)
    stderr_filepath = os.path.join(logs_dir, stderr_file)

    # Run compilation
    process = subprocess.run(
        ["make"] + arguments, cwd=test_path, shell=False, capture_output=True
    )

    # Dump compilation logs
    with open(stdout_filepath, "wb") as out:
        out.write(process.stdout)
    with open(stderr_filepath, "wb") as out:
        out.write(process.stderr)

    return process


def do_clean_build(test_name):
    """
    Clean TASTE project from test_name directory
    This function executes `make clean` inside test_name directory,
    test_name -- Name of the test and also directory with test project.
    """
    test_path = os.path.join(".", MODELS_FOLDER, test_name)
    subprocess.run("make clean", cwd=test_path, shell=True, capture_output=True)


# Extracts test names from the README.md file for the model, and initialises the test_results dictionary with FAIL for each test
def initialise_test_results_for_model(model_name):

    readme_path = os.path.join(".", MODELS_FOLDER, model_name, "README.md")
    if not os.path.exists(readme_path):
        cprint(f"Error: README.md not found for model {model_name}", "red", attrs=['bold'])
        sys.exit(1)

    # Use awk + subprocess to search the README for the relevant hits
    command = f"awk '/^## Tests Implemented/ {{ in_section=1; next }} /^## / && in_section {{ exit }} in_section' {readme_path} | grep -oP '\\*\\*\\K[^*]+(?=\\*\\*)'"
    process = subprocess.run(command, capture_output=True, text=True, bufsize=1, shell=True)
    for test_id in process.stdout.splitlines():
        test_results[test_id.strip()] = ["FAIL", "(Test was not run yet)"]


# Parses and adds a test result line to the test results
def add_test_result_line(test_result_line):

    # Try to parse the line
    parts = test_result_line.split(":")
    if len(parts) < 4:
        cprint(f"Error: Invalid test result line: {test_result_line}", "red", attrs=['bold'])
        return

    # Add to the test results dict
    test_id = parts[1].strip()
    passfail = "PASS" if parts[2].strip() == "PASS" else "FAIL"
    failreason = ":".join(parts[3:]).strip()
    test_results[test_id] = [ passfail, failreason ]

    # Render the test result we obtained
    render_test_result(test_id)


# Renders a test result line
def render_test_result(test_id):
    test_passfail, test_failreason = test_results[test_id]
    cprint(f"--> ", color="light_grey", attrs=['dark'], end="")
    cprint(test_id.ljust(20), color="blue", attrs=['bold'], end="")
    if test_passfail == "PASS":
        cprint("PASS", color="green", attrs=['bold'], end="\n")
    else:
        cprint("FAIL", color="red", attrs=['bold'], end="")
        cprint("  " + test_failreason, color="yellow", attrs=[], end="\n")


# Processes line output received over UART
def process_uart_lines(uart_listener):

    # Remove the coverage_tmp folder, it should only contain files from the current run of this script
    shutil.rmtree(GCDA_OUTPUT_PATH, ignore_errors=True)

    # Ensure that the output paths exist
    os.makedirs(GCDA_OUTPUT_PATH, exist_ok=True)
    os.makedirs(os.path.dirname(TEST_RESULTS_OUTPUT_PATH), exist_ok=True)
    gcda_files = []

    # Parse the lines to extract test results and GCDA files
    cprint(f"Processing UART output from ...", "light_grey", attrs=['dark'])
    for line in uart_listener.stdout:
        if line.startswith("TEST_RESULT:"):
            add_test_result_line(line)
        elif line.startswith("GCDA_FILENAME:"):
            filename = line.split(":")[1]
            gcda_files.append(filename.strip())
        elif line.startswith("GCDA_HEX:"):
            hex_data = line.split(":")[1]
            # Write out the hex data as a file on disk in the output folder
            if gcda_files:
                gcda_filename = gcda_files[-1]
                output_path = f"{GCDA_OUTPUT_PATH}/{gcda_filename}"
                with open(output_path, 'wb') as gcda_file:
                    gcda_file.write(bytes.fromhex(hex_data))
                    print(f"Wrote GCDA file: {gcda_filename} ({len(bytes.fromhex(hex_data))} bytes)")
        elif line.strip() == UART_CMD__RESET_AND_RERUN:
            cprint(f"Received command to reset and rerun the model", "yellow", attrs=['bold'])
            return True
        elif line.strip() == UART_CMD__END_OF_OUTPUT:
            cprint(f"Received end-of-output signal. Ignoring any further output.", "light_grey", attrs=[])
            return False
        else:
            cprint(line, color="light_grey", attrs=[], end="")

    # Return False to indicate that we did not receive a reset command
    return False


# Runs a command on the host that holds the UART device.
# command should be a list of parts, e.g. ["ls", "-l", "/dev/ttyUSB0"]
def start_target_host_process(command):

    # Adjust the command to take into account any requuired tunneling to the target host
    command = ["ssh", "-T", uart_ssh_login] + [" ".join(command)] if uart_ssh_login else command

    # Start the process, using Popen() to allow for non-blocking execution
    print(colored(f"Running command (non-blocking): {' '.join(command)}", "yellow"), flush=True)
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)

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

    # Report the command we're about to execute
    if not description:
        description = command
    print(colored(description, "magenta"), end="\n", flush=True)

    # Execute the command and capture responses
    responses = gdbmi.write(command)

    # Specifically look for the completion record
    while True:
        print_gdb_responses(responses, gdb_verbose=gdb_verbose)
        found_result = False
        for r in responses:
            if r["type"] == "result":
                found_result = True
                if gdb_verbose:
                    cprint(f'Command "{command}" completed', "yellow", attrs=['dark'])
                break
        if found_result:
            break

        # Try again to fetch responses, with a timeout to avoid hanging indefinitely
        if gdb_verbose:
            cprint(f'Waiting to get GDB completion response for command "{command}" ...', "yellow", attrs=['dark'])
        responses = gdbmi.get_gdb_response(timeout_sec=timeout)


# Returns True if gdb has stopped, False if it is still running
def gdb_sigtrap_occurred(gdbmi, grace_time_before_check=3, gdb_verbose=DEFAULT_GDB_VERBOSE):

    # Wait for the grace period before checking
    if grace_time_before_check > 0:
        cprint(f"Waiting {grace_time_before_check} seconds before checking if gdb has stopped ...", "yellow", attrs=['dark'])
        time.sleep(grace_time_before_check)

    # Check if gdb has stopped
    try:
        gdbmi.write("info program")
        responses = gdbmi.get_gdb_response(timeout_sec=DEFAULT_GDB_COMMAND_TIMEOUT)
        print_gdb_responses(responses, gdb_verbose=gdb_verbose)
        for r in responses:
            if "received signal SIGTRAP" in r["payload"]:
                cprint(f"gdb has halted on SIGTRAP", "red", attrs=['dark'])
                return True
    except Exception as e:
        cprint(f"Error while checking if gdb has stopped: {e}", "yellow", attrs=[])
        return False

    # If we get here, we didn't find a result record, so assume gdb is still running
    cprint(f"gdb is still running (no result record found)", "yellow", attrs=['dark'])
    return False


# Performs an "extended reset" on the target hardware, which is a more complete reset than a simple "monitor reset"
# Following a crash (e.g. UsageFault) of the SAMRH71 target, the target may not be able to recover from a simple "monitor reset" command, 
# and may require an extended reset to recover. This is at least the case for model-death-report.
def gdb_extended_reset(gdbmi, timeout=DEFAULT_GDB_COMMAND_TIMEOUT, gdb_verbose=DEFAULT_GDB_VERBOSE):

    gdb_command(gdbmi, "monitor reset", description="Performing ordinary reset", gdb_verbose=gdb_verbose, timeout=timeout)
    gdb_command(gdbmi, "monitor reset 0", description="Performing core & peripherals reset via SYSRESETREQ & VECTRESET bit", gdb_verbose=gdb_verbose, timeout=timeout)
    gdb_command(gdbmi, "monitor reset 1", description="Performing core only reset, not peripherals", gdb_verbose=gdb_verbose, timeout=timeout)
    gdb_command(gdbmi, "monitor reset 8", description="Performing core & peripherals reset via SYSRESETREQ bit only", gdb_verbose=gdb_verbose, timeout=timeout)
    gdb_command(gdbmi, "monitor reset", description="Performing ordinary reset", gdb_verbose=gdb_verbose, timeout=timeout)


# Build the model using the specified recipe
def build(model_name, build_recipe=DEFAULT_MAKE_RECIPE):

    # Perform a make-clean on the model build folders
    print("make clean ... ", end="", flush=True)
    do_clean_build(model_name)
    print("done", flush=True)

    # Perform a make on the intended target recipe, and ensure success
    print(f"make {TARGET_HARDWARE} {build_recipe} ... ", end="", flush=True)
    build = do_build(model_name, [TARGET_HARDWARE, build_recipe])
    stderr = build.stderr.decode("utf-8")
    assert build.returncode == 0, f"Compilation errors: \n{stderr}"
    print("done", flush=True)

    # Report end of building process
    cprint("\nBuild finished\n", "green", attrs=['bold'])


# Deploy the model to the target hardware using gdb
def deploy(
        model_name,
        gdb_binary_path=DEFAULT_GDB_BINARY,
        gdb_server_tcp_port=DEFAULT_GDB_SERVER_TCP_PORT,
        uart_listen_device=DEFAULT_UART_LISTEN_DEVICE,
        gdb_verbose=DEFAULT_GDB_VERBOSE,
        extended_reset=False
) -> bool:

    # Fail if model_name is not set
    if model_name is None:
        print("Error: model_name is not set")
        sys.exit(1)

    # Determine the path to the model binary
    model_binary_path = os.path.join(".", MODELS_FOLDER, model_name, BINARY_SUB_PATH)

    # Assume we do not have to re-run the model, unless we receive a command from the UART listener to do so
    rerun_the_model = False

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

        # Tell gdb not to ask for any confirmations
        gdb_command(gdbmi, "set confirm off", gdb_verbose=gdb_verbose)

        # Reset the target
        if extended_reset:
            gdb_command(gdbmi, "monitor reset", gdb_verbose=gdb_verbose)
            time.sleep(10)  # Wait a few seconds for the target to reset, then send further reset commands
        gdb_extended_reset(gdbmi, gdb_verbose=gdb_verbose)

        # Connect to the UART listen device, before the model starts running
        enable_remote_parsing = True
        remote_line_parser_cmds = ["sed", "'/END_OF_OUTPUT/q'"] if enable_remote_parsing else ["cat"]
        uart_listener = start_target_host_process(["stty", "-F", uart_listen_device] + UART_TTY_CONFIG + ["&&"] + remote_line_parser_cmds + [uart_listen_device])
        if not uart_listener:
            raise RuntimeError(f"Failed to start UART listener on {uart_listen_device}")

        # Load the model onto the target
        gdb_command(gdbmi, "load", "Loading the model", gdb_verbose=gdb_verbose)

        # Run the model
        gdb_command(gdbmi, "c", "Running the model", gdb_verbose=gdb_verbose)

        # Process the stdout we receive from the listener
        rerun_the_model = process_uart_lines(uart_listener)

        # Ensure that the UART listener process is terminated and cleaned up
        uart_listener.terminate()
        uart_listener.wait()

        # Report end of deployment process
        cprint("\nDeployment finished\n", "green", attrs=['bold'])

    # Report any errors that occur during the gdb session
    except Exception as e:
        cprint(f"\nError during deployment: {e}\n", "red", attrs=['bold'])

    # Ensure we always exit gdb cleanly, even if an error occurs
    finally:
        gdbmi.exit()

        # Kill the process that's potentially currently still listening to the UART device, so that we can cleanly exit
        run_target_host_command(["kill", "-9", "$(fuser " + uart_listen_device + " 2>/dev/null)"])


    # Return whether we need to rerun the model, based on whether we received a command from the UART listener to do so
    return rerun_the_model



# MAIN entry point for the script, which parses command line arguments and runs the build/deploy process
if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Build and deploy a TASTE model to the target hardware.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    parser.add_argument("--model", default=None, help="Name of the model to build and deploy")
    parser.add_argument("--build_recipe", default=DEFAULT_MAKE_RECIPE, help="Make recipe to use for the build")
    parser.add_argument("--gdb_binary_path", default=os.getenv("GDB_BINARY_PATH", default=DEFAULT_GDB_BINARY), help="Path to the GDB binary")
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
        cprint("Error: model_name is not set", "red", attrs=['bold'])
        sys.exit(1)

    # Assert that the model folder exists
    if args.model != "all":
        model_folder = os.path.join(".", MODELS_FOLDER, args.model)
        if not os.path.exists(model_folder):
            cprint(f"Error: model {model_folder} not found\n", "red", attrs=['bold'])
            cprint(f"Available models: {', '.join([d for d in os.listdir(MODELS_FOLDER) if os.path.isdir(os.path.join(MODELS_FOLDER, d)) and d.startswith('model-') and d != 'model-template'])}", "yellow", attrs=['bold'])
            sys.exit(1)

    # Assert that the recipe is either "debug" or "coverage"
    if args.build_recipe not in SUPPORTED_RECIPES:
        cprint(f"Error: Unsupported build recipe {args.build_recipe}", "red", attrs=['bold'])
        sys.exit(1)

    # Assert that we have a valid UART listen device
    device_match_lines = run_target_host_command(["ls", args.uart_listen_device])
    if args.uart_listen_device not in device_match_lines:
        cprint(f"Error: UART listen device {args.uart_listen_device} not found", "red", attrs=['bold'])
        sys.exit(1)

    # Ensure that nothing is running on the UART listen device before we start the model, by running the linux lsof command
    lsof_output = run_target_host_command(["lsof", args.uart_listen_device])
    if lsof_output:
        lines = lsof_output.splitlines()
        lines = [line for line in lines if not line.startswith("COMMAND")]
        if lines:
            cprint(f"Error: UART listen device {args.uart_listen_device} is already in use", "red", attrs=['bold'])
            cprint("\n".join(lines), "red", attrs=['bold'])
            sys.exit(1)

    # One model or all?
    if args.model == "all":
        # Get a list of all folders in the current directory with a name matching "model-*"
        models = [d for d in os.listdir(MODELS_FOLDER) if os.path.isdir(os.path.join(MODELS_FOLDER, d)) and d.startswith("model-") and d != "model-template"]
        cprint(f"\nIterating over {len(models)} models:\n", "green", attrs=['bold'])
        cprint(f" - {'\n - '.join(models)}\n", "yellow", attrs=['bold'])
    else:
        models = [args.model]

    # Remove everything from the test_output folder, to ensure that we only have files from the current run of this script
    shutil.rmtree("test_output", ignore_errors=True)

    # Iterate over each model and build/deploy it
    for model in models:
        cprint(f"---------------------------------------------------", "green", attrs=['bold'])
        cprint(f"Building and deploying model: {model}\n", "green", attrs=['bold'])

        # Initialise the test results for this model, based on the README.md file
        initialise_test_results_for_model(model)

        # Perform the build
        if not args.skip_build:
            build(model, build_recipe=args.build_recipe)

        # Before deploying, ensure that the target model binary exists on disk
        model_binary_path = os.path.join(".", MODELS_FOLDER, model, BINARY_SUB_PATH)
        if not os.path.exists(model_binary_path):
            cprint(f"Error: model binary {model_binary_path} does not exist, cannot deploy", "red", attrs=['bold'])
            sys.exit(1)

        # Perform the deployment
        rerun_the_model = deploy(model,
            gdb_binary_path=args.gdb_binary_path,
            gdb_server_tcp_port=args.gdb_server_tcp_port,
            uart_listen_device=args.uart_listen_device,
            gdb_verbose=args.gdb_verbose
        )

        # If we received a command to rerun the model, do so
        if rerun_the_model:
            cprint(f"Rerunning model: {model} (due to reset signal from last run) ... \n", "cyan", attrs=['bold'])
            rerun_the_model = deploy(model,
                gdb_binary_path=args.gdb_binary_path,
                gdb_server_tcp_port=args.gdb_server_tcp_port,
                uart_listen_device=args.uart_listen_device,
                gdb_verbose=args.gdb_verbose,
                extended_reset=True,
            )

        # After deployment we may need to generate a partial coverage report, if any gcda files were generated
        # TODO

    # If we ran multiple models, report what we did
    if len(models) > 1:
        cprint(f"\n\n---------------------------------------------------", "cyan", attrs=['bold'])
        cprint(f"Finished building and deploying {len(models)} models:\n", "cyan", attrs=['bold'])
        cprint(f" - {'\n - '.join(models)}\n", "cyan", attrs=[])

        # Also print the test results that were captured during this run
        if test_results:
            cprint(f"Test results:\n", "cyan", attrs=['bold'])
            for test_id in sorted(test_results.keys()):
                render_test_result(test_id)
            print()


