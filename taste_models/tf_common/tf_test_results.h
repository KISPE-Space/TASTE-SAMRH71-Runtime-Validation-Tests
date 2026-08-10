/***********************************************************************************
 *  @file tf_test_results.h
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

#ifndef TF_TEST_RESULTS_H
#define TF_TEST_RESULTS_H

/*
 * Definitions for test result pass / fail codes
 * We do not use any "bool" type since in general all TASTE models should have a well defined asn.1 bool type,
 * but this lib code exists outside the models and cannot use that same type. So this lib uses old class C style 
 * integer values for pass/fail.
 */
#define TEST_PASS    1
#define TEST_FAIL    0


/*
 * Enumeration of test identifiers
 */
typedef enum {
    TF_TEST_ID__TestMaxTasks        = 0,
    TF_TEST_ID__TestTime            = 1,
    TF_TEST_ID__TestComms01         = 2,
    TF_TEST_ID__TestPriority        = 3,
    TF_TEST_ID__UNUSED              = 4,
    TF_TEST_ID__TestParameterCount  = 5,
    TF_TEST_ID__TestEncodingErrors  = 6,
    TF_TEST_ID__TestFpu             = 7,
    TF_TEST_ID__TestSdlToAda        = 8,
    TF_TEST_ID__TestComms09         = 9,
    TF_TEST_ID__TestEncoding        = 10,
    TF_TEST_ID__TestQueueOverflow   = 11,    
    TF_TEST_ID__TestMaxMatrix       = 12,
    TF_TEST_ID__TestSdlTimer        = 13,
    TF_TEST_ID__TestStacks          = 14,
    TF_TEST_ID__TestMonitoring      = 15,
    TF_TEST_ID__TestBootReason      = 16,
    TF_TEST_ID__TestBswLaunch       = 17,
    TF_TEST_ID__TestCpuFreqDefault  = 18,
    TF_TEST_ID__TestCpuFreqCustom   = 19,
    TF_TEST_ID__TestQueues          = 20,
    TF_TEST_ID__TestDecodingErrors  = 21,
    TF_TEST_ID__TestActivityLog     = 22,
    TF_TEST_ID__TestLongerLog       = 23,
    TF_TEST_ID__TestMaxFunctions    = 24,
    TF_TEST_ID__TestCpuFreqNone     = 25,

    TF_TEST_ID__FIRST               = TF_TEST_ID__TestMaxTasks,
    TF_TEST_ID__LAST                = TF_TEST_ID__TestCpuFreqNone,
    TF_TEST_ID__COUNT               = TF_TEST_ID__LAST + 1
} TF_TestId;


/*** PUBLIC FUNCTIONS -------------------------------------------------------------------------------------------------- */

/*
 * Registers a test with this object.
 * The TF_Reporter TASTE Function will only transmit coverage data once all test results have been submitted to this
 * object for each registered test.
 *
 * Usage examples:
 *   testresult_register_test(TF_TEST_ID__TestMaxTasks);
 */
void testresult_register_test(TF_TestId eTestId);


/*
 * Reports a test PASS over the UART channel.
 * Convenience function for testresult_report_result.
 * 
 * Parameters:
 *   eTestId: The test identifier for the test that passed.
 * 
 * Usage example:
 *   testresult_report_pass(TF_TEST_ID__TestMaxTasks);
 */
void testresult_report_pass(TF_TestId eTestId);


/*
 * Reports a test FAIL over the UART channel.
 * Convenience function for testresult_report_result.
 * 
 * Parameters:
 *   eTestId: The test identifier for the test that failed.
 *   pFailReason: A string describing the reason for the test failure. This string will be truncated to a maximum length of 170 characters if it exceeds that length.
 * 
 * Usage example:
 *   testresult_report_fail(TF_TEST_ID__TestComms01, "Received integer not as expected");
 */
void testresult_report_fail(TF_TestId eTestId, char* pFailReason);


/*
 * Sets the timeout for test results. If a test result is not received within this time, the test result object
 * will consider the test to have failed due to timeout and report ist as such.
 * The timeout is specified in milliseconds.
 *
 * Usage example:
 *   testresult_set_timeout(5000); // Set timeout to 5000 milliseconds (5 seconds)
 */
void testresult_set_timeout(int iTimeoutMs);


/*
 * Reports the result of a test over the UART channel. The test result is sent as string encoded into a sequence of bytes, 
 * including the test name, the result ("PASS"/"FAIL"), and, for failed tests, the failure reason.
 * 
 * Parameters:
 *   eTestId: The test identifier for the test being reported.
 *   iPassOrFail: An integer indicating whether the test passed (TEST_PASS) or failed (TEST_FAIL).
 *   pFailReason: A null-terminated string describing the reason for the test failure. This parameter is only relevant if iPassOrFail is TEST_FAIL; otherwise, 
 *     it can be NULL or an empty string.
 *
 * Usage examples:
 *   testresult_report_result(TF_TEST_ID__TestMaxTasks, TEST_PASS, "");
 *   testresult_report_result(TF_TEST_ID__TestComms01, TEST_FAIL, "Received integer not as expected");
 */
void testresult_report_result(TF_TestId eTestId, int iPassOrFail, char* pFailReason);


/*
 * Finalises the test results reporting process. This function should be called periodically.
 * It checks if all registered tests have reported their results and, if so, transmits the
 * coverage data over the UART channel. If not all tests have reported results, it does nothing
 * unless the timeout has elapsed, in which case it reports a failure for any tests that have not reported results.
 */
void testresult_finalise_when_done(void);


#endif // TF_TEST_RESULTS_H
