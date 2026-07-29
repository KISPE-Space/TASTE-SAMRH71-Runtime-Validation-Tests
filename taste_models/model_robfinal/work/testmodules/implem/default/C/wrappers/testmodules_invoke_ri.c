// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error testmodules_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned testmodules_initialized;

void testmodules_RI_PI_1_ActivationLog_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_ActivationLog(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_ActivationLog(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testmodules_RI_PI_1_ActivationLog_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testmodules_RI_PI_1_ActivationLog_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testmodules_pi_1_activationlog
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testmodules_pi_1_activationlog
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testmodules_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testmodules_RI_PI_1_Boot_Helper_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_Boot_Helper(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_Boot_Helper(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testmodules_RI_PI_1_Boot_Helper_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testmodules_RI_PI_1_Boot_Helper_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testmodules_pi_1_boot_helper
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testmodules_pi_1_boot_helper
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testmodules_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testmodules_RI_PI_1_BrokerLog_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_BrokerLog(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_BrokerLog(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testmodules_RI_PI_1_BrokerLog_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testmodules_RI_PI_1_BrokerLog_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testmodules_pi_1_brokerlog
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testmodules_pi_1_brokerlog
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testmodules_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testmodules_RI_PI_1_CPUCore_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_CPUCore(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_CPUCore(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testmodules_RI_PI_1_CPUCore_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testmodules_RI_PI_1_CPUCore_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testmodules_pi_1_cpucore
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testmodules_pi_1_cpucore
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testmodules_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testmodules_RI_PI_1_DeathReport_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_DeathReport(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_DeathReport(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testmodules_RI_PI_1_DeathReport_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testmodules_RI_PI_1_DeathReport_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testmodules_pi_1_deathreport
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testmodules_pi_1_deathreport
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testmodules_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testmodules_RI_PI_1_HAL_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_HAL(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_HAL(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testmodules_RI_PI_1_HAL_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testmodules_RI_PI_1_HAL_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testmodules_pi_1_hal
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testmodules_pi_1_hal
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testmodules_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testmodules_RI_PI_1_MonCallback_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_MonCallback(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_MonCallback(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testmodules_RI_PI_1_MonCallback_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testmodules_RI_PI_1_MonCallback_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testmodules_pi_1_moncallback
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testmodules_pi_1_moncallback
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testmodules_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testmodules_RI_PI_1_Threads_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_Threads(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_1_Threads(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testmodules_RI_PI_1_Threads_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testmodules_RI_PI_1_Threads_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testmodules_pi_1_threads
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testmodules_pi_1_threads
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testmodules_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void testmodules_RI_PI_2_Mon00A_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_2_Mon00A(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void testmodules_RI_PI_2_Mon00A(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   testmodules_RI_PI_2_Mon00A_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void testmodules_RI_PI_2_Mon00A_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_testmodules_pi_2_mon00a
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_testmodules_pi_2_mon00a
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  testmodules_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void testmodules_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void testmodules_get_sender(asn1SccPID *sender_pid);
  testmodules_get_sender(sender_pid);
}

void testmodules_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = testmodules_recent_error;
}

void testmodules_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    testmodules_RI_get_last_error(err);
}

