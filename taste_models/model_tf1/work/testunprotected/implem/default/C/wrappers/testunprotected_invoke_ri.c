// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error testunprotected_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned testunprotected_initialized;

void testunprotected_RI_PI_1_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32   *IN_p1,
       const asn1SccT_UInt32  *IN_p2,
       const asn1SccT_Int8    *IN_p3,
       const asn1SccT_UInt8   *IN_p4,
       const asn1SccT_Boolean *IN_p5,
       asn1SccT_Boolean       *OUT_p6
);
void testunprotected_RI_PI_1(
      const asn1SccT_Int32   *IN_p1,
       const asn1SccT_UInt32  *IN_p2,
       const asn1SccT_Int8    *IN_p3,
       const asn1SccT_UInt8   *IN_p4,
       const asn1SccT_Boolean *IN_p5,
       asn1SccT_Boolean       *OUT_p6
);
void testunprotected_RI_PI_1(
      const asn1SccT_Int32   *IN_p1,
       const asn1SccT_UInt32  *IN_p2,
       const asn1SccT_Int8    *IN_p3,
       const asn1SccT_UInt8   *IN_p4,
       const asn1SccT_Boolean *IN_p5,
       asn1SccT_Boolean       *OUT_p6
)
{
   // When no destination is specified, send to everyone (multicast)
   testunprotected_RI_PI_1_To_PID(PID_env, IN_p1, IN_p2, IN_p3, IN_p4, IN_p5, OUT_p6
);
}

void testunprotected_RI_PI_1_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32   *IN_p1,
       const asn1SccT_UInt32  *IN_p2,
       const asn1SccT_Int8    *IN_p3,
       const asn1SccT_UInt8   *IN_p4,
       const asn1SccT_Boolean *IN_p5,
       asn1SccT_Boolean       *OUT_p6
)
{

   size_t      size_OUT_buf_p6 = 0;

   // Send the message via the middleware API
   extern void vm_testunprotected_pi_1
     (asn1SccPID,
      void *, size_t,
      void *, size_t,
      void *, size_t,
      void *, size_t,
      void *, size_t,
      void *, size_t *);

   vm_testunprotected_pi_1
     (dest_pid,
      (void *)IN_p1, sizeof(asn1SccT_Int32),
      (void *)IN_p2, sizeof(asn1SccT_UInt32),
      (void *)IN_p3, sizeof(asn1SccT_Int8),
      (void *)IN_p4, sizeof(asn1SccT_UInt8),
      (void *)IN_p5, sizeof(asn1SccT_Boolean),
      (void *)OUT_p6, &size_OUT_buf_p6);


  testunprotected_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testunprotected_RI_PI_1_00_To_PID(asn1SccPID dest_pid);
void testunprotected_RI_PI_1_00(void);
void testunprotected_RI_PI_1_00(void)
{
   // When no destination is specified, send to everyone (multicast)
   testunprotected_RI_PI_1_00_To_PID(PID_env);
}

void testunprotected_RI_PI_1_00_To_PID(asn1SccPID dest_pid)
{


   // Send the message via the middleware API
   extern void vm_testunprotected_pi_1_00(asn1SccPID);
   vm_testunprotected_pi_1_00(dest_pid);

  testunprotected_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testunprotected_RI_TestUnProtOUT05_PI_1_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_UInt32  *OUT_p2,
       asn1SccT_Int8    *OUT_p3,
       asn1SccT_UInt8   *OUT_p4,
       asn1SccT_Boolean *OUT_p5,
       asn1SccT_Boolean *OUT_p6
);
void testunprotected_RI_TestUnProtOUT05_PI_1(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_UInt32  *OUT_p2,
       asn1SccT_Int8    *OUT_p3,
       asn1SccT_UInt8   *OUT_p4,
       asn1SccT_Boolean *OUT_p5,
       asn1SccT_Boolean *OUT_p6
);
void testunprotected_RI_TestUnProtOUT05_PI_1(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_UInt32  *OUT_p2,
       asn1SccT_Int8    *OUT_p3,
       asn1SccT_UInt8   *OUT_p4,
       asn1SccT_Boolean *OUT_p5,
       asn1SccT_Boolean *OUT_p6
)
{
   // When no destination is specified, send to everyone (multicast)
   testunprotected_RI_TestUnProtOUT05_PI_1_To_PID(PID_env, OUT_p1, OUT_p2, OUT_p3, OUT_p4, OUT_p5, OUT_p6
);
}

void testunprotected_RI_TestUnProtOUT05_PI_1_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_UInt32  *OUT_p2,
       asn1SccT_Int8    *OUT_p3,
       asn1SccT_UInt8   *OUT_p4,
       asn1SccT_Boolean *OUT_p5,
       asn1SccT_Boolean *OUT_p6
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;
   size_t      size_OUT_buf_p3 = 0;
   size_t      size_OUT_buf_p4 = 0;
   size_t      size_OUT_buf_p5 = 0;
   size_t      size_OUT_buf_p6 = 0;

   // Send the message via the middleware API
   extern void vm_testunprotected_testunprotout05_pi_1
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *,
      void *, size_t *,
      void *, size_t *,
      void *, size_t *,
      void *, size_t *);

   vm_testunprotected_testunprotout05_pi_1
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2,
      (void *)OUT_p3, &size_OUT_buf_p3,
      (void *)OUT_p4, &size_OUT_buf_p4,
      (void *)OUT_p5, &size_OUT_buf_p5,
      (void *)OUT_p6, &size_OUT_buf_p6);


  testunprotected_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void testunprotected_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void testunprotected_get_sender(asn1SccPID *sender_pid);
  testunprotected_get_sender(sender_pid);
}

void testunprotected_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = testunprotected_recent_error;
}

void testunprotected_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    testunprotected_RI_get_last_error(err);
}

