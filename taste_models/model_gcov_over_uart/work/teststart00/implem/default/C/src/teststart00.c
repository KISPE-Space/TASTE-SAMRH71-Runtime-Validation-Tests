#include "teststart00.h"
#include "../../../../../tf_common/tf_uart_comms.h"
#include "../../../../../tf_common/tf_test_results.h"
#include "../../../../../tf_common/tf_coverage.h"


/*
 * Used in the demo code for receiving over UART, below
 */
static unsigned long iCurrentValue = 0;


/*
 * Flag to indicate when results have been transmitted. We only want to do that once per run.
 */
static int iResultsTransmitted = 0;


/*
 * Constructor for this TASTE Function
 */
void teststart00_startup(void)
{
    // Register the sporadic interface (C function) over which this model can transmit data out from the target hardware
    register_uart_byte_transmitter_function(teststart00_RI_samrh71tx);
    return;
}


/*
 * Handler for the cyclic interface entry-point for this TASTE Function
 */
void teststart00_PI_PI_1_CYCLIC( void )
{
    // Already done this once? Then do not do this again
    if (iResultsTransmitted) {
        return;
    }


    // TODO: Invoke / allow time for tests to run
    // Note that some tests are triggered by cyclic interfaces, so we just need to give them time to run and
    // report their results. Each test can report its results directly, using similar code to the example below.

    // Send example test results over UART
    testresult_report_fail("Test001", "Spindle no longer aligned within tolerance");
    testresult_report_pass("Test002");
    testresult_report_fail("Test006", "Oxygen level depleted below acceptable limit");

    // Transmit all gcov data over UARTS
    coverage_transmit_all();

    // Set the flag so we don't do this again
    iResultsTransmitted = 1;
}


/*
 * Handler for bytes received over the UART (demo code only)
 */
void teststart00_PI_samrh71rx( const asn1SccT_UInt8 * iIN_RxValue)
{
    // Store the provided byte as our new value
    iCurrentValue = (unsigned long)((*iIN_RxValue) + 5);
}
