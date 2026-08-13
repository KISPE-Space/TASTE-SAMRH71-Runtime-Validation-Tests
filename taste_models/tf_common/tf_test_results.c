/***********************************************************************************
 *  @file tf_test_results.c
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


#include <stdio.h>
#include <string.h>
#include "tf_uart_comms.h"
#include "tf_test_results.h"
#include "tf_coverage.h"
#include <Hal.h>

#define TR__TEST_RESULT_BUFFER_SIZE         200
#define TR__MAX_LENGTH_FAIL_REASON          170
#define TR__MAX_WAIT_FOR_TEST_RESULTS_MS    10000
#define TR__NANOSECONDS_PER_MILLISECOND     1000000

/*
 * Time within which test results must arrive
 */
static unsigned long ulTestResultsTimeoutMs = TR__MAX_WAIT_FOR_TEST_RESULTS_MS;


/*
 * Time at which the last test was registered
 */
static unsigned long ulLastTestRegisteredTimeMs = 0;


/*
 * Array of strings mapping test identifier integers to their corresponding names. This is used to convert the test identifier enum to a string for reporting.
 */
static const char * const aTestNames[TF_TEST_ID__COUNT] =
{
    [TF_TEST_ID__TestMaxTasks]       = "TestMaxTasks",
    [TF_TEST_ID__TestTime]           = "TestTime",
    [TF_TEST_ID__TestComms01]        = "TestComms01",
    [TF_TEST_ID__TestPriority]       = "TestPriority",
    [TF_TEST_ID__TestStackUsage]     = "TestStackUsage",
    [TF_TEST_ID__TestParameterCount] = "TestParameterCount",
    [TF_TEST_ID__TestEncodingErrors] = "TestEncodingErrors",
    [TF_TEST_ID__TestFpu]            = "TestFpu",
    [TF_TEST_ID__TestSdlToAda]       = "TestSdlToAda",
    [TF_TEST_ID__TestComms09]        = "TestComms09",
    [TF_TEST_ID__TestEncoding]       = "TestEncoding",
    [TF_TEST_ID__TestQueueOverflow]  = "TestQueueOverflow",
    [TF_TEST_ID__TestMaxMatrix]      = "TestMaxMatrix",
    [TF_TEST_ID__TestSdlTimer]       = "TestSdlTimer",
    [TF_TEST_ID__TestStackSize]      = "TestStackSize",
    [TF_TEST_ID__TestMonitoring]     = "TestMonitoring",
    [TF_TEST_ID__TestBootReason]     = "TestBootReason",
    [TF_TEST_ID__TestBswLaunch]      = "TestBswLaunch",
    [TF_TEST_ID__TestCpuFreqDefault] = "TestCpuFreqDefault",
    [TF_TEST_ID__TestCpuFreqCustom]  = "TestCpuFreqCustom",
    [TF_TEST_ID__TestQueues]         = "TestQueues",
    [TF_TEST_ID__TestDecodingErrors] = "TestDecodingErrors",
    [TF_TEST_ID__TestActivityLog]    = "TestActivityLog",
    [TF_TEST_ID__TestLongerLog]      = "TestLongerLog",
    [TF_TEST_ID__TestMaxFunctions]   = "TestMaxFunctions",
    [TF_TEST_ID__TestCpuFreqNone]    = "TestCpuFreqNone"
};

/*
 * Array that indicates which tests have been registered with this object.
 * Each index corresponds to a test ID, and the value is 1 if the test is registered, or 0 if it is not.
 */
static TF_TestId aRegisteredTests[TF_TEST_ID__COUNT] = { 0 };


/*
 * Array that indicates for which tests we have test results.
 * Each index corresponds to a test ID, and the value is 1 if a result is available, or 0 if it is not.
 */
static int aTestResultsTransmitted[TF_TEST_ID__COUNT] = { 0 };


/*
 * Flag to indicate finalisation has been done
 */
int bFinalisationDone = 0;


/*
 * Private Function declarations
 */
static int testresult_all_registered_tests_have_results(void);
static int testresult_get_count_of_registered_tests(void);


/*
 * PUBLIC FUNCTIONS -------------------------------------------------------------------------------------------------
 */


/*
 * Refer to header for function usage docs
 */
void testresult_register_test(TF_TestId eTestId)
{
    // Ensure that the provided test ID is valid
    if (eTestId < TF_TEST_ID__FIRST || eTestId > TF_TEST_ID__LAST) {
        char error_message[100];
        sprintf(error_message, "ERROR: Invalid test ID provided (%d). Test not registered\n", eTestId);
        transmit_bytes_over_uart(error_message);
        return;
    }

    // Flag this test as registered
    aRegisteredTests[eTestId] = 1;

    // Make a note of the time at which this test was registered
    ulLastTestRegisteredTimeMs = Hal_GetElapsedTimeInNs() / TR__NANOSECONDS_PER_MILLISECOND;

    // Report the test being registered (by name and id)
    char aMsgBuff[100];
    sprintf(aMsgBuff, "Test registered: %s (%d)", aTestNames[eTestId], eTestId);
    transmit_log_info(aMsgBuff);
}


/*
 * Refer to header for function usage docs
 */
