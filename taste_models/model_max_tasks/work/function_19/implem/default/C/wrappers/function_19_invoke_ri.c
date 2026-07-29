// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error function_19_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned function_19_initialized;

void function_19_RI_PI_2_20_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1
);
void function_19_RI_PI_2_20(
      const asn1SccT_Int32 *IN_p1
);
void function_19_RI_PI_2_20(
      const asn1SccT_Int32 *IN_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   function_19_RI_PI_2_20_To_PID(PID_env, IN_p1
);
}

void function_19_RI_PI_2_20_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1
)
{


   // Send the message via the middleware API
   extern void vm_function_19_pi_2_20
     (asn1SccPID,
      void *, size_t);

   vm_function_19_pi_2_20
     (dest_pid,
      (void *)IN_p1, sizeof(asn1SccT_Int32));


  function_19_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void function_19_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void function_19_get_sender(asn1SccPID *sender_pid);
  function_19_get_sender(sender_pid);
}

void function_19_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = function_19_recent_error;
}

void function_19_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    function_19_RI_get_last_error(err);
}

