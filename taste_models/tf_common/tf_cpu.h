/***********************************************************************************
 *  @file tf_cpu.h
 ***********************************************************************************
 *   _  _____ ____  ____  _____
 *  | |/ /_ _/ ___||  _ \| ____|
 *  | ' / | |\___ \| |_) |  _|
 *  | . \ | | ___) |  __/| |___
 *  |_|\_\___|____/|_|   |_____|
 *
 ***********************************************************************************
 *  Copyright (c) 2026 KISPE Space Systems Ltd.
 *
 *  All Rights Reserved
 ***********************************************************************************
 *  Created on: 17th-Aug-2026 14:07:16
 *  Implementation of the CPU utilities module
 *  @author: Andy Cowling
 ***********************************************************************************/

#ifndef TF_CPU_H
#define TF_CPU_H

#include <stdbool.h>

/*
 * Returns true if the processor clock is currently configured at 100 MHz, else false
 */
bool is_processor_clock_100mhz(void);


/*
 * Returns true if the floating point unit (FPU) is currently enabled, else false
 */
bool is_fpu_enabled(void);


#endif // TF_CPU_H