void testresult_report_result(TF_TestId eTestId, int iPassOrFail, char* pFailReason)
{
    char aMessageBuff[TR__TEST_RESULT_BUFFER_SIZE];

    // Already finalised? Then do not do anything
    if (bFinalisationDone) {
        return;
    }

    // Ensure that the provided test ID is valid
    if (eTestId < TF_TEST_ID__FIRST || eTestId > TF_TEST_ID__LAST) {
        sprintf(aMessageBuff, "ERROR: Invalid test ID provided (%d). Result not reported\n", eTestId);
        transmit_bytes_over_uart(aMessageBuff);
        return;
    }

    // Not registered? Then ignore this request
    if (aRegisteredTests[eTestId] == 0) {
        sprintf(aMessageBuff, "ERROR: Test result provided for unregistered test %s (%d). Ignoring\n", aTestNames[eTestId], eTestId);
        transmit_bytes_over_uart(aMessageBuff);
        return;
    }

    // Test result already provided? Then ignore this request
    if (aTestResultsTransmitted[eTestId] == 1) {
        sprintf(aMessageBuff, "ERROR: Test result already provided for test %s (%d). Ignoring\n", aTestNames[eTestId], eTestId);
        transmit_bytes_over_uart(aMessageBuff);
        return;
    }

    // If fail reason longer than 170 bytes, replace end with an ellipsis
    if (strlen(pFailReason) > TR__MAX_LENGTH_FAIL_REASON) {
        sprintf(pFailReason + TR__MAX_LENGTH_FAIL_REASON - 4, "%s", "...");
        pFailReason[TR__MAX_LENGTH_FAIL_REASON] = 0;
    }

    // Compose the line
    if (TEST_PASS == iPassOrFail) {
        sprintf(aMessageBuff, "TEST_RESULT:%s:PASS:\n", aTestNames[eTestId]);
    } else {
        sprintf(aMessageBuff, "TEST_RESULT:%s:FAIL:%s\n", aTestNames[eTestId], pFailReason);
    }

    // Transmit the line
    transmit_bytes_over_uart(aMessageBuff);

    // Flag that we submitted a result for this test
    aTestResultsTransmitted[eTestId] = 1;
}


/*
 * Refer to header for function usage docs
 */
void testresult_report_pass(TF_TestId eTestId)
{
    return testresult_report_result(eTestId, TEST_PASS, 0);
}


/*
 * Refer to header for function usage docs
 */
void testresult_report_fail(TF_TestId eTestId, char* pFailReason)
{
    return testresult_report_result(eTestId, TEST_FAIL, pFailReason);
}


/*
 * Refer to header for function usage docs
 */
void testresult_set_timeout(int iTimeoutMs)
{
    ulTestResultsTimeoutMs = iTimeoutMs;

    char sMsgBuff[100];
    sprintf(sMsgBuff, "Test results timeout set to %d ms", iTimeoutMs);
    transmit_log_info(sMsgBuff);
}


/*
 * Refer to header for function usage docs
 */
void testresult_finalise_when_done(void)
{
    // Already finalised? Then do not do anything
    if (bFinalisationDone) {
        return;
    }

    // As long as we have no registered tests, do not do anything
    if (testresult_get_count_of_registered_tests() == 0) {
        transmit_log_info("No registered tests, not finalising test results");
        return;
    }

    // As long as all registered tests have not had results reported, do not do anything
    if (testresult_all_registered_tests_have_results() == 0) {
        //transmit_log_info("Not all registered tests have results, not finalising test results");
        return;
    }

    // All tests submitted results. We can now transmit the GCOV data
#if COVERAGE_ENABLED == 1
    coverage_transmit_all();
#endif

    // Flag that finalisation has been done
    bFinalisationDone = 1;
}


/*
 * PRIVATE FUNCTIONS -------------------------------------------------------------------------------------------------
 */

/*
 * Returns the count of registered tests.
 */
static int testresult_get_count_of_registered_tests(void)
{
    int count = 0;
    for (TF_TestId eTestId = TF_TEST_ID__FIRST; eTestId <= TF_TEST_ID__LAST; eTestId++) {
        if (aRegisteredTests[eTestId] == 1) {
            count++;
        }
    }
    return count;
}


/*
 * Returns 1 if timeout has elapsed, else 0
 */
static int testresult_has_timeout_elapsed(void)
{
    unsigned long ulElapsedTimeMs = (Hal_GetElapsedTimeInNs() / TR__NANOSECONDS_PER_MILLISECOND) - ulLastTestRegisteredTimeMs;
    return (ulElapsedTimeMs > ulTestResultsTimeoutMs);
}


/*
 * Returns 1 if all registered tests have had results reported, 0 otherwise.
 */
static int testresult_all_registered_tests_have_results(void)
{
    // Assume all results reported until proven otherwise
    int bAllResultsReported = 1;

    // Iterate over all test identifiers and check if each registered test has a result reported
    for (TF_TestId eTestId = TF_TEST_ID__FIRST; eTestId <= TF_TEST_ID__LAST; eTestId++) {

        // Not registered? Then skip this test
        if (aRegisteredTests[eTestId] == 0) {
            continue;
        }

        // Test result provided? Then skip this test
        if (aTestResultsTransmitted[eTestId] == 1) {
            continue;
        }

        // Timeout elapsed? Then fail this test
        if (testresult_has_timeout_elapsed()) {
            testresult_report_fail(eTestId, "No result received within timeout period");
            continue;
        }

        // If we got here we found a registered test without a result, and timeout has not yet elapsed, so we cannot consider all results reported
        bAllResultsReported = 0;
    }

    // Return the result
    return bAllResultsReported;
}
