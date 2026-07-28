#include <stdio.h>
#include <string.h>
#include "uart_comms.h"

#define TEST_RESULT_BUFFER_SIZE 200
#define MAX_LENGTH_FAIL_REASON 170

/*
 * Private attributes
 */
static void (*pMainByteTransmitterFunction)(const unsigned long*);


/* Functions ------------------------------------ */


/*
 * Refer to header for function usage docs
 */
void register_uart_byte_transmitter_function(void (*pByteTransmitterFunction)(const unsigned long*))
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
void testresult_report_result(char* pTestId, int iPassOrFail, char* pFailReason)
{
    char aTestResultLine[TEST_RESULT_BUFFER_SIZE];

    // If fail reason longer than 170 bytes, replace end with an ellipsis
    if (strlen(pFailReason) > MAX_LENGTH_FAIL_REASON) {
        sprintf(pFailReason + MAX_LENGTH_FAIL_REASON - 4, "%s", "...");
        pFailReason[MAX_LENGTH_FAIL_REASON] = NULL;
    }

    // Compose the line
    if (TEST_PASS == iPassOrFail) {
        sprintf(aTestResultLine, "TEST_RESULT:%s:PASS:\n", pTestId);
    } else {
        sprintf(aTestResultLine, "TEST_RESULT:%s:FAIL:%s\n", pTestId, pFailReason);
    }

    // Transmit the line
    transmit_bytes_over_uart(aTestResultLine);
}

/*
 * Refer to header for function usage docs
 */
void testresult_report_pass(char* pTestId)
{
    return testresult_report_result(pTestId, TEST_PASS, NULL);
}

/*
 * Refer to header for function usage docs
 */
void testresult_report_fail(char* pTestId, char* pFailReason)
{
    return testresult_report_result(pTestId, TEST_FAIL, pFailReason);
}



