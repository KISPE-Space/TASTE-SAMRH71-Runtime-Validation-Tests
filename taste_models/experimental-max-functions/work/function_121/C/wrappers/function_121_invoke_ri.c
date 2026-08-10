// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error function_121_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned function_121_initialized;

void function_121_RI_RI_1_To_PID(asn1SccPID dest_pid, 
      const asn1SccMyInteger *IN_p1
);
void function_121_RI_RI_1(
      const asn1SccMyInteger *IN_p1
);
void function_121_RI_RI_1(
      const asn1SccMyInteger *IN_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   function_121_RI_RI_1_To_PID(PID_env, IN_p1
);
}

void function_121_RI_RI_1_To_PID(asn1SccPID dest_pid, 
      const asn1SccMyInteger *IN_p1
)
{


   // Send the message via the middleware API
   extern void vm_function_121_ri_1
     (asn1SccPID,
      void *, size_t);

   vm_function_121_ri_1
     (dest_pid,
      (void *)IN_p1, sizeof(asn1SccMyInteger));


  function_121_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void function_121_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void function_121_get_sender(asn1SccPID *sender_pid);
  function_121_get_sender(sender_pid);
}

void function_121_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = function_121_recent_error;
}

void function_121_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    function_121_RI_get_last_error(err);
}

