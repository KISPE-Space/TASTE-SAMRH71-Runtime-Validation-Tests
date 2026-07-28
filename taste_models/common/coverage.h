/*
 * Transmits all gcov code line hit counts as gcda data over the UART.
 * Should be called once, after all tests have completed.
 */
void coverage_transmit_all(void);
