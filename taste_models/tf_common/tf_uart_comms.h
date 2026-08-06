/***********************************************************************************
 *  @file tf_uart_comms.h
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
 *  Implementation of the UART Comms Module
 *  @author: Andy Cowling
 ***********************************************************************************/

#ifndef TF_UART_COMMS_H
#define TF_UART_COMMS_H


/*
 * Registers a function name that can be used to transmit a single byte over the UART. This function is called by
 * the "transmit_bytes_over_uart" function.
 *
 * The function to be registered must have the following signature:
 * void function_name(const unsigned long* pByteToTransmit)
 * where the parameter is a pointer to an unsigned long that contains the byte to be transmitted.
 *
 * The function must be able to transmit the byte over the UART channel.
 * The function must be registered before any calls to "transmit_bytes_over_uart" are made.
 * The function must be registered before any calls to "report_test_result_over_uart" are made *
 *
 * Usage example:
 *  register_uart_byte_transmitter_function(teststart00_RI_samrh71tx);
 */
void register_uart_byte_transmitter_function(void (*pByteTransmitterFunction)(const unsigned int*));

/*
 * Transmits a sequence of bytes over the UART channel, using the previously registered function for sending a single byte.
 * The input is a null-terminated string, and each character in the string is sent as a byte over the UART channel.
 */
void transmit_bytes_over_uart(char* pBytes);


/*
 * Transmits a string encapsulated as a general log message
 */
void transmit_log_info(char* pString);


#endif // TF_UART_COMMS_H