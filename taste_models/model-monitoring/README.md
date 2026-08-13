# Max-tasks Model

## Tests Implemented
- **TestMonitoring**: Fetches execution times for two sporadic interfaces and one cyclic interface and validates that they contain sensible and distinct data

## Requirements covered
- `MBEP-RT-FUN-610` : TASTE Runtime shall provide a status parameter indicating its CPU usage.
- `MBEP-RT-FUN-630` : TASTE Runtime shall provide a status parameter, per each provided sporadic and cyclic interface, indicating maximum execution time.
- `MBEP-RT-FUN-640` : TASTE Runtime shall provide a status parameter, per each provided sporadic and cyclic interface, indicating minimum execution time.
- `MBEP-RT-FUN-650` : TASTE Runtime shall provide a status parameter, per each provided sporadic and cyclic interface, indicating average execution time.

## Notes
1. The two sporadic and one cyclic interface handlers implement "expensive" operations, to create a dummy load. However these take up realtime, which then blocks subsequent IF calls. The update of the min/avg/max execution times by the runtime only happens on completion of each (possibly queued) IF call. Since it is desired to have more than just one sample collected for each IF before we run the testfunction and determine PASS/FAIL, the "expesnive" workloads are sized sich that multiple IF invocations can happen within each second.
2. It was noted during this development that setting the "Priority" of an interface to a value other than 1 resulted in that IF never being called. This was while the "expensive" workloads were ten times higher than what they are now, and likely was caused by starvation of lower-level priority task threads.

## Implemented By
KISPE Space Systems Ltd., 2026

