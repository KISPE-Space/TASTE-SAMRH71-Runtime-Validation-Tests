// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error teststart00_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned teststart00_initialized;

void teststart00_RI_PI_1_To_PID(asn1SccPID dest_pid);
void teststart00_RI_PI_1(void);
void teststart00_RI_PI_1(void)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_1_To_PID(PID_env);
}

void teststart00_RI_PI_1_To_PID(asn1SccPID dest_pid)
{


   // Send the message via the middleware API
   extern void vm_teststart00_pi_1(asn1SccPID);
   vm_teststart00_pi_1(dest_pid);

  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_10_TestModules_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_10_TestModules(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_10_TestModules(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_10_TestModules_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_10_TestModules_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_10_testmodules
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_10_testmodules
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_1_Broker_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_1_Broker(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_1_Broker(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_1_Broker_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_1_Broker_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_1_broker
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_1_broker
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



void teststart00_RI_PI_1_TestACN_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_1_TestACN(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_1_TestACN(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_1_TestACN_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_1_TestACN_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_1_testacn
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_1_testacn
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_1_TestComms09_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_1_TestComms09(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_1_TestComms09(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_1_TestComms09_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_1_TestComms09_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_1_testcomms09
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_1_testcomms09
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


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
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_2(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_2(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_2_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_2_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_2
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_2
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_PI_2_Cyclic_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_2_Cyclic(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_PI_2_Cyclic(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_PI_2_Cyclic_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_PI_2_Cyclic_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_pi_2_cyclic
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_pi_2_cyclic
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


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



void teststart00_RI_TPI_1_TestComms10_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_TPI_1_TestComms10(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
);
void teststart00_RI_TPI_1_TestComms10(
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_TPI_1_TestComms10_To_PID(PID_env, OUT_p1, OUT_p2
);
}

void teststart00_RI_TPI_1_TestComms10_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32   *OUT_p1,
       asn1SccT_Boolean *OUT_p2
)
{

   size_t      size_OUT_buf_p1 = 0;
   size_t      size_OUT_buf_p2 = 0;

   // Send the message via the middleware API
   extern void vm_teststart00_tpi_1_testcomms10
     (asn1SccPID,
      void *, size_t *,
      void *, size_t *);

   vm_teststart00_tpi_1_testcomms10
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1,
      (void *)OUT_p2, &size_OUT_buf_p2);


  teststart00_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void teststart00_RI_samrh71tx_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt8 *IN_is71outvalue
);
void teststart00_RI_samrh71tx(
      const asn1SccT_UInt8 *IN_is71outvalue
);
void teststart00_RI_samrh71tx(
      const asn1SccT_UInt8 *IN_is71outvalue
)
{
   // When no destination is specified, send to everyone (multicast)
   teststart00_RI_samrh71tx_To_PID(PID_env, IN_is71outvalue
);
}

void teststart00_RI_samrh71tx_To_PID(asn1SccPID dest_pid, 
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
      teststart00_recent_error.kind = T_Runtime_Error_encodeerror_PRESENT;
      teststart00_recent_error.u.encodeerror = is71outvalue_error_code;
      return;
   }


   // Send the message via the middleware API
   extern void vm_teststart00_samrh71tx
     (asn1SccPID,
      void *, size_t);

   vm_teststart00_samrh71tx
     (dest_pid,
      (void *)&IN_buf_is71outvalue, (size_t)size_IN_buf_is71outvalue);


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

