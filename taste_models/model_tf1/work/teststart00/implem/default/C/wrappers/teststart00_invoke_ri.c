// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error teststart00_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned teststart00_initialized;

void teststart00_RI_MQueueCallBack12_PI_1_To_PID(asn1SccPID dest_pid);
void teststart00_RI_MQueueCallBack12_PI_1(void);
void teststart00_RI_MQueueCallBack12_PI_1(void)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_MQueueCallBack12_PI_1_To_PID(PID_env);
}

void teststart00_RI_MQueueCallBack12_PI_1_To_PID(asn1SccPID dest_pid)
{


   // Send the message via the middleware API
   extern void vm_teststart00_mqueuecallback12_pi_1(asn1SccPID);
   vm_teststart00_mqueuecallback12_pi_1(dest_pid);

  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_1_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_1(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_1(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_1_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_1_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_1
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_1
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_10_Act_Start_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_10_Act_Start(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_10_Act_Start(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_10_Act_Start_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_10_Act_Start_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_10_act_start
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_10_act_start
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_10_Callback_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_10_Callback(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_10_Callback(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_10_Callback_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_10_Callback_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_10_callback
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_10_callback
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_1_Prot_Start_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_1_Prot_Start(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_1_Prot_Start(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_1_Prot_Start_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_1_Prot_Start_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_1_prot_start
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_1_prot_start
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_1_STARTSDL14_To_PID(asn1SccPID dest_pid, 
      const asn1SccCounter *IN_p1
);
void teststart00_RI_PI_1_STARTSDL14(
      const asn1SccCounter *IN_p1
);
void teststart00_RI_PI_1_STARTSDL14(
      const asn1SccCounter *IN_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_1_STARTSDL14_To_PID(PID_env, IN_p1
);
}

void teststart00_RI_PI_1_STARTSDL14_To_PID(asn1SccPID dest_pid, 
      const asn1SccCounter *IN_p1
)
{


   // Send the message via the middleware API
   extern void vm_teststart00_pi_1_startsdl14
     (asn1SccPID,
      void *, size_t);

   vm_teststart00_pi_1_startsdl14
     (dest_pid,
      (void *)IN_p1, sizeof(asn1SccCounter));


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_1_UnProt_Start_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_1_UnProt_Start(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_1_UnProt_Start(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_1_UnProt_Start_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_1_UnProt_Start_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_1_unprot_start
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_1_unprot_start
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_2_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1
);
void teststart00_RI_PI_2(
      const asn1SccT_Int32 *IN_p1
);
void teststart00_RI_PI_2(
      const asn1SccT_Int32 *IN_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_2_To_PID(PID_env, IN_p1
);
}

void teststart00_RI_PI_2_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1
)
{


   // Send the message via the middleware API
   extern void vm_teststart00_pi_2
     (asn1SccPID,
      void *, size_t);

   vm_teststart00_pi_2
     (dest_pid,
      (void *)IN_p1, sizeof(asn1SccT_Int32));


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_3_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_3(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_3(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_3_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_3_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_3
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_3
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_4_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_4(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_4(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_4_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_4_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_4
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_4
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_6_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_6(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_6(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_6_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_6_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_6
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_6
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_7_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_7(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_7(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_7_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_7_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_7
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_7
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_8_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_8(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_8(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_8_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_8_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_8
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_8
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_Mon_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_Mon(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_Mon(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_Mon_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_Mon_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_mon
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_mon
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_STARTSDL08_To_PID(asn1SccPID dest_pid, 
      const asn1SccCounter *IN_p1
);
void teststart00_RI_PI_STARTSDL08(
      const asn1SccCounter *IN_p1
);
void teststart00_RI_PI_STARTSDL08(
      const asn1SccCounter *IN_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_STARTSDL08_To_PID(PID_env, IN_p1
);
}

void teststart00_RI_PI_STARTSDL08_To_PID(asn1SccPID dest_pid, 
      const asn1SccCounter *IN_p1
)
{


   // Send the message via the middleware API
   extern void vm_teststart00_pi_startsdl08
     (asn1SccPID,
      void *, size_t);

   vm_teststart00_pi_startsdl08
     (dest_pid,
      (void *)IN_p1, sizeof(asn1SccCounter));


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_start_SPCC06_To_PID(asn1SccPID dest_pid);
void teststart00_RI_PI_start_SPCC06(void);
void teststart00_RI_PI_start_SPCC06(void)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_start_SPCC06_To_PID(PID_env);
}

void teststart00_RI_PI_start_SPCC06_To_PID(asn1SccPID dest_pid)
{


   // Send the message via the middleware API
   extern void vm_teststart00_pi_start_spcc06(asn1SccPID);
   vm_teststart00_pi_start_spcc06(dest_pid);

  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_RI_22_To_PID(asn1SccPID dest_pid);
void teststart00_RI_RI_22(void);
void teststart00_RI_RI_22(void)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_RI_22_To_PID(PID_env);
}

void teststart00_RI_RI_22_To_PID(asn1SccPID dest_pid)
{


   // Send the message via the middleware API
   extern void vm_teststart00_ri_22(asn1SccPID);
   vm_teststart00_ri_22(dest_pid);

  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_RI_5_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_RI_5(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_RI_5(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_RI_5_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_RI_5_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_ri_5
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_ri_5
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_TestACN11_PI_1_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_TestACN11_PI_1(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_TestACN11_PI_1(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_TestACN11_PI_1_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_TestACN11_PI_1_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_testacn11_pi_1
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_testacn11_pi_1
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_TestComms09_PI_1_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1
);
void teststart00_RI_TestComms09_PI_1(
      const asn1SccT_Int32 *IN_p1
);
void teststart00_RI_TestComms09_PI_1(
      const asn1SccT_Int32 *IN_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_TestComms09_PI_1_To_PID(PID_env, IN_p1
);
}

void teststart00_RI_TestComms09_PI_1_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1
)
{


   // Send the message via the middleware API
   extern void vm_teststart00_testcomms09_pi_1
     (asn1SccPID,
      void *, size_t);

   vm_teststart00_testcomms09_pi_1
     (dest_pid,
      (void *)IN_p1, sizeof(asn1SccT_Int32));


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_TestComms10_PI_1_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1
);
void teststart00_RI_TestComms10_PI_1(
      const asn1SccT_Int32 *IN_p1
);
void teststart00_RI_TestComms10_PI_1(
      const asn1SccT_Int32 *IN_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_TestComms10_PI_1_To_PID(PID_env, IN_p1
);
}

void teststart00_RI_TestComms10_PI_1_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_Int32 *IN_p1
)
{


   // Send the message via the middleware API
   extern void vm_teststart00_testcomms10_pi_1
     (asn1SccPID,
      void *, size_t);

   vm_teststart00_testcomms10_pi_1
     (dest_pid,
      (void *)IN_p1, sizeof(asn1SccT_Int32));


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_TestRTCommon02_PI_2_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_TestRTCommon02_PI_2(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_TestRTCommon02_PI_2(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_TestRTCommon02_PI_2_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_TestRTCommon02_PI_2_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_testrtcommon02_pi_2
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_testrtcommon02_pi_2
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_TestRTCommon02_PI_3_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_TestRTCommon02_PI_3(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_TestRTCommon02_PI_3(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_TestRTCommon02_PI_3_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_TestRTCommon02_PI_3_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_testrtcommon02_pi_3
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_testrtcommon02_pi_3
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

