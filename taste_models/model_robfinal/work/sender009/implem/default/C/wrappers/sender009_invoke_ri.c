// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error sender009_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned sender009_initialized;

void sender009_RI_PI_9_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1,
       asn1SccT_Boolean     *OUT_p2
);
void sender009_RI_PI_9(
      const asn1SccT_Int32 *IN_p1,
       asn1SccT_Boolean     *OUT_p2
);
void sender009_RI_PI_9(
      const asn1SccT_Int32 *IN_p1,
       asn1SccT_Boolean     *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   sender009_RI_PI_9_To_PID(PID_env, IN_p1, OUT_p2
);
}

void sender009_RI_PI_9_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1,
       asn1SccT_Boolean     *OUT_p2
)
{

   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_sender009_pi_9
     (asn1SccPID,
      void *, size_t,
      void *, size_t *);

   vm_sender009_pi_9
     (dest_pid,
      (void *)IN_p1, sizeof(asn1SccT_Int32),
      (void *)OUT_p2, &size_OUT_buf_p2);


  sender009_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void sender009_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void sender009_get_sender(asn1SccPID *sender_pid);
  sender009_get_sender(sender_pid);
}

void sender009_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = sender009_recent_error;
}

void sender009_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    sender009_RI_get_last_error(err);
}

