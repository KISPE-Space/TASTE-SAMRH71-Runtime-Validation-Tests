// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error uartotherend_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned uartotherend_initialized;

void uartotherend_RI_samrh71rx_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt8 *IN_is71invalue
);
void uartotherend_RI_samrh71rx(
      const asn1SccT_UInt8 *IN_is71invalue
);
void uartotherend_RI_samrh71rx(
      const asn1SccT_UInt8 *IN_is71invalue
)
{
   // When no destination is specified, send to everyone (multicast)
   uartotherend_RI_samrh71rx_To_PID(PID_env, IN_is71invalue
);
}

void uartotherend_RI_samrh71rx_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt8 *IN_is71invalue
)
{
   int is71invalue_error_code = 0;
   // Encode parameter iS71InValue using ASN.1 ACN
   
   static char IN_buf_is71invalue[asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_is71invalue =
      Encode_ACN_T_UInt8
        ((void *)&IN_buf_is71invalue,
          asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccT_UInt8 *)IN_is71invalue,
          &is71invalue_error_code);
   if (-1 == size_IN_buf_is71invalue) {
      uartotherend_recent_error.kind = T_Runtime_Error_encodeerror_PRESENT;
      uartotherend_recent_error.u.encodeerror = is71invalue_error_code;
      return;
   }


   // Send the message via the middleware API
   extern void vm_uartotherend_samrh71rx
     (asn1SccPID,
      void *, size_t);

   vm_uartotherend_samrh71rx
     (dest_pid,
      (void *)&IN_buf_is71invalue, (size_t)size_IN_buf_is71invalue);


  uartotherend_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void uartotherend_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void uartotherend_get_sender(asn1SccPID *sender_pid);
  uartotherend_get_sender(sender_pid);
}

void uartotherend_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = uartotherend_recent_error;
}

void uartotherend_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    uartotherend_RI_get_last_error(err);
}

