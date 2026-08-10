#ifndef teststart00_samrh71rx_INCLUDED
#define teststart00_samrh71rx_INCLUDED

#include <stdint.h>
#include <rtems.h>

#include "request_size.h"
#include <dataview-uniq.h>
#include <routing.h>

struct ThreadTeststart00_Samrh71rxRequest
{
    uint32_t m_sender_pid;
    uint32_t m_length;
    uint8_t m_data[TESTSTART00_SAMRH71RX_REQUEST_SIZE] __attribute__((aligned(16)));
};

rtems_task teststart00_samrh71rx_job(rtems_task_argument unused);

#endif // teststart00_samrh71rx_INCLUDED
