# Misc Model

## Tests Implemented
- **TestStackSize**: Validates stack sizes for Sporadic and Cyclic interfaces at runtime match those configured in the Interface View
- **TestStackUsage**: Validates that the TASTE runtime can report reasonable maximum stack usage for interfaces 
- **TestPriority**: Validates priority values for Sporadic and Cyclic interfaces at runtime match those configured in the Interface View

## Requirements covered
- `MBEP-RT-FUN-100` : TASTE Runtime shall support setting the stack size of sporadic interfaces.
- `MBEP-RT-FUN-101` : TASTE Runtime shall support setting the priority of sporadic interfaces.
- `MBEP-RT-FUN-110` : TASTE Runtime shall support setting the stack size of cyclic interfaces.
- `MBEP-RT-FUN-111` : TASTE Runtime shall support setting the priority of cyclic interfaces.
- `MBEP-RT-FUN-620` : TASTE Runtime shall provide a status parameter, per each user thread (Function task), indicating maximum measured runtime stack usage.

## Implemented By
KISPE Space Systems Ltd., 2026
