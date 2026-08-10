// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error tf_reporter_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned tf_reporter_initialized;

void tf_reporter_RI_samrh71tx_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt8 *IN_is71outvalue
);
void tf_reporter_RI_samrh71tx(
      const asn1SccT_UInt8 *IN_is71outvalue
);
void tf_reporter_RI_samrh71tx(
      const asn1SccT_UInt8 *IN_is71outvalue
)
{
   // When no destination is specified, send to everyone (multicast)
   tf_reporter_RI_samrh71tx_To_PID(PID_env, IN_is71outvalue
);
}

void tf_reporter_RI_samrh71tx_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt8 *IN_is71outvalue
)
{
   int is71outvalue_error_code = 0;
   // Encode parameter iS71OutValue using ASN.1 ACN
   
   static char IN_buf_is71outvalue[asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_is71outvalue =
      Encode_ACN_T_UInt8
        ((void *)&IN_buf_is71outvalue,
          asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccT_UInt8 *)IN_is71outvalue,
          &is71outvalue_error_code);
   if (-1 == size_IN_buf_is71outvalue) {
      tf_reporter_recent_error.kind = T_Runtime_Error_encodeerror_PRESENT;
      tf_reporter_recent_error.u.encodeerror = is71outvalue_error_code;
      return;
   }


   // Send the message via the middleware API
   extern void vm_tf_reporter_samrh71tx
     (asn1SccPID,
      void *, size_t);

   vm_tf_reporter_samrh71tx
     (dest_pid,
      (void *)&IN_buf_is71outvalue, (size_t)size_IN_buf_is71outvalue);


  tf_reporter_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void tf_reporter_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void tf_reporter_get_sender(asn1SccPID *sender_pid);
  tf_reporter_get_sender(sender_pid);
}

void tf_reporter_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = tf_reporter_recent_error;
}

void tf_reporter_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    tf_reporter_RI_get_last_error(err);
}

