# Misc Model

## Tests Implemented
- **TestTime**: Validates that elpased time can be obtained from the TASTE runtime and that time values are reasonable
- **TestCpuFreqDefault**: Validates that with no compiler clock frequency flags the processor runs at 100 MHz
- **TestFpu**: Validates that the Floating Point Unit (FPU) is configured as enabled
- **TestBootReason**: Validates that a sane boot reason can be obtained from the TASTE runtime

## Requirements covered
- `MBEP-RT-FUN-370` : TASTE Runtime shall provide the capability to query elapsed time.
- `MBEP-RT-PER-10` : By default TASTE Runtime shall configure the CPU core to operate at 100 MHz.
- `MBEP-RT-RES-110` : TASTE Runtime shall enable FPU.
- `MBEP-RT-RES-310` : TASTE Runtime shall provide the capability to query boot reason.

## Implemented By
KISPE Space Systems Ltd., 2026
