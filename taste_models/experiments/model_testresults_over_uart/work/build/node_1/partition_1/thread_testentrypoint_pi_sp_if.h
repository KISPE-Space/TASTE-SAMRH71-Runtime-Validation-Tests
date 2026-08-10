#ifndef testentrypoint_pi_sp_if_INCLUDED
#define testentrypoint_pi_sp_if_INCLUDED

#include <stdint.h>
#include <rtems.h>

#include "request_size.h"
#include <dataview-uniq.h>
#include <routing.h>

struct ThreadTestentrypoint_Pi_Sp_IfRequest
{
    uint32_t m_sender_pid;
    uint32_t m_length;
    uint8_t m_data[TESTENTRYPOINT_PI_SP_IF_REQUEST_SIZE] __attribute__((aligned(16)));
};

rtems_task testentrypoint_pi_sp_if_job(rtems_task_argument unused);

#endif // testentrypoint_pi_sp_if_INCLUDED
