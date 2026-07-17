/**
 * This folder needs including in each project's Makefile, using (at least) the following additional line:
 *
 * export PARTITION_1_EXTERNAL_SOURCE_PATH=/home/taste/work/kispe_common/
 */
#include "uart_comms.h"
#include <string.h>
#include <stdio.h>


/**
 * Name of the model-wide function used for sending a single byte over the UART.
 * This function relates to the sporadic interface on the TX side of the UART channel.
 * 
 * Note: The type "asn1SccT_UInt8" used within models is defined outside of models only in ASN.1/ACN definitions, 
 * i.e. in $(HOME)/tool-inst/share/taste-types/taste-types.asn. However, to get a C header, you need to process 
 * that using ASN1SCC, which is done automatically by TASTE in case of a TASTE project. Since such a header is 
 * not generally available outside of models (TASTE projects) we use the type that is a close match to the ASN.1 type,
 * which is in fact "unsigned long"
 */
static void (*pMainByteTransmitterFunction)(const unsigned long*) = NULL;


/**
 * Refer to header for function usage docs 
 */
void register_uart_byte_transmitter_function(void (*pByteTransmitterFunction)(const unsigned long*))
{
    pMainByteTransmitterFunction = pByteTransmitterFunction;
}

/**
 * Refer to header for function usage docs 
 */
void transmit_bytes_over_uart(char* pBytes)
{
    // Do nothing if the byte transmitter function has not been registered
    if (pMainByteTransmitterFunction == NULL) {
        return;
    }

    // Send each character in the string as a byte over the UART channel
    unsigned long charBuff;
    for (unsigned long i=0; i<strlen(pBytes); i++) {
        charBuff = pBytes[i];
        pMainByteTransmitterFunction(&charBuff);
    }
}

/**
 * Refer to header for function usage docs 
 */
void report_test_result_over_uart(char* pTestId, bool bIsPass, char* pFailReason)
{
    // Do nothing if the byte transmitter function has not been registered
    if (pMainByteTransmitterFunction == NULL) {
        return;
    }

    // Compose the test result message and send it over the UART channel
    char aTestIdBuff[100];
    char aFailReasonBuff[200];
    sprintf(aTestIdBuff, "<TEST_ID>%s\n", pTestId);
    transmit_bytes_over_uart(aTestIdBuff);
    if (bIsPass) {
        transmit_bytes_over_uart("<TEST_RESULT>PASS\n");
    } else {
        transmit_bytes_over_uart("<TEST_RESULT>FAIL\n");
        sprintf(aFailReasonBuff, "<TEST_FAIL_REASON>%s\n", pFailReason);
        transmit_bytes_over_uart(aFailReasonBuff);
    }
}
