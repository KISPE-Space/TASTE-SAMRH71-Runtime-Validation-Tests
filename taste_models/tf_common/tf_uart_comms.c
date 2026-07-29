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


