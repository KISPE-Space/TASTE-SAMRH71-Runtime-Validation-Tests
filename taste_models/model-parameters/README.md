# Parameters Model

## Tests Implemented
- **TestEncoding**: Validates NATIVE and ACN encoding of interface parameters.
- **TestParameterCount**: Validates interfaces can support an arbitrary number of IN or OUT parameters
- **TestEncodingErrors**: Validates that encoding errors are reported by the TASTE runtime
- **TestDecodingErrors**: Validates that decoding errors are reported by the TASTE runtime

## Requirements covered
- `MBEP-RT-FUN-150` : TASTE Runtime shall support protected interfaces with an arbitrary number of input parameters.
- `MBEP-RT-FUN-160` : TASTE Runtime shall support protected interfaces with an arbitrary number of output parameters.
- `MBEP-RT-FUN-180` : TASTE Runtime shall support unprotected interfaces with an arbitrary number of input parameters.
- `MBEP-RT-FUN-190` : TASTE Runtime shall support unprotected interfaces with an arbitrary number of output parameters.
- `MBEP-RT-FUN-240` : TASTE Runtime shall support native encoding of parameters.
- `MBEP-RT-FUN-250` : TASTE Runtime shall support ACN encoding of parameters.
- `MBEP-RT-FUN-340` : TASTE Runtime shall report errors encountered during data transcoding.

## Implemented By
KISPE Space Systems Ltd., 2026
