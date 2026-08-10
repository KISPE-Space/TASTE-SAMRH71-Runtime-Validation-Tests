#ifndef uartotherend_samrh71tx_INCLUDED
#define uartotherend_samrh71tx_INCLUDED

#include <stdint.h>
#include <rtems.h>

#include "request_size.h"
#include <dataview-uniq.h>
#include <routing.h>

struct ThreadUartotherend_Samrh71txRequest
{
    uint32_t m_sender_pid;
    uint32_t m_length;
    uint8_t m_data[UARTOTHEREND_SAMRH71TX_REQUEST_SIZE] __attribute__((aligned(16)));
};

rtems_task uartotherend_samrh71tx_job(rtems_task_argument unused);

#endif // uartotherend_samrh71tx_INCLUDED
