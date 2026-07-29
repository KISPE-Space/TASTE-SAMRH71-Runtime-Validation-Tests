// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error teststart00_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned teststart00_initialized;

void teststart00_RI_PI_1_StartTestCC06_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_1_StartTestCC06(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_1_StartTestCC06(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_1_StartTestCC06_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_1_StartTestCC06_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_1_starttestcc06
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_1_starttestcc06
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void teststart00_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void teststart00_get_sender(asn1SccPID *sender_pid);
  teststart00_get_sender(sender_pid);
}

void teststart00_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = teststart00_recent_error;
}

void teststart00_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    teststart00_RI_get_last_error(err);
}

