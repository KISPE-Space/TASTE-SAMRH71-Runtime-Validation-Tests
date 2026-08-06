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
static void (*pMainByteTransmitterFunction)(const unsigned int*);


/* Functions ------------------------------------ */


/*
 * Refer to header for function usage docs
 */
void register_uart_byte_transmitter_function(void (*pByteTransmitterFunction)(const unsigned int*))
{
    pMainByteTransmitterFunction = pByteTransmitterFunction;
}

/*
 * Refer to header for function usage docs
 */
void transmit_bytes_over_uart(char* pBytes)
{
    unsigned long charBuff;
    for (unsigned long i=0; i<strlen(pBytes); i++)
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
