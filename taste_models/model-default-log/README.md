# TASTE runtime test framework - Template Model

This is a template model that demonstrates how to integrate the TASTE runtime test framework into a model. The template is intended for use with a SAMRH71 as target, and assumes that `FLEXCOM1` is connected to a host USB port which can recive the test results and coverage data

This model uses the `tf_common` library to send log output, register tests, and submit test results. The underlying test-results lib will only transmit coverage data over the UART once all registered tests have submitted a test result. If any test takes longer than the configured timeout it is automatically failed. The timeout can be set via a function call but otherwise defaults to 10 seconds.

## Running the template model


This model has been validated to work on the SAMRH71, sending data over the UART. 

Building does not make use of the `coverage` build target but rather the `debug` target. Build with:
```
    make samrh71 debug
```
*The above assumes that the target model's Deployment View XML file is named `samrh71.ui.xml`*


Sample output is asbelow:
```
    INFO:Test registered: 'TestComms01' (2)
    INFO:Example test startup completed its work
    TEST_RESULT:TestComms01:PASS:
    COVERAGE_DATA_START
    GCDA_FILENAME:main.gcda
    GCDA_HEX:6164636720333242b54c5ad796b3955f000000010c000000ee818958e2eed156b88330a40000a101f8 ...
    GCDA_FILENAME:Broker.gcda
    GCDA_HEX:616463672033324212555ad70339cab4000000010c0000004810c24a8069b0c4b88330a40000a101f8 ...
    GCDA_FILENAME:BrokerLock.gcda
    GCDA_HEX:61646367203332421f535ad797c0ba96000000010c000000b0e6ce75f64fc7643eb2bbc00000a10110 ...
    ...
```

## Adding the test reporting to another model

Throughout these steps the term "target model" shall be used to refer to the mode that is being updated to use the test framework. The phrase "this model" refers to `model-default-log`.

### Setup steps

1. Copy the two TASTE Functions at the top of the Interface Layout (`UartOtherEnd` and `TF Reporter`) into the target model. These can be copy-and-pasted between two TASTE GUIs. Their interface nodes should be connected with a line. 
2. Update the Deployment View of the target mode as follows:
    - Place two instances of `SAM RH71 RTEMS N7S` side by side (`Partition_1` on the left, `Partition_2` on the right).
    - Connect the `uart1` node on each instance with a line
    - Bind `Partition_2` to the TASTE Function `UartOtherEnd` *only*
    - Bind `Partition_1` to all other TASTE Functions in the model
    - In the `Partition_1` **Properties** dialog in the **Attributes** tab set **Extra libs** to `../../../../tf_common/`
    - In the **Properties** dialog for the line connecting the two `uart1` nodes, in the **Message Bindings** tab tick the `TF_Reporter.samrh71tx -> UartOtherEnd.samrh71.tx` entry
    - In the **Properties** dailog for each samrh71's `uart1` node set **Config** to: `{ devname  uart1, speed  b115200, parity  even, transmit-mode  raw-single-byte }`
    - In the **Properties** dailog for each samrh71's `uart1` node set **Packetizer** to `passthrough`
3. Open the file `Makefile` in the target model and add the stanza from the **Makefile export definitions** section below.
4. Copy the following folders from the `work` folder of this mode into the target model's `work` folder:
    - `tf_reporter`
    - `uartotherend`

*Notes*: 
* `Partition_2` is not intended to ever be deployed. It is included only to enable the definition of the `TF Reporter` side of the UART link.
* The TASTE Function `Example Test Function` is not intended to be included in the target model. It is is included here as a working example of:
    - *Registering a test with the test-results lib*
    - *Sending a test result*
    - *Setting an explicit test timeout*
    - *Sending arbitrary log lines*
* This model and the instructions above define a custom linker script for the target model. If the target model needs or already has its own custom linker script it can instead have one locally in the model but that linker script **must** include the `.gcov_info` section in the model's custom liner script. An example is below - see section **Sample .gcov_info linker script section**


### Makefile export definitions
```
    # Enable coverage in this model
    export PARTITION_1_USER_CFLAGS=--coverage -fprofile-info-section
    export PARTITION_1_USER_LDFLAGS=--coverage 
    $(info [TFINFO] Coverage enabled for compilation and linking)

    # Use the Test Framework's custom linker script. It simply adds a definition for the (tiny) .gcov_info section
    SHARED_LINKER_SCRIPT_DIR := $(abspath ../tf_linker_gcov_samrh71)
    $(info [TFINFO] Shared gcov linker script folder: $(SHARED_LINKER_SCRIPT_DIR))
    export PARTITION_1_USER_LDSCRIPT_DIR=$(SHARED_LINKER_SCRIPT_DIR)
    export PARTITION_1_USER_LDSCRIPT=$(SHARED_LINKER_SCRIPT_DIR)/linkcmds.intsram
```

### Sample .gcov_info linker script section
```
    .gcov_info : ALIGN_WITH_INPUT {
	        PROVIDE (__gcov_info_start = .);
		KEEP (*(.gcov_info))
		PROVIDE (__gcov_info_end = .);
	} > REGION_WORK AT > REGION_WORK
```

