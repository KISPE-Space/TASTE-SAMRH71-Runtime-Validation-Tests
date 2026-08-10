# experimental-parameters

## Model History
- Copied the N7 model samrh71-rtems-parameter-encoding to new model
- Validated it ran fine on KISPE's Parrot samrh71
- Added the KISPE test frewmork UART components
- Added a simple single log line from the triggerfunction
- Built and deployed fine, but no output over UART: Soon crashed and reset the cpu, reporting in gdb "corrupt stack?"
