#include "thread_teststart00_samrh71rx.h"

#include <rtems.h>
#include <assert.h>
#include "interfaces_info.h"
#include <Hal.h>
#include <ThreadsCommon.h>

#include "partition_1_interface.h"

extern rtems_id teststart00_samrh71rx_Global_Queue;

rtems_task teststart00_samrh71rx_job(rtems_task_argument unused)
{

    for(;;)
    {
        size_t messageSize = 0;
        struct ThreadTeststart00_Samrh71rxRequest request = {0};
        rtems_status_code result = rtems_message_queue_receive(teststart00_samrh71rx_Global_Queue,
                                                               &request,
                                                               &messageSize,
                                                               RTEMS_WAIT,
                                                               RTEMS_NO_TIMEOUT);

        if(result == RTEMS_SUCCESSFUL)
        {
            teststart00_samrh71rx_sender_pid = (asn1SccPID)request.m_sender_pid;

            ThreadsCommon_ProcessRequest((char*)request.m_data, request.m_length,
                                         (void (*)(const char *,size_t))call_teststart00_samrh71rx, teststart00_samrh71rx);
        }
    }
}
