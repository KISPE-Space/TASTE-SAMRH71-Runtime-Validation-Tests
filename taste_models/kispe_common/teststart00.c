#include "teststart00.h"
#include "../../../../../kispe_common/uart_comms.h"
#include <stdio.h>
#include <string.h>

static asn1SccT_UInt8 iCurrentValue = 0;


void teststart00_startup(void)
{
    // Register the byte transmitter function
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
    teststart00_RI_PI_start_SPCC06( );
}

void teststart00_PI_samrh71rx( const asn1SccT_UInt8 * iIN_RxValue)
{
    // Store the provided byte as our new value
    iCurrentValue = (*iIN_RxValue) + 5;
}
