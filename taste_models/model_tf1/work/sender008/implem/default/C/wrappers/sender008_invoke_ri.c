// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error sender008_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned sender008_initialized;

void sender008_RI_PI_8_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1
);
void sender008_RI_PI_8(
      const asn1SccT_Int32 *IN_p1
);
void sender008_RI_PI_8(
      const asn1SccT_Int32 *IN_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   sender008_RI_PI_8_To_PID(PID_env, IN_p1
);
}

void sender008_RI_PI_8_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1
)
{


   // Send the message via the middleware API
   extern void vm_sender008_pi_8
     (asn1SccPID,
      void *, size_t);

   vm_sender008_pi_8
     (dest_pid,
      (void *)IN_p1, sizeof(asn1SccT_Int32));


  sender008_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void sender008_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void sender008_get_sender(asn1SccPID *sender_pid);
  sender008_get_sender(sender_pid);
}

void sender008_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = sender008_recent_error;
}

void sender008_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    sender008_RI_get_last_error(err);
}

