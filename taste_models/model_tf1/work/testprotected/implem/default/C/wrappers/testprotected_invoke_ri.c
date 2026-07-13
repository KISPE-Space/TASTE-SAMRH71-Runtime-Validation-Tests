// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error testprotected_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned testprotected_initialized;

void testprotected_RI_PI_1_5IN_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Boolean *IN_p1,
       const asn1SccT_Int32   *IN_p2,
       const asn1SccT_UInt32  *IN_p3,
       const asn1SccT_Int8    *IN_p4,
       const asn1SccT_UInt8   *IN_p5,
       asn1SccT_Boolean       *OUT_p6
);
void testprotected_RI_PI_1_5IN(
      const asn1SccT_Boolean *IN_p1,
       const asn1SccT_Int32   *IN_p2,
       const asn1SccT_UInt32  *IN_p3,
       const asn1SccT_Int8    *IN_p4,
       const asn1SccT_UInt8   *IN_p5,
       asn1SccT_Boolean       *OUT_p6
);
void testprotected_RI_PI_1_5IN(
      const asn1SccT_Boolean *IN_p1,
       const asn1SccT_Int32   *IN_p2,
       const asn1SccT_UInt32  *IN_p3,
       const asn1SccT_Int8    *IN_p4,
       const asn1SccT_UInt8   *IN_p5,
       asn1SccT_Boolean       *OUT_p6
)
{
   // When no destination is specified, send to everyone (multicast)
   testprotected_RI_PI_1_5IN_To_PID(PID_env, IN_p1, IN_p2, IN_p3, IN_p4, IN_p5, OUT_p6
);
}

void testprotected_RI_PI_1_5IN_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Boolean *IN_p1,
       const asn1SccT_Int32   *IN_p2,
       const asn1SccT_UInt32  *IN_p3,
       const asn1SccT_Int8    *IN_p4,
       const asn1SccT_UInt8   *IN_p5,
       asn1SccT_Boolean       *OUT_p6
)
{

   size_t      size_OUT_buf_p6 = 0;

   // Send the message via the middleware API
   extern void vm_testprotected_pi_1_5in
     (asn1SccPID,
      void *, size_t,
      void *, size_t,
      void *, size_t,
      void *, size_t,
      void *, size_t,
      void *, size_t *);

   vm_testprotected_pi_1_5in
     (dest_pid,
      (void *)IN_p1, sizeof(asn1SccT_Boolean),
      (void *)IN_p2, sizeof(asn1SccT_Int32),
      (void *)IN_p3, sizeof(asn1SccT_UInt32),
      (void *)IN_p4, sizeof(asn1SccT_Int8),
      (void *)IN_p5, sizeof(asn1SccT_UInt8),
      (void *)OUT_p6, &size_OUT_buf_p6);


  testprotected_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testprotected_RI_PI_1_5OUT_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_UInt32  *OUT_p2,
       asn1SccT_UInt8   *OUT_p3,
       asn1SccT_Int8    *OUT_p4,
       asn1SccT_Boolean *OUT_p5
);
void testprotected_RI_PI_1_5OUT(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_UInt32  *OUT_p2,
       asn1SccT_UInt8   *OUT_p3,
       asn1SccT_Int8    *OUT_p4,
       asn1SccT_Boolean *OUT_p5
);
void testprotected_RI_PI_1_5OUT(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_UInt32  *OUT_p2,
       asn1SccT_UInt8   *OUT_p3,
       asn1SccT_Int8    *OUT_p4,
       asn1SccT_Boolean *OUT_p5
)
{
   // When no destination is specified, send to everyone (multicast)
   testprotected_RI_PI_1_5OUT_To_PID(PID_env, OUT_p1, OUT_p2, OUT_p3, OUT_p4, OUT_p5
);
}

void testprotected_RI_PI_1_5OUT_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_UInt32  *OUT_p2,
       asn1SccT_UInt8   *OUT_p3,
       asn1SccT_Int8    *OUT_p4,
       asn1SccT_Boolean *OUT_p5
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;
   size_t      size_OUT_buf_p3 = 0;
   size_t      size_OUT_buf_p4 = 0;
   size_t      size_OUT_buf_p5 = 0;

   // Send the message via the middleware API
   extern void vm_testprotected_pi_1_5out
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *,
      void *, size_t *,
      void *, size_t *,
      void *, size_t *);

   vm_testprotected_pi_1_5out
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2,
      (void *)OUT_p3, &size_OUT_buf_p3,
      (void *)OUT_p4, &size_OUT_buf_p4,
      (void *)OUT_p5, &size_OUT_buf_p5);


  testprotected_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testprotected_RI_PI_1_ZERO_To_PID(asn1SccPID dest_pid);
void testprotected_RI_PI_1_ZERO(void);
void testprotected_RI_PI_1_ZERO(void)
{
   // When no destination is specified, send to everyone (multicast)
   testprotected_RI_PI_1_ZERO_To_PID(PID_env);
}

void testprotected_RI_PI_1_ZERO_To_PID(asn1SccPID dest_pid)
{


   // Send the message via the middleware API
   extern void vm_testprotected_pi_1_zero(asn1SccPID);
   vm_testprotected_pi_1_zero(dest_pid);

  testprotected_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void testprotected_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void testprotected_get_sender(asn1SccPID *sender_pid);
  testprotected_get_sender(sender_pid);
}

void testprotected_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = testprotected_recent_error;
}

void testprotected_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    testprotected_RI_get_last_error(err);
}

