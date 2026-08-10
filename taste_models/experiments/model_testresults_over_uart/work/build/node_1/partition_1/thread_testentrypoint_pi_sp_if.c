#include "thread_testentrypoint_pi_sp_if.h"

#include <rtems.h>
#include <assert.h>
#include "interfaces_info.h"
#include <Hal.h>
#include <ThreadsCommon.h>

#include "partition_1_interface.h"

extern rtems_id testentrypoint_pi_sp_if_Global_Queue;

rtems_task testentrypoint_pi_sp_if_job(rtems_task_argument unused)
{

    for(;;)
    {
        size_t messageSize = 0;
        struct ThreadTestentrypoint_Pi_Sp_IfRequest request = {0};
        rtems_status_code result = rtems_message_queue_receive(testentrypoint_pi_sp_if_Global_Queue,
                                                               &request,
                                                               &messageSize,
                                                               RTEMS_WAIT,
                                                               RTEMS_NO_TIMEOUT);

        if(result == RTEMS_SUCCESSFUL)
        {
            testentrypoint_pi_sp_if_sender_pid = (asn1SccPID)request.m_sender_pid;

            ThreadsCommon_ProcessRequest((char*)request.m_data, request.m_length,
                                         (void (*)(const char *,size_t))call_testentrypoint_pi_sp_if, testentrypoint_pi_sp_if);
        }
    }
}
