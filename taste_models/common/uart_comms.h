/*
 * Definitions for test result pass / fail codes
 */
#define TEST_PASS    1
#define TEST_FAIL    0

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
void register_uart_byte_transmitter_function(void (*pByteTransmitterFunction)(const unsigned long*));

/*
 * Transmits a sequence of bytes over the UART channel, using the previously registered function for sending a single byte.
 * The input is a null-terminated string, and each character in the string is sent as a byte over the UART channel.
 */
void transmit_bytes_over_uart(char* pBytes);

/*
 * Reports the result of a test over the UART channel. The test result is sent as a sequence of bytes, including the test ID,
 * the result (pass/fail), and an optional failure reason.
 * The test ID and failure reason are sent as null-terminated strings, while the result is sent as a boolean indicating pass (true)
 * or fail (false).
 *
 * Usage examples:
 *   report_test_result_over_uart("Test001", TEST_PASS, "");
 *   report_test_result_over_uart("Test002", TEST_FAIL, "Received integer not as expected");
 */
void testresult_report_result(char* pTestId, int iPassOrFail, char* pFailReason);

/*
 * Convenience function for reporting a test pass
 */
void testresult_report_pass(char* pTestId);


/*
 * Convenience function for reporting a test fail
 */
void testresult_report_fail(char* pTestId, char* pFailReason);
