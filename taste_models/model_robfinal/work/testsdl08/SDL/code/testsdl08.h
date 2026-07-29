#ifndef TESTSDL08_PROCESS_INCLUDE_GUARD_H
#define TESTSDL08_PROCESS_INCLUDE_GUARD_H

#include "dataview-uniq.h"
#include "testsdl08_datamodel.h"
enum Testsdl08_Branches {
   rerun, startup_transition, continuous_signals, branch_end
};

void runTransitionTestsdl08(enum Testsdl08_Branches Id);
//// Startup
void testsdl08_startup();

//// Declaration Of Exported Inner Procedures

//// Input Signals
// Provided interface "PI_STARTSDL08"
void testsdl08_PI_PI_STARTSDL08(asn1SccCounter * p1);
// Provided interface "mytime"
void testsdl08_PI_mytime();
//// Output Signals
//// Continuous Signals

//// External Procedures
// Sync Required Interface "get_sender
void testsdl08_RI_get_sender(asn1SccPID * sender);
// Sync Required Interface "get_last_error
void testsdl08_RI_get_last_error(asn1SccT_Runtime_Error * err);
//// Timers
// Timer mytime SET and RESET functions
void testsdl08_RI_SET_mytime(const asn1SccT_UInt32 * val);
void testsdl08_RI_RESET_mytime();

#endif /* TESTSDL08_PROCESS_INCLUDE_GUARD_H */