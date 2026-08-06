/***********************************************************************************
 *  @file tf_coverage.h
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
 *  Implementation of the Coverage Module
 *  @author: Andy Cowling
 ***********************************************************************************/

#ifndef TF_COVERAGE_H
#define TF_COVERAGE_H

/**
 * Transmits all gcov code line hit counts as gcda data over the UART.
 * Should be called once, after all tests have completed.
 */
void coverage_transmit_all(void);

#endif // TF_COVERAGE_H