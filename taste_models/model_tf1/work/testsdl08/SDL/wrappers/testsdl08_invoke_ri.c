// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error testsdl08_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned testsdl08_initialized;

void testsdl08_RI_RESET_mytime_To_PID(asn1SccPID dest_pid);
void testsdl08_RI_RESET_mytime(void);
void testsdl08_RI_RESET_mytime(void)
{
   // When no destination is specified, send to everyone (multicast)
   testsdl08_RI_RESET_mytime_To_PID(PID_env);
}

void testsdl08_RI_RESET_mytime_To_PID(asn1SccPID dest_pid)
{


   // Send the message via the middleware API
   extern void vm_testsdl08_reset_mytime(asn1SccPID);
   vm_testsdl08_reset_mytime(dest_pid);

  testsdl08_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testsdl08_RI_SET_mytime_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt32 *IN_val
);
void testsdl08_RI_SET_mytime(
      const asn1SccT_UInt32 *IN_val
);
void testsdl08_RI_SET_mytime(
      const asn1SccT_UInt32 *IN_val
)
{
   // When no destination is specified, send to everyone (multicast)
   testsdl08_RI_SET_mytime_To_PID(PID_env, IN_val
);
}

void testsdl08_RI_SET_mytime_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt32 *IN_val
)
{


   // Send the message via the middleware API
   extern void vm_testsdl08_set_mytime
     (asn1SccPID,
      void *, size_t);

   vm_testsdl08_set_mytime
     (dest_pid,
      (void *)IN_val, sizeof(asn1SccT_UInt32));


  testsdl08_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void testsdl08_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void testsdl08_get_sender(asn1SccPID *sender_pid);
  testsdl08_get_sender(sender_pid);
}

void testsdl08_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = testsdl08_recent_error;
}

void testsdl08_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    testsdl08_RI_get_last_error(err);
}

