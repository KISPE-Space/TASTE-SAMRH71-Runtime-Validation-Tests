// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error comms_hub_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned comms_hub_initialized;

void comms_hub_RI_uart1tx_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt8 *IN_p1
);
void comms_hub_RI_uart1tx(
      const asn1SccT_UInt8 *IN_p1
);
void comms_hub_RI_uart1tx(
      const asn1SccT_UInt8 *IN_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   comms_hub_RI_uart1tx_To_PID(PID_env, IN_p1
);
}

void comms_hub_RI_uart1tx_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt8 *IN_p1
)
{
   int p1_error_code = 0;
   // Encode parameter p1 using ASN.1 ACN
   
   static char IN_buf_p1[asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_p1 =
      Encode_ACN_T_UInt8
        ((void *)&IN_buf_p1,
          asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccT_UInt8 *)IN_p1,
          &p1_error_code);
   if (-1 == size_IN_buf_p1) {
      comms_hub_recent_error.kind = T_Runtime_Error_encodeerror_PRESENT;
      comms_hub_recent_error.u.encodeerror = p1_error_code;
      return;
   }


   // Send the message via the middleware API
   extern void vm_comms_hub_uart1tx
     (asn1SccPID,
      void *, size_t);

   vm_comms_hub_uart1tx
     (dest_pid,
      (void *)&IN_buf_p1, (size_t)size_IN_buf_p1);


  comms_hub_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void comms_hub_RI_uart3tx_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt8 *IN_p1
);
void comms_hub_RI_uart3tx(
      const asn1SccT_UInt8 *IN_p1
);
void comms_hub_RI_uart3tx(
      const asn1SccT_UInt8 *IN_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   comms_hub_RI_uart3tx_To_PID(PID_env, IN_p1
);
}

void comms_hub_RI_uart3tx_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt8 *IN_p1
)
{
   int p1_error_code = 0;
   // Encode parameter p1 using ASN.1 ACN
   
   static char IN_buf_p1[asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_p1 =
      Encode_ACN_T_UInt8
        ((void *)&IN_buf_p1,
          asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccT_UInt8 *)IN_p1,
          &p1_error_code);
   if (-1 == size_IN_buf_p1) {
      comms_hub_recent_error.kind = T_Runtime_Error_encodeerror_PRESENT;
      comms_hub_recent_error.u.encodeerror = p1_error_code;
      return;
   }


   // Send the message via the middleware API
   extern void vm_comms_hub_uart3tx
     (asn1SccPID,
      void *, size_t);

   vm_comms_hub_uart3tx
     (dest_pid,
      (void *)&IN_buf_p1, (size_t)size_IN_buf_p1);


  comms_hub_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void comms_hub_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void comms_hub_get_sender(asn1SccPID *sender_pid);
  comms_hub_get_sender(sender_pid);
}

void comms_hub_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = comms_hub_recent_error;
}

void comms_hub_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    comms_hub_RI_get_last_error(err);
}

