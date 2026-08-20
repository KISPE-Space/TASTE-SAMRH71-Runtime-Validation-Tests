/***********************************************************************************
 *  @file tf_uart_comms.c
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
 *  Created on: 6th-Aug-2026 14:07:16                      
 *  Implementation of the Test Results Module       
 *  @author: Andy Cowling
 ***********************************************************************************/

#include <stdio.h>
#include <string.h>
#include "tf_uart_comms.h"

/*
 * Private attributes
 */
static void (*pMainByteTransmitterFunction)(const unsigned int*) = 0;


/* Functions ------------------------------------ */


/*
 * Refer to header for function usage docs
 */
void register_uart_byte_transmitter_function(void (*pByteTransmitterFunction)(const unsigned int*))
{
    // Do not do this if already set
    if (pMainByteTransmitterFunction != 0) {
        transmit_log_info("ERROR: Attempt to register UART byte transmitter function when one is already registered. Ignoring");
        return;
    }

    // Register the function pointer
    pMainByteTransmitterFunction = pByteTransmitterFunction;
}

/*
 * Refer to header for function usage docs
 */
void transmit_bytes_over_uart(char* pBytes)
{
    // Do not do this if not yet set
    if (pMainByteTransmitterFunction == 0) {
        return;
    }

    // Iterate over characters in the buffer
    unsigned long charBuff;             // Under the hood TASTE is defaulting to using four bytes for a T-Uint8. Using an unsigned long here to match that default.
    for (int i=0; i<strlen(pBytes); i++)
    {
        charBuff = pBytes[i];
        pMainByteTransmitterFunction(&charBuff);
    }
}


/*
 * Refer to header for function usage docs
 */
void transmit_log_info(char* pString)
{
    transmit_bytes_over_uart("INFO:");
    transmit_bytes_over_uart(pString);
    transmit_bytes_over_uart("\n");
}


/*
 * Refer to header for function usage docs
 */
void transmit_end_signal(void)
{
    transmit_bytes_over_uart("END_OF_OUTPUT\n\n");
}


/*
 * Refer to header for function usage docs
 */
void transmit_reset_signal(void)
{
    transmit_bytes_over_uart("RESET_AND_RERUN\n");
    transmit_end_signal();
}
