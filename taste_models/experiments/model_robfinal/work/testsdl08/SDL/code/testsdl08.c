//// Includes
#include "dataview-uniq.h"
#include "testsdl08_datamodel.h"
#include "testsdl08.h"
//// SDL Constants
[[maybe_unused]]
static const asn1SccPID self = asn1SccPID_testsdl08;

//// Aliases

//// Context
static asn1SccTestsdl08_Context ctxt = {0};
//// State Aggregations Start functions
//// Declaration Of Inner Procedures

//// Startup
void CInittestsdl08()
{
   ctxt.sender = asn1SccPID_env;
   ctxt.offspring = asn1SccPID_env;

   runTransitionTestsdl08(startup_transition);
   ctxt.init_done = true;
}

// Required To Work With TASTE's Wrappers
void testsdl08_startup()
{
   CInittestsdl08();
}

//// Input Signals
void testsdl08_PI_PI_STARTSDL08(asn1SccCounter * p1)
{
   runTransitionTestsdl08(continuous_signals);
}

void testsdl08_PI_mytime()
{
   runTransitionTestsdl08(continuous_signals);
}

//// Output Signals
#define SET_mytime testsdl08_RI_SET_mytime
#define RESET_mytime testsdl08_RI_RESET_mytime
//// Definition Of Inner Procedures

// CONNECTION rerun (16,8)
static enum Testsdl08_Branches branch_rerun(void)
{
   // set_timer(1000, mytime) (18,13)
   {
      asn1SccT_UInt32 tmp8;
      tmp8 = 1000;
      SET_mytime(&tmp8);
   }
   // counter := counter + 1 (20,13)
   ctxt.counter = (asn1SccCounter) (ctxt.counter + 1);  // default assignment
   // DECISION counter > 10 (22,25)
   // ANSWER false (24,13)
   if((((ctxt.counter > 10)) == false))
   {
      // JOIN rerun (26,21) at 571, 499
      return rerun;
      // ANSWER true (28,13)
   } else if((((ctxt.counter > 10)) == true))
   {
      // NEXT_STATE Wait (30,26) at 644, 499
      ctxt.state = asn1SccTestsdl08_States_wait;
      return continuous_signals;
   } //last
}

// CONNECTION Startup_Transition
static enum Testsdl08_Branches branch_startup_transition(void)
{
   // counter := 0 (14,13)
   ctxt.counter = (asn1SccCounter) 0;  // default assignment
   // JOIN rerun
   return rerun;
}

//// Definition Of Run Transition
void runTransitionTestsdl08(enum Testsdl08_Branches Id)
{
   enum Testsdl08_Branches trId = Id;
   while (trId != branch_end)
   {
      switch (trId)
      {
         case rerun: trId = branch_rerun(); break;
         case startup_transition: trId = branch_startup_transition(); break;
         case continuous_signals: trId = branch_end; break;
         default: trId = branch_end; break;
      }
   }
}

//// Current State To String
char* testsdl08_state(void)
{
   return "Not_supported_in_C__Use_the_Ada_backend";
}
