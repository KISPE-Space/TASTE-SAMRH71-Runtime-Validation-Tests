/***********************************************************************************
 *  @file tf_coverage.c
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

#include <gcov.h>
#include <stdlib.h>
#include <string.h>
#include "tf_uart_comms.h"


extern const struct gcov_info *__gcov_info_start[];
extern const struct gcov_info *__gcov_info_end[];



/*
  Binary to HEX encoder.
  Each 8bit binary data value c gets encoded into two characters, each in range '0'-'f'
*/
static void coverage_byte_to_hex(unsigned char c, char buf[3])
{
    static const char hex[] = "0123456789abcdef";
    buf[0] = hex[(c >> 4) & 0x0F];  // high nibble
    buf[1] = hex[c & 0x0F];         // low nibble
}


/*
 * Transmits a block of GCDA data over the wire, encoding bytes into HEX for easier parsing of
 * the full data stream at the other end
 */
static void coverage_transmit_binary_data (const void *d, unsigned n, void *arg)
{
    // Create a 3 character buffer, such that we can store two hex digits (ASCII codes) and a trailing NULL
    char aTmp[3] = {0};
    const unsigned char *c = d;

    // Iterate over each byte value
    for (unsigned int i = 0; i < n; ++i)
    {
        // Convert byte value into HEX ASCII encoding, and transmit over the wire
        coverage_byte_to_hex(c[i], aTmp);
        transmit_bytes_over_uart(aTmp);
    }
}


/*
 * This function takes the filename as input, and is called by __gocv_info_to_gcda
 */
static void coverage_transmit_filename (const char *f, void *arg)
{
    // Remove all the path elements from the provided string, keeping onlythe leaf filename
    char *leaf_name = strrchr(f, '/');
    if (leaf_name) {
        leaf_name++;      // move past the '/'
    } else {
        leaf_name = (char*)f; // no '/' found
    }

    // Transmit this filename on its own row
    transmit_bytes_over_uart("GCDA_FILENAME:");
    transmit_bytes_over_uart(leaf_name);
    transmit_bytes_over_uart("\nGCDA_HEX:");
}


/*
 * The __gcov_info_to_gcda() function may have to allocate memory under certain conditions, but this seems to never be the case for TASTE RTEMS.
 * Nevertheless we leave the function implemented and available for now
 */
static void * coverage_allocate(unsigned length, void *arg)
{
    (void)arg;
    return malloc(length);
}


/*
 * Similar to gcov_dump on other systems. Dumps all currently collected per-object coverage metrics over UART.
 */
void coverage_transmit_all(void)
{
    // Pull in the start and end addresses where we find the object data pointers
    const struct gcov_info **info = __gcov_info_start;
    const struct gcov_info **end = __gcov_info_end;

    /* Obfuscate variable to prevent compiler optimizations.  */
    __asm__ ("" : "+r" (info));

    // Report the start of the GCDA section
    transmit_bytes_over_uart("COVERAGE_DATA_START\n");

    // Iterate over all gcov_info structs with pointers in the __gcov_info section of RAM
    while (info != end)
    {
        void *arg = NULL;

        // Call gcov's magic function that does the heavy lifting for this object's coverage metrics, passing in
        // functions for transmitting the filename, transmitting gcda data blocks, and a dummy placeholder for
        // an "allocate" function (never gets called)
        __gcov_info_to_gcda (*info, coverage_transmit_filename, coverage_transmit_binary_data, coverage_allocate, arg);

        // Finish this object's GCDA row with a new line
        transmit_bytes_over_uart("\n");

        // Increment to the object's next gcov_info struct
        ++info;
    }

    // Report the end of the GDA section
    transmit_bytes_over_uart("COVERAGE_DATA_END\n\n\n");
}


