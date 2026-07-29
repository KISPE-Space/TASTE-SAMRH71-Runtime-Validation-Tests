/*
 * Definitions for test result pass / fail codes
 */
#define TEST_PASS    1
#define TEST_FAIL    0

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
