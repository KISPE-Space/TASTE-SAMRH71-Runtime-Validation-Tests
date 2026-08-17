# Parameters Model

## Tests Implemented
- **TestQueues**: Validates that configured queue sizes are respected by TASTE Sporadic interfaces.
- **TestQueueOverflow**: Validates that the TASTE runtime reports queue overflow events.

## Requirements covered
- `MBEP-RT-FUN-90` : TASTE Runtime shall support setting of the queue sizes for the sporadic interfaces.
- `MBEP-RT-FUN-350` : TASTE Runtime shall report message queue overflow.
- `MBEP-RT-FUN-660` : TASTE Runtime shall provide a status parameter, per each provided sporadic interface, indicating the number of queued items in the queue.

## Implemented By
KISPE Space Systems Ltd., 2026
