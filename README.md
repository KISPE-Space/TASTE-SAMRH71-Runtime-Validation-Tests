# TASTE runtime tests for the SAMRH71

This repository contains tests for validating that all software requirements are met by the TASTE runtime running on a SAMRH71 target. 

Tests are implemented in TASTE models, most of which communicate over a UART serial connection (FLEXCOM1 on the SAMRH71) to the host computer running the tests. 

This software has been developed as part of the "Model Based Execution Platform for Space Applications" project (contract ESA Contract No. 4000146882/24/NL/KK) financed by the European Space Agency.

## Dependencies

* The tests are intended for use on a Linux environment.
* The TASTE toolchain must be available on the environment that is hosting the tests
* The tests require a GDB server connected to the target
* The tests require a local serial port (such as a USB device) which is connected to the target's FLEXCOM1 uart rx/tx pins

## Setup

1.	A SAMRH71’s JLink connector should be connected via some debugger to a host computer with GDB Server installed.
2.	The GDB server should be started, and connected to the logical host port on which the debugger device is found
3.	The FLEXCOM1 RX & TX pins of the SAMRH71 should be connected via some serial interface (such as an FTDI) to the host computer, such that it is available via some USB device on the host.
4.	The TASTE toolchain must be installed on the host (or virtual machine / docker container) on which the model runner will run, since it must build each model before deploying.
5.	The Python model dependencies of the model runner script should be installed on the SAMRH71 host computer. The dependencies are defined in the requirements.txt file in the root of the test repository.


## Running the tests

If the UART is connected tothe host computer on port ```/dev/ttyUSB0``` then simply run:
```
python3 model-runner.py --model=all --uart_listen_device=/dev/ttyUSB0
```

If the GDB server is being hosted remotely, or the UART device is to be found on some other (network-reachable) host, the model-runner will need to know how to reach each of those. (Refer to the model runner’s help documentation by running it with the -h argument: ```python3 model-runner.py -h```)

The model runner will then build the "debug" Make target for each model using TASTE, instantiate a GDB session with the server to load the resulting elf file to the target, then listen for output on the named UART listener device. The output sent by from target over UART will be parsed and the results rendered at the end of the script. 

Additionally a combined coverage report can be obtained by providing the ```--build_recipe=coverage``` argument.
