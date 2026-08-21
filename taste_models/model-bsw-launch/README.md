# Misc Model

## Tests Implemented
- **TestTime**: Validates that elpased time can be obtained from the TASTE runtime and that time values are reasonable
- **TestCpuFreqDefault**: Validates that with no compiler clock frequency flags the processor runs at 100 MHz
- **TestFpu**: Vallidates that the FLoating POint Unit (FPU) is configured as enabled

## Requirements covered
- `MBEP-RT-FUN-370` : TASTE Runtime shall provide the capability to query elapsed time.
- `MBEP-RT-PER-10` : By default TASTE Runtime shall configure the CPU core to operate at 100 MHz.
- `MBEP-RT-RES-110` : TASTE Runtime shall enable FPU.

## Implemented By
KISPE Space Systems Ltd., 2026
