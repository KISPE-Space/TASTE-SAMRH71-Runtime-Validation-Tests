// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error sendacn_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned sendacn_initialized;

void sendacn_RI_PI_1_ACN03_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Boolean *IN_p1,
       asn1SccT_Boolean       *OUT_p2
);
void sendacn_RI_PI_1_ACN03(
      const asn1SccT_Boolean *IN_p1,
       asn1SccT_Boolean       *OUT_p2
);
void sendacn_RI_PI_1_ACN03(
      const asn1SccT_Boolean *IN_p1,
       asn1SccT_Boolean       *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   sendacn_RI_PI_1_ACN03_To_PID(PID_env, IN_p1, OUT_p2
);
}

void sendacn_RI_PI_1_ACN03_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Boolean *IN_p1,
       asn1SccT_Boolean       *OUT_p2
)
{
   int p1_error_code = 0;
   // Encode parameter p1 using ASN.1 ACN
   
   static char IN_buf_p1[asn1SccT_Boolean_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_p1 =
      Encode_ACN_T_Boolean
        ((void *)&IN_buf_p1,
          asn1SccT_Boolean_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccT_Boolean *)IN_p1,
          &p1_error_code);
   if (-1 == size_IN_buf_p1) {
      sendacn_recent_error.kind = T_Runtime_Error_encodeerror_PRESENT;
      sendacn_recent_error.u.encodeerror = p1_error_code;
      return;
   }

   // Buffer for decoding parameter p2 from ACN
   
   static char OUT_buf_p2[asn1SccT_Boolean_REQUIRED_BYTES_FOR_ACN_ENCODING];
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_sendacn_pi_1_acn03
     (asn1SccPID,
      void *, size_t,
      void *, size_t *);

   vm_sendacn_pi_1_acn03
     (dest_pid,
      (void *)&IN_buf_p1, (size_t)size_IN_buf_p1,
      (void *)&OUT_buf_p2, &size_OUT_buf_p2);


   int p2_error_code = 0;
   // Decode parameter p2
   if (0 != Decode_ACN_T_Boolean
              (OUT_p2, (void *)&OUT_buf_p2, size_OUT_buf_p2, &p2_error_code)) {
      sendacn_recent_error.kind = T_Runtime_Error_decodeerror_PRESENT;
      sendacn_recent_error.u.decodeerror = p2_error_code;
      return;
  }
  sendacn_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void sendacn_RI_PI_1_ACN04_To_PID(asn1SccPID dest_pid, 
      const asn1SccPID *IN_p1,
       asn1SccPID       *OUT_p2
);
void sendacn_RI_PI_1_ACN04(
      const asn1SccPID *IN_p1,
       asn1SccPID       *OUT_p2
);
void sendacn_RI_PI_1_ACN04(
      const asn1SccPID *IN_p1,
       asn1SccPID       *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   sendacn_RI_PI_1_ACN04_To_PID(PID_env, IN_p1, OUT_p2
);
}

void sendacn_RI_PI_1_ACN04_To_PID(asn1SccPID dest_pid, 
      const asn1SccPID *IN_p1,
       asn1SccPID       *OUT_p2
)
{
   int p1_error_code = 0;
   // Encode parameter p1 using ASN.1 ACN
   
   static char IN_buf_p1[asn1SccPID_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_p1 =
      Encode_ACN_PID
        ((void *)&IN_buf_p1,
          asn1SccPID_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccPID *)IN_p1,
          &p1_error_code);
   if (-1 == size_IN_buf_p1) {
      sendacn_recent_error.kind = T_Runtime_Error_encodeerror_PRESENT;
      sendacn_recent_error.u.encodeerror = p1_error_code;
      return;
   }

   // Buffer for decoding parameter p2 from ACN
   
   static char OUT_buf_p2[asn1SccPID_REQUIRED_BYTES_FOR_ACN_ENCODING];
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_sendacn_pi_1_acn04
     (asn1SccPID,
      void *, size_t,
      void *, size_t *);

   vm_sendacn_pi_1_acn04
     (dest_pid,
      (void *)&IN_buf_p1, (size_t)size_IN_buf_p1,
      (void *)&OUT_buf_p2, &size_OUT_buf_p2);


   int p2_error_code = 0;
   // Decode parameter p2
   if (0 != Decode_ACN_PID
              (OUT_p2, (void *)&OUT_buf_p2, size_OUT_buf_p2, &p2_error_code)) {
      sendacn_recent_error.kind = T_Runtime_Error_decodeerror_PRESENT;
      sendacn_recent_error.u.decodeerror = p2_error_code;
      return;
  }
  sendacn_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void sendacn_RI_PI_1_ACN05_To_PID(asn1SccPID dest_pid, 
      const asn1SccPID_Range *IN_p1,
       asn1SccPID_Range       *OUT_p2
);
void sendacn_RI_PI_1_ACN05(
      const asn1SccPID_Range *IN_p1,
       asn1SccPID_Range       *OUT_p2
);
void sendacn_RI_PI_1_ACN05(
      const asn1SccPID_Range *IN_p1,
       asn1SccPID_Range       *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   sendacn_RI_PI_1_ACN05_To_PID(PID_env, IN_p1, OUT_p2
);
}

void sendacn_RI_PI_1_ACN05_To_PID(asn1SccPID dest_pid, 
      const asn1SccPID_Range *IN_p1,
       asn1SccPID_Range       *OUT_p2
)
{
   int p1_error_code = 0;
   // Encode parameter p1 using ASN.1 ACN
   
   static char IN_buf_p1[asn1SccPID_Range_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_p1 =
      Encode_ACN_PID_Range
        ((void *)&IN_buf_p1,
          asn1SccPID_Range_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccPID_Range *)IN_p1,
          &p1_error_code);
   if (-1 == size_IN_buf_p1) {
      sendacn_recent_error.kind = T_Runtime_Error_encodeerror_PRESENT;
      sendacn_recent_error.u.encodeerror = p1_error_code;
      return;
   }

   // Buffer for decoding parameter p2 from ACN
   
   static char OUT_buf_p2[asn1SccPID_Range_REQUIRED_BYTES_FOR_ACN_ENCODING];
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_sendacn_pi_1_acn05
     (asn1SccPID,
      void *, size_t,
      void *, size_t *);

   vm_sendacn_pi_1_acn05
     (dest_pid,
      (void *)&IN_buf_p1, (size_t)size_IN_buf_p1,
      (void *)&OUT_buf_p2, &size_OUT_buf_p2);


   int p2_error_code = 0;
   // Decode parameter p2
   if (0 != Decode_ACN_PID_Range
              (OUT_p2, (void *)&OUT_buf_p2, size_OUT_buf_p2, &p2_error_code)) {
      sendacn_recent_error.kind = T_Runtime_Error_decodeerror_PRESENT;
      sendacn_recent_error.u.decodeerror = p2_error_code;
      return;
  }
  sendacn_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void sendacn_RI_PI_1_ACN_01_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1,
       asn1SccT_Int32       *OUT_p2
);
void sendacn_RI_PI_1_ACN_01(
      const asn1SccT_Int32 *IN_p1,
       asn1SccT_Int32       *OUT_p2
);
void sendacn_RI_PI_1_ACN_01(
      const asn1SccT_Int32 *IN_p1,
       asn1SccT_Int32       *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   sendacn_RI_PI_1_ACN_01_To_PID(PID_env, IN_p1, OUT_p2
);
}

void sendacn_RI_PI_1_ACN_01_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1,
       asn1SccT_Int32       *OUT_p2
)
{
   int p1_error_code = 0;
   // Encode parameter p1 using ASN.1 ACN
   
   static char IN_buf_p1[asn1SccT_Int32_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_p1 =
      Encode_ACN_T_Int32
        ((void *)&IN_buf_p1,
          asn1SccT_Int32_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccT_Int32 *)IN_p1,
          &p1_error_code);
   if (-1 == size_IN_buf_p1) {
      sendacn_recent_error.kind = T_Runtime_Error_encodeerror_PRESENT;
      sendacn_recent_error.u.encodeerror = p1_error_code;
      return;
   }

   // Buffer for decoding parameter p2 from ACN
   
   static char OUT_buf_p2[asn1SccT_Int32_REQUIRED_BYTES_FOR_ACN_ENCODING];
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_sendacn_pi_1_acn_01
     (asn1SccPID,
      void *, size_t,
      void *, size_t *);

   vm_sendacn_pi_1_acn_01
     (dest_pid,
      (void *)&IN_buf_p1, (size_t)size_IN_buf_p1,
      (void *)&OUT_buf_p2, &size_OUT_buf_p2);


   int p2_error_code = 0;
   // Decode parameter p2
   if (0 != Decode_ACN_T_Int32
              (OUT_p2, (void *)&OUT_buf_p2, size_OUT_buf_p2, &p2_error_code)) {
      sendacn_recent_error.kind = T_Runtime_Error_decodeerror_PRESENT;
      sendacn_recent_error.u.decodeerror = p2_error_code;
      return;
  }
  sendacn_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void sendacn_RI_PI_1_ACN_02_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt8 *IN_p1,
       asn1SccT_UInt8       *OUT_p2
);
void sendacn_RI_PI_1_ACN_02(
      const asn1SccT_UInt8 *IN_p1,
       asn1SccT_UInt8       *OUT_p2
);
void sendacn_RI_PI_1_ACN_02(
      const asn1SccT_UInt8 *IN_p1,
       asn1SccT_UInt8       *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   sendacn_RI_PI_1_ACN_02_To_PID(PID_env, IN_p1, OUT_p2
);
}

void sendacn_RI_PI_1_ACN_02_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt8 *IN_p1,
       asn1SccT_UInt8       *OUT_p2
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
      sendacn_recent_error.kind = T_Runtime_Error_encodeerror_PRESENT;
      sendacn_recent_error.u.encodeerror = p1_error_code;
      return;
   }

   // Buffer for decoding parameter p2 from ACN
   
   static char OUT_buf_p2[asn1SccT_UInt8_REQUIRED_BYTES_FOR_ACN_ENCODING];
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_sendacn_pi_1_acn_02
     (asn1SccPID,
      void *, size_t,
      void *, size_t *);

   vm_sendacn_pi_1_acn_02
     (dest_pid,
      (void *)&IN_buf_p1, (size_t)size_IN_buf_p1,
      (void *)&OUT_buf_p2, &size_OUT_buf_p2);


   int p2_error_code = 0;
   // Decode parameter p2
   if (0 != Decode_ACN_T_UInt8
              (OUT_p2, (void *)&OUT_buf_p2, size_OUT_buf_p2, &p2_error_code)) {
      sendacn_recent_error.kind = T_Runtime_Error_decodeerror_PRESENT;
      sendacn_recent_error.u.decodeerror = p2_error_code;
      return;
  }
  sendacn_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void sendacn_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void sendacn_get_sender(asn1SccPID *sender_pid);
  sendacn_get_sender(sender_pid);
}

void sendacn_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = sendacn_recent_error;
}

void sendacn_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    sendacn_RI_get_last_error(err);
}

