#include "teststart00.h"
#include "../../../../../kispe_common/uart_comms.h"
#include <stdio.h>
#include <string.h>

// Temp for gcov testing
#include <gcov.h>
#include <stdlib.h>
static void gcov_dump (void);
// End temp for gcov testing

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
    //teststart00_RI_pi_sp_if( );

    // Dump gcov data
    gcov_dump();
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


// Gcov temp ---------------------------------------

/*
void __gcov_exit(void)
{
    transmit_bytes_over_uart("[__gcov_exit]");
    return;
}
*/

extern const struct gcov_info *__gcov_info_start[];
extern const struct gcov_info *__gcov_info_end[];

static const unsigned char ascii_a = 'a';


/*
  Binary to HEX encoder.
  Each 8bit binary data value c gets encoded into two characters, each in range '0'-'f'
*/
void byte_to_hex(unsigned char c, char buf[3])
{
    static const char hex[] = "0123456789abcdef";
    if (c > 255) {
        buf[0] = '_';
        buf[1] = '_';
    } else {
        buf[0] = hex[(c >> 4) & 0x0F];  // high nibble
        buf[1] = hex[c & 0x0F];         // low nibble
    }
}

static void gcov_dump_binary_data (const void *d, unsigned n, void *arg)
{
    // Create a 3 character buffer, such that we can store two hex digits (ASCII codes) and a trailing NULL
    char aTmp[3] = {0};
    const unsigned char *c = d;

    // Iterate over each byte value
    for (unsigned int i = 0; i < n; ++i)
    {
        // Convert byte value into HEX ASCII encoding, and transmit over the wire
        byte_to_hex(c[i], aTmp);
        transmit_bytes_over_uart(aTmp);
    }
}


static void gcov_dump_filename (const char *f, void *arg)
{
    // This function takes the filename as input, and is called by __gocv_info_to_gcda
    char *leaf_name = strrchr(f, '/');
    if (leaf_name) {
        leaf_name++;      // move past the '/'
    } else {
        leaf_name = f; // no '/' found
    }
    transmit_bytes_over_uart("GCDA_FILENAME:");
    transmit_bytes_over_uart(leaf_name);
    transmit_bytes_over_uart("\nGCDA_HEX:");
}


/* The __gcov_info_to_gcda() function may have to allocate memory under certain conditions, but this seems to never be the case for TASTE RTEMS.
 Nevertheless we leave the function implemented and available for now */

static void * gov_allocate (unsigned length, void *arg)
{
    (void)arg;
    return malloc (length);
}

static void gcov_dump(void)
{
    const struct gcov_info **info = __gcov_info_start;
    const struct gcov_info **end = __gcov_info_end;

    /* Obfuscate variable to prevent compiler optimizations.  */
    __asm__ ("" : "+r" (info));

    while (info != end)
    {
        void *arg = NULL;
        __gcov_info_to_gcda (*info, gcov_dump_filename, gcov_dump_binary_data, gov_allocate, arg);
        transmit_bytes_over_uart("\n");
        ++info;
    }
    transmit_bytes_over_uart("-----------------------------------------------\n");
}


