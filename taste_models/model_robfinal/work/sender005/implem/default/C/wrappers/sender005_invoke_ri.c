// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error sender005_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned sender005_initialized;

void sender005_RI_PI_5_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1,
       asn1SccT_Boolean     *OUT_p2
);
void sender005_RI_PI_5(
      const asn1SccT_Int32 *IN_p1,
       asn1SccT_Boolean     *OUT_p2
);
void sender005_RI_PI_5(
      const asn1SccT_Int32 *IN_p1,
       asn1SccT_Boolean     *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   sender005_RI_PI_5_To_PID(PID_env, IN_p1, OUT_p2
);
}

void sender005_RI_PI_5_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1,
       asn1SccT_Boolean     *OUT_p2
)
{

   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_sender005_pi_5
     (asn1SccPID,
      void *, size_t,
      void *, size_t *);

   vm_sender005_pi_5
     (dest_pid,
      (void *)IN_p1, sizeof(asn1SccT_Int32),
      (void *)OUT_p2, &size_OUT_buf_p2);


  sender005_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void sender005_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void sender005_get_sender(asn1SccPID *sender_pid);
  sender005_get_sender(sender_pid);
}

void sender005_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = sender005_recent_error;
}

void sender005_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    sender005_RI_get_last_error(err);
}

