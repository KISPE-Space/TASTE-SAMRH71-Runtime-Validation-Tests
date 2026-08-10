// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error triggerfunction_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned triggerfunction_initialized;

void triggerfunction_RI_PI_1_To_PID(asn1SccPID dest_pid, 
      const asn1SccMyInteger *IN_p1
);
void triggerfunction_RI_PI_1(
      const asn1SccMyInteger *IN_p1
);
void triggerfunction_RI_PI_1(
      const asn1SccMyInteger *IN_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   triggerfunction_RI_PI_1_To_PID(PID_env, IN_p1
);
}

void triggerfunction_RI_PI_1_To_PID(asn1SccPID dest_pid, 
      const asn1SccMyInteger *IN_p1
)
{


   // Send the message via the middleware API
   extern void vm_triggerfunction_pi_1
     (asn1SccPID,
      void *, size_t);

   vm_triggerfunction_pi_1
     (dest_pid,
      (void *)IN_p1, sizeof(asn1SccMyInteger));


  triggerfunction_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void triggerfunction_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void triggerfunction_get_sender(asn1SccPID *sender_pid);
  triggerfunction_get_sender(sender_pid);
}

void triggerfunction_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = triggerfunction_recent_error;
}

void triggerfunction_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    triggerfunction_RI_get_last_error(err);
}

