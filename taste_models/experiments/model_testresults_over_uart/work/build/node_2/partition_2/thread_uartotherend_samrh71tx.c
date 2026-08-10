#include "thread_uartotherend_samrh71tx.h"

#include <rtems.h>
#include <assert.h>
#include "interfaces_info.h"
#include <Hal.h>
#include <ThreadsCommon.h>

#include "partition_2_interface.h"

extern rtems_id uartotherend_samrh71tx_Global_Queue;

rtems_task uartotherend_samrh71tx_job(rtems_task_argument unused)
{

    for(;;)
    {
        size_t messageSize = 0;
        struct ThreadUartotherend_Samrh71txRequest request = {0};
        rtems_status_code result = rtems_message_queue_receive(uartotherend_samrh71tx_Global_Queue,
                                                               &request,
                                                               &messageSize,
                                                               RTEMS_WAIT,
                                                               RTEMS_NO_TIMEOUT);

        if(result == RTEMS_SUCCESSFUL)
        {
            uartotherend_samrh71tx_sender_pid = (asn1SccPID)request.m_sender_pid;

            ThreadsCommon_ProcessRequest((char*)request.m_data, request.m_length,
                                         (void (*)(const char *,size_t))call_uartotherend_samrh71tx, uartotherend_samrh71tx);
        }
    }
}
