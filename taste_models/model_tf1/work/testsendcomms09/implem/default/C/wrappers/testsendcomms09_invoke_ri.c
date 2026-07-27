// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error testsendcomms09_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned testsendcomms09_initialized;

void testsendcomms09_RI_PI_1_Send01_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send01(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send01(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testsendcomms09_RI_PI_1_Send01_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testsendcomms09_RI_PI_1_Send01_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testsendcomms09_pi_1_send01
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testsendcomms09_pi_1_send01
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testsendcomms09_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testsendcomms09_RI_PI_1_Send02_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send02(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send02(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testsendcomms09_RI_PI_1_Send02_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testsendcomms09_RI_PI_1_Send02_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testsendcomms09_pi_1_send02
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testsendcomms09_pi_1_send02
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testsendcomms09_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testsendcomms09_RI_PI_1_Send03_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send03(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send03(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testsendcomms09_RI_PI_1_Send03_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testsendcomms09_RI_PI_1_Send03_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testsendcomms09_pi_1_send03
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testsendcomms09_pi_1_send03
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testsendcomms09_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testsendcomms09_RI_PI_1_Send04_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send04(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send04(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testsendcomms09_RI_PI_1_Send04_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testsendcomms09_RI_PI_1_Send04_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testsendcomms09_pi_1_send04
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testsendcomms09_pi_1_send04
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testsendcomms09_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testsendcomms09_RI_PI_1_Send05_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send05(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send05(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testsendcomms09_RI_PI_1_Send05_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testsendcomms09_RI_PI_1_Send05_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testsendcomms09_pi_1_send05
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testsendcomms09_pi_1_send05
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testsendcomms09_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testsendcomms09_RI_PI_1_Send06_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send06(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send06(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testsendcomms09_RI_PI_1_Send06_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testsendcomms09_RI_PI_1_Send06_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testsendcomms09_pi_1_send06
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testsendcomms09_pi_1_send06
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testsendcomms09_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testsendcomms09_RI_PI_1_Send07_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send07(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send07(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testsendcomms09_RI_PI_1_Send07_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testsendcomms09_RI_PI_1_Send07_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testsendcomms09_pi_1_send07
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testsendcomms09_pi_1_send07
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testsendcomms09_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testsendcomms09_RI_PI_1_Send08_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send08(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send08(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testsendcomms09_RI_PI_1_Send08_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testsendcomms09_RI_PI_1_Send08_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testsendcomms09_pi_1_send08
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testsendcomms09_pi_1_send08
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testsendcomms09_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testsendcomms09_RI_PI_1_Send09_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send09(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send09(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testsendcomms09_RI_PI_1_Send09_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testsendcomms09_RI_PI_1_Send09_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testsendcomms09_pi_1_send09
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testsendcomms09_pi_1_send09
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testsendcomms09_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testsendcomms09_RI_PI_1_Send10_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send10(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testsendcomms09_RI_PI_1_Send10(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testsendcomms09_RI_PI_1_Send10_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testsendcomms09_RI_PI_1_Send10_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testsendcomms09_pi_1_send10
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testsendcomms09_pi_1_send10
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testsendcomms09_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void testsendcomms09_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void testsendcomms09_get_sender(asn1SccPID *sender_pid);
  testsendcomms09_get_sender(sender_pid);
}

void testsendcomms09_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = testsendcomms09_recent_error;
}

void testsendcomms09_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    testsendcomms09_RI_get_last_error(err);
}

