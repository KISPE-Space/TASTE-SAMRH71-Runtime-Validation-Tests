# model-max-tasks - First Attempt

## Model History
- Started out as a clone of model_tf1 (the large model, before model_robfinal was cloned), named **model_max_tasks**
- All elements except those required for the max-SPoradic-CycliC interfaces test ("TestSPCC") were removed
- This model was committed to git on July 29th
- The model was used for testing out the standalone TF Reporter in its infancy
- On August 6th 2026 the model was renamed **model-max-tasks** to fit the updated naming convention
- On the same day the model was updated to follow the pattern of **model-template**
- Work then began on bringing the model to implement all scoped requirements, but it was quickly founds that the model would crash with stack corruption
- In the layouts nascent form it still uses the "embedded Functions" approach; The layout is OK but as a standsalone model its somewhat more cumbersome than it needs to be. Its not in a good state for sharing with N7 for their support.
- This work ended with various debugging efforts, before the model was moved into the **sandbox** folder, with the intent being to create a new *model-max-tasks* by cloning **model-template**

## Efforts to Resolve the Crashing
- Efforts were made to simplify the model, removing all references to the tf_common lib, the shared linker script (and thus all gcov), and all non-trivial C code, but the issue was not resolved
- An inital early crash seemed to be consistently solved by one small improvement to the tf_common lib.
- A further speculative change was made, placing all the tf_common lib variables into a dedicated region of memory (`.tfdata`). Again no resolution.
- It was later observed however that the crashing was not determinate as previously understood: Rather the point at which any given model crashes seems to vary from one run to the next: Often only 14 seconds, but other times 20, 28 seconds, or over four minutes.

## Crash Description
- The model is deployed via gdb, with monitor `reset->load->c`
- No output was ever seen on the UART, despite stepping over the UART-writing function
- After some seconds (variable) the GDB Server window would then be filled with "DEADBEEF" style register contents, and typically a few seconds later the UART tailing window would start to show the ROM-installed app spooling out its output again, indicating that a processor reset had occurred.
- On some occassions the GDB Server session would seem to remain in tact - no output to indicate otherwise - yet the UART-tailing window shows the truth: The processor was reset. Pausing GDB then allows the server to catch up with reality

## Last model update
6th August 2026, Andy Cowling
