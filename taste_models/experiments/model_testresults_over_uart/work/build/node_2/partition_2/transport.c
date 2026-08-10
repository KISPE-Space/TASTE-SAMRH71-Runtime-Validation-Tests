#include "transport.h"

#include <rtems.h>
#include <interfaces_info.h>
#include <ThreadsCommon.h>

// Sporadic required
void deliver_to_teststart00_samrh71rx(
   const asn1SccPID sender_pid,
   const uint8_t* const data,
   const size_t length)
{
    Broker_deliver_request(
            INTERFACE_TESTSTART00_SAMRH71RX,
            sender_pid,
            data,
            length);
}

// Sporadic provided

#include "thread_uartotherend_samrh71tx.h"

#include <string.h>

void deliver_to_uartotherend_samrh71tx(const asn1SccPID sender_pid, const uint8_t* const data, const size_t length)
{
    extern rtems_id uartotherend_samrh71tx_Global_Queue;

    struct ThreadUartotherend_Samrh71txRequest request = {0};
    if(length > 0)
    {
        memcpy(request.m_data, data, length);
    }
    request.m_length = length;
    request.m_sender_pid = (uint32_t)sender_pid;

    ThreadsCommon_SendRequest(&request,
                              sizeof(struct ThreadUartotherend_Samrh71txRequest),
                              uartotherend_samrh71tx_Global_Queue,
                              uartotherend_samrh71tx);
}



void initialize_transport()
{
    interface_to_deliver_function[INTERFACE_UARTOTHEREND_SAMRH71TX] = &deliver_to_uartotherend_samrh71tx;
}
