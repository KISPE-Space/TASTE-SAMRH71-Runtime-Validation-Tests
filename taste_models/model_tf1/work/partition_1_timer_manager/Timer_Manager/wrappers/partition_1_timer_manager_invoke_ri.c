// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error partition_1_timer_manager_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned partition_1_timer_manager_initialized;

void partition_1_timer_manager_RI_testsdl08_mytime_To_PID(asn1SccPID dest_pid);
void partition_1_timer_manager_RI_testsdl08_mytime(void);
void partition_1_timer_manager_RI_testsdl08_mytime(void)
{
   // When no destination is specified, send to everyone (multicast)
   partition_1_timer_manager_RI_testsdl08_mytime_To_PID(PID_env);
}

void partition_1_timer_manager_RI_testsdl08_mytime_To_PID(asn1SccPID dest_pid)
{


   // Send the message via the middleware API
   extern void vm_partition_1_timer_manager_testsdl08_mytime(asn1SccPID);
   vm_partition_1_timer_manager_testsdl08_mytime(dest_pid);

  partition_1_timer_manager_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void partition_1_timer_manager_RI_testsdl08_mytime_Reset_To_PID(asn1SccPID dest_pid);
void partition_1_timer_manager_RI_testsdl08_mytime_Reset(void);
void partition_1_timer_manager_RI_testsdl08_mytime_Reset(void)
{
   // When no destination is specified, send to everyone (multicast)
   partition_1_timer_manager_RI_testsdl08_mytime_Reset_To_PID(PID_env);
}

void partition_1_timer_manager_RI_testsdl08_mytime_Reset_To_PID(asn1SccPID dest_pid)
{


   // Send the message via the middleware API
   extern void vm_partition_1_timer_manager_testsdl08_mytime_reset(asn1SccPID);
   vm_partition_1_timer_manager_testsdl08_mytime_reset(dest_pid);

  partition_1_timer_manager_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void partition_1_timer_manager_RI_testsdl08_mytime_Set_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt32 *IN_val
);
void partition_1_timer_manager_RI_testsdl08_mytime_Set(
      const asn1SccT_UInt32 *IN_val
);
void partition_1_timer_manager_RI_testsdl08_mytime_Set(
      const asn1SccT_UInt32 *IN_val
)
{
   // When no destination is specified, send to everyone (multicast)
   partition_1_timer_manager_RI_testsdl08_mytime_Set_To_PID(PID_env, IN_val
);
}

void partition_1_timer_manager_RI_testsdl08_mytime_Set_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt32 *IN_val
)
{


   // Send the message via the middleware API
   extern void vm_partition_1_timer_manager_testsdl08_mytime_set
     (asn1SccPID,
      void *, size_t);

   vm_partition_1_timer_manager_testsdl08_mytime_set
     (dest_pid,
      (void *)IN_val, sizeof(asn1SccT_UInt32));


  partition_1_timer_manager_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void partition_1_timer_manager_RI_testsdl14_mytime_To_PID(asn1SccPID dest_pid);
void partition_1_timer_manager_RI_testsdl14_mytime(void);
void partition_1_timer_manager_RI_testsdl14_mytime(void)
{
   // When no destination is specified, send to everyone (multicast)
   partition_1_timer_manager_RI_testsdl14_mytime_To_PID(PID_env);
}

void partition_1_timer_manager_RI_testsdl14_mytime_To_PID(asn1SccPID dest_pid)
{


   // Send the message via the middleware API
   extern void vm_partition_1_timer_manager_testsdl14_mytime(asn1SccPID);
   vm_partition_1_timer_manager_testsdl14_mytime(dest_pid);

  partition_1_timer_manager_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void partition_1_timer_manager_RI_testsdl14_mytime_Reset_To_PID(asn1SccPID dest_pid);
void partition_1_timer_manager_RI_testsdl14_mytime_Reset(void);
void partition_1_timer_manager_RI_testsdl14_mytime_Reset(void)
{
   // When no destination is specified, send to everyone (multicast)
   partition_1_timer_manager_RI_testsdl14_mytime_Reset_To_PID(PID_env);
}

void partition_1_timer_manager_RI_testsdl14_mytime_Reset_To_PID(asn1SccPID dest_pid)
{


   // Send the message via the middleware API
   extern void vm_partition_1_timer_manager_testsdl14_mytime_reset(asn1SccPID);
   vm_partition_1_timer_manager_testsdl14_mytime_reset(dest_pid);

  partition_1_timer_manager_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void partition_1_timer_manager_RI_testsdl14_mytime_Set_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt32 *IN_val
);
void partition_1_timer_manager_RI_testsdl14_mytime_Set(
      const asn1SccT_UInt32 *IN_val
);
void partition_1_timer_manager_RI_testsdl14_mytime_Set(
      const asn1SccT_UInt32 *IN_val
)
{
   // When no destination is specified, send to everyone (multicast)
   partition_1_timer_manager_RI_testsdl14_mytime_Set_To_PID(PID_env, IN_val
);
}

void partition_1_timer_manager_RI_testsdl14_mytime_Set_To_PID(asn1SccPID dest_pid, 
      const asn1SccT_UInt32 *IN_val
)
{


   // Send the message via the middleware API
   extern void vm_partition_1_timer_manager_testsdl14_mytime_set
     (asn1SccPID,
      void *, size_t);

   vm_partition_1_timer_manager_testsdl14_mytime_set
     (dest_pid,
      (void *)IN_val, sizeof(asn1SccT_UInt32));


  partition_1_timer_manager_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void partition_1_timer_manager_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void partition_1_timer_manager_get_sender(asn1SccPID *sender_pid);
  partition_1_timer_manager_get_sender(sender_pid);
}

void partition_1_timer_manager_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = partition_1_timer_manager_recent_error;
}

void partition_1_timer_manager_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    partition_1_timer_manager_RI_get_last_error(err);
}

