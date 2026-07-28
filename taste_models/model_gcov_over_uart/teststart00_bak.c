#include "teststart00.h"
#include "../../../../../kispe_common/uart_comms.h"
#include <stdio.h>
#include <string.h>

// Temp for gcov testing
#include <gcov.h>
#include <stdlib.h>
static void dump_gcov_info (void);
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

    // Hello
    dump_gcov_info();
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
  Binary to ASCII encoder.
  Each 8bit binary data value c gets encoded into two characters, each in range 'a'-'p' (p is 'a'+16):
  buf[0]: 'a' + LowNibble(c)
  buf[1]: 'a' + HighNibble(c)
*/
static inline unsigned char *encode(unsigned char c, unsigned char buf[2]) {
    buf[0] = ascii_a + c % 16;
    buf[1] = ascii_a + (c / 16) % 16;
    return buf;
}

/*
  Binary to HEX encoder.
  Each 8bit binary data value c gets encoded into two characters, each in range '0'-'f'
*/
void byte_to_hex(unsigned char c, char buf[2])
{
    static const char hex[] = "0123456789ABCDEF";
    buf[0] = hex[(c >> 4) & 0x0F];  // high nibble
    buf[1] = hex[c & 0x0F];         // low nibble
}

static void dump (const void *d, unsigned n, void *arg)
{
    char aTmp[2];
    const unsigned char *c = d;

    for (unsigned int i = 0; i < n; ++i)
    {
        byte_to_hex(c[i], aTmp);
        transmit_bytes_over_uart(aTmp);
    }
}


static void filename (const char *f, void *arg)
{
    // This function takes the filename as input, and is called by __gocv_info_to_gcda
    char *leaf_name = strrchr(f, '/');
    if (leaf_name) {
        leaf_name++;      // move past the '/'
    } else {
        leaf_name = f; // no '/' found
    }
    transmit_bytes_over_uart(leaf_name);
    transmit_bytes_over_uart("\n");
}


/* The __gcov_info_to_gcda() function may have to allocate memory under certain conditions, but this seems to never be the case for TASTE RTEMS.
 Nevertheless we leave the function implemented and available for now */

static void * allocate (unsigned length, void *arg)
{
    (void)arg;
    return malloc (length);
}

static void dump_gcov_info (void)
{
    const struct gcov_info **info = __gcov_info_start;
    const struct gcov_info **end = __gcov_info_end;

    // TEMP DEBUG
    char aStartBuff[100];
    char aEndBuff[100];
    char aSizeBuff[100];
    unsigned long count = (unsigned long)end - (unsigned long)info;
    sprintf(aStartBuff, "[__gcov_info_start ] %p\n", info);
    sprintf(aEndBuff,   "[__gcov_info_end   ] %p\n", end);
    sprintf(aSizeBuff,  "[__gcov_info #bytes] %lu\n", count);
    transmit_bytes_over_uart(aStartBuff);
    transmit_bytes_over_uart(aEndBuff);
    transmit_bytes_over_uart(aSizeBuff);

    /* Obfuscate variable to prevent compiler optimizations.  */
    __asm__ ("" : "+r" (info));

    while (info != end)
    {
        void *arg = NULL;
/*
        // Before the call to __gcov_info_to_gcda, report the filename via transmit_bytes_over_uart
        char aFnameBuff[300];
        const struct my_gcov_info *p = (const struct my_gcov_info *)(*info);
        sprintf(aFnameBuff, "[info] %lx ; [p] %li ; [version] %i\n", (long)info, (long)p, p->version);
        transmit_bytes_over_uart(aFnameBuff);

        snprintf(aFnameBuff, 250, "[filename] %s\n",  p->filename);
        transmit_bytes_over_uart(aFnameBuff);
*/
        __gcov_info_to_gcda (*info, filename, dump, allocate, arg);
        transmit_bytes_over_uart("\n");
        ++info;
    }
}


