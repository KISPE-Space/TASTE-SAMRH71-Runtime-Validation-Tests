# Max-tasks Model

## Tests Implemented
- **TestMaxTasks**: Implements 44 Sporadic IFs and 4 Cyclic IFs in a single model, validating they all get invoked. Note one Sporadic is on the UART transmitter function.

## Requirements covered
- `MBEP-RT-FUN-20` : TASTE Runtime shall support TASTE Functions with sporadic provided interfaces.
- `MBEP-RT-FUN-30` : TASTE Runtime shall support TASTE Functions with cyclic provided interfaces.
- `MBEP-RT-FUN-40` : TASTE Runtime shall support TASTE Functions with protected provided interfaces.
- `MBEP-RT-FUN-50` : TASTE Runtime shall support TASTE Functions with unprotected provided interfaces.
- `MBEP-RT-FUN-60` : TASTE Runtime shall support TASTE Functions with sporadic required interfaces.
- `MBEP-RT-FUN-70` : TASTE Runtime shall support TASTE Functions with protected required interfaces.
- `MBEP-RT-FUN-80` : TASTE Runtime shall support TASTE Functions with unprotected required interfaces.
- `MBEP-RT-FUN-120`	: TASTE Runtime shall support sporadic interfaces with no parameters.
- `MBEP-RT-FUN-130`	: TASTE Runtime shall support sporadic interfaces with a single input parameter.
- `MBEP-RT-FUN-140`	: TASTE Runtime shall support protected interfaces with no parameters.
- `MBEP-RT-FUN-170`	: TASTE Runtime shall support unprotected interfaces with no parameters.
- `MBEP-RT-FUN-410`	: TASTE Runtime shall support TASTE Functions implemented in C.
- `MBEP-RT-RES-220`	: TASTE Runtime shall support at minimum the combined total of 48 TASTE Function sporadic and cyclic interfaces.
- `MBEP-RT-OPER-10`	: It shall be possible to execute an application built using the TASTE Runtime on the hardware target without the use of an additional BSW.

## Implemented By
KISPE Space Systems Ltd., 2026
