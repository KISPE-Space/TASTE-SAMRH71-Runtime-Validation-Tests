// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error sender011_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned sender011_initialized;

void sender011_RI_PI_1_SR11_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR11(
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR11(
      asn1SccT_Int32 *OUT_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   sender011_RI_PI_1_SR11_To_PID(PID_env, OUT_p1
);
}

void sender011_RI_PI_1_SR11_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
)
{

   size_t      size_OUT_buf_p1 = 0;

   // Send the message via the middleware API
   extern void vm_sender011_pi_1_sr11
     (asn1SccPID,
      void *, size_t *);

   vm_sender011_pi_1_sr11
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1);


  sender011_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void sender011_RI_PI_1_SR12_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR12(
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR12(
      asn1SccT_Int32 *OUT_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   sender011_RI_PI_1_SR12_To_PID(PID_env, OUT_p1
);
}

void sender011_RI_PI_1_SR12_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
)
{

   size_t      size_OUT_buf_p1 = 0;

   // Send the message via the middleware API
   extern void vm_sender011_pi_1_sr12
     (asn1SccPID,
      void *, size_t *);

   vm_sender011_pi_1_sr12
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1);


  sender011_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void sender011_RI_PI_1_SR13_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR13(
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR13(
      asn1SccT_Int32 *OUT_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   sender011_RI_PI_1_SR13_To_PID(PID_env, OUT_p1
);
}

void sender011_RI_PI_1_SR13_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
)
{

   size_t      size_OUT_buf_p1 = 0;

   // Send the message via the middleware API
   extern void vm_sender011_pi_1_sr13
     (asn1SccPID,
      void *, size_t *);

   vm_sender011_pi_1_sr13
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1);


  sender011_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void sender011_RI_PI_1_SR14_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR14(
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR14(
      asn1SccT_Int32 *OUT_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   sender011_RI_PI_1_SR14_To_PID(PID_env, OUT_p1
);
}

void sender011_RI_PI_1_SR14_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
)
{

   size_t      size_OUT_buf_p1 = 0;

   // Send the message via the middleware API
   extern void vm_sender011_pi_1_sr14
     (asn1SccPID,
      void *, size_t *);

   vm_sender011_pi_1_sr14
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1);


  sender011_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void sender011_RI_PI_1_SR15_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR15(
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR15(
      asn1SccT_Int32 *OUT_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   sender011_RI_PI_1_SR15_To_PID(PID_env, OUT_p1
);
}

void sender011_RI_PI_1_SR15_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
)
{

   size_t      size_OUT_buf_p1 = 0;

   // Send the message via the middleware API
   extern void vm_sender011_pi_1_sr15
     (asn1SccPID,
      void *, size_t *);

   vm_sender011_pi_1_sr15
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1);


  sender011_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void sender011_RI_PI_1_SR16_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR16(
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR16(
      asn1SccT_Int32 *OUT_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   sender011_RI_PI_1_SR16_To_PID(PID_env, OUT_p1
);
}

void sender011_RI_PI_1_SR16_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
)
{

   size_t      size_OUT_buf_p1 = 0;

   // Send the message via the middleware API
   extern void vm_sender011_pi_1_sr16
     (asn1SccPID,
      void *, size_t *);

   vm_sender011_pi_1_sr16
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1);


  sender011_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void sender011_RI_PI_1_SR17_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR17(
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR17(
      asn1SccT_Int32 *OUT_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   sender011_RI_PI_1_SR17_To_PID(PID_env, OUT_p1
);
}

void sender011_RI_PI_1_SR17_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
)
{

   size_t      size_OUT_buf_p1 = 0;

   // Send the message via the middleware API
   extern void vm_sender011_pi_1_sr17
     (asn1SccPID,
      void *, size_t *);

   vm_sender011_pi_1_sr17
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1);


  sender011_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void sender011_RI_PI_1_SR18_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR18(
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR18(
      asn1SccT_Int32 *OUT_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   sender011_RI_PI_1_SR18_To_PID(PID_env, OUT_p1
);
}

void sender011_RI_PI_1_SR18_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
)
{

   size_t      size_OUT_buf_p1 = 0;

   // Send the message via the middleware API
   extern void vm_sender011_pi_1_sr18
     (asn1SccPID,
      void *, size_t *);

   vm_sender011_pi_1_sr18
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1);


  sender011_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void sender011_RI_PI_1_SR19_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR19(
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR19(
      asn1SccT_Int32 *OUT_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   sender011_RI_PI_1_SR19_To_PID(PID_env, OUT_p1
);
}

void sender011_RI_PI_1_SR19_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
)
{

   size_t      size_OUT_buf_p1 = 0;

   // Send the message via the middleware API
   extern void vm_sender011_pi_1_sr19
     (asn1SccPID,
      void *, size_t *);

   vm_sender011_pi_1_sr19
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1);


  sender011_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void sender011_RI_PI_1_SR20_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR20(
      asn1SccT_Int32 *OUT_p1
);
void sender011_RI_PI_1_SR20(
      asn1SccT_Int32 *OUT_p1
)
{
   // When no destination is specified, send to everyone (multicast)
   sender011_RI_PI_1_SR20_To_PID(PID_env, OUT_p1
);
}

void sender011_RI_PI_1_SR20_To_PID(asn1SccPID dest_pid, 
      asn1SccT_Int32 *OUT_p1
)
{

   size_t      size_OUT_buf_p1 = 0;

   // Send the message via the middleware API
   extern void vm_sender011_pi_1_sr20
     (asn1SccPID,
      void *, size_t *);

   vm_sender011_pi_1_sr20
     (dest_pid,
      (void *)OUT_p1, &size_OUT_buf_p1);


  sender011_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void sender011_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void sender011_get_sender(asn1SccPID *sender_pid);
  sender011_get_sender(sender_pid);
}

void sender011_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = sender011_recent_error;
}

void sender011_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    sender011_RI_get_last_error(err);
}

