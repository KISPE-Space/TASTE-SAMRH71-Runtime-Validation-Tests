#include "thread_teststart00_pi_1_cyclic.h"

#include <rtems.h>
#include <assert.h>
#include "interfaces_info.h"
#include <Hal.h>
#include <ThreadsCommon.h>

#include "partition_1_interface.h"

extern rtems_id teststart00_pi_1_cyclic_Global_Queue;

rtems_task teststart00_pi_1_cyclic_job(rtems_task_argument unused)
{
    const bool createCyclicRequestStatus = ThreadsCommon_CreateCyclicRequest( 4000 * NANOSECONDS_IN_MILLISECOND,
                                                                              0 * NANOSECONDS_IN_MILLISECOND,
                                                                             teststart00_pi_1_cyclic_Global_Queue,
                                                                             sizeof(struct CyclicInterfaceEmptyRequestData));
    assert(createCyclicRequestStatus);

    for(;;)
    {
        size_t messageSize = 0;
        struct ThreadTeststart00_Pi_1_CyclicRequest request = {0};
        rtems_status_code result = rtems_message_queue_receive(teststart00_pi_1_cyclic_Global_Queue,
                                                               &request,
                                                               &messageSize,
                                                               RTEMS_WAIT,
                                                               RTEMS_NO_TIMEOUT);

        if(result == RTEMS_SUCCESSFUL)
        {
            teststart00_pi_1_cyclic_sender_pid = (asn1SccPID)request.m_sender_pid;

            ThreadsCommon_ProcessRequest((char*)request.m_data, request.m_length,
                                         (void (*)(const char *,size_t))call_teststart00_pi_1_cyclic, teststart00_pi_1_cyclic);
        }
    }
}
