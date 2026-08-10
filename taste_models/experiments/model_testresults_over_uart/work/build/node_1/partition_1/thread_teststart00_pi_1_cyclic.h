#ifndef teststart00_PI_1_CYCLIC_INCLUDED
#define teststart00_PI_1_CYCLIC_INCLUDED

#include <stdint.h>
#include <rtems.h>

#include "request_size.h"
#include <dataview-uniq.h>
#include <routing.h>

struct ThreadTeststart00_Pi_1_CyclicRequest
{
    uint32_t m_sender_pid;
    uint32_t m_length;
    uint8_t m_data[TESTSTART00_PI_1_CYCLIC_REQUEST_SIZE] __attribute__((aligned(16)));
};

rtems_task teststart00_pi_1_cyclic_job(rtems_task_argument unused);

#endif // teststart00_PI_1_CYCLIC_INCLUDED
