#include "teststart00.h"
#include "../../../../../kispe_common/uart_comms.h"
#include <stdio.h>
#include <string.h>

static asn1SccT_UInt8 iCurrentValue = 0;


void teststart00_startup(void)
{
    // Nothing to do
    register_uart_byte_transmitter_function(teststart00_RI_samrh71tx);
    return;
}

void teststart00_PI_PI_1_CYCLIC( void )
{
    // Send example test results over uart
    if (iCurrentValue++ % 2 == 0) {
        report_test_result_over_uart("Test59987987", false, "Spiggots have mice");
    } else {
        report_test_result_over_uart("Test3333", true, "Never see this");
    }

    // Run a sample test
    teststart00_RI_pi_sp_if( );
}

void teststart00_PI_samrh71rx( const asn1SccT_UInt8 * iIN_RxValue)
{
    // Store the provided byte as our new value
    iCurrentValue = (*iIN_RxValue) + 5;
}

/*
 *
 *  TEMP: Place common code here til we can solve the make file includes issue
 *
 */
static void (*pMainByteTransmitterFunction)(const asn1SccT_UInt8*);

void register_uart_byte_transmitter_function(void (*pByteTransmitterFunction)(const asn1SccT_UInt8*))
{
    pMainByteTransmitterFunction = pByteTransmitterFunction;
}
void transmit_bytes_over_uart(char* pBytes)
{
    unsigned long charBuff;
    for (unsigned long i=0; i<strlen(pBytes); i++)
    {
        charBuff = pBytes[i];
        pMainByteTransmitterFunction(&charBuff);
    }
}

void report_test_result_over_uart(char* pTestId, bool bIsPass, char* pFailReason)
{
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
