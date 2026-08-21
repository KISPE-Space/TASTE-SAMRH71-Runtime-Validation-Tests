#!/usr/bin/env python3

import serial
import sys
import time
from termcolor import cprint

# Assert that we have exactly one command line argument - the numerical ordinal of the USB port tty device (e.g. "0" for /dev/ttyUSB0)
if len(sys.argv) < 2:
	print("Usage: python3 uart_listener.py <USB-port-numerical-ordinal>")
	sys.exit(1)
port=f"/dev/ttyUSB{sys.argv[1]}"

last_sent_at = time.time()
last_sent_byte = 0
INCREMENT_BYTE_BY = 5
SEND_INTERVAL_SECONDS = 4

# Open the port and listen for bytes
with serial.Serial(port=port, baudrate=115200, bytesize=serial.EIGHTBITS, stopbits=serial.STOPBITS_ONE, parity=serial.PARITY_EVEN, xonxoff=False, timeout=1) as ser:
	while True:
		if ser.in_waiting:
			data = ser.read(ser.in_waiting)
			for b in data:
				cprint(chr(b), "cyan", attrs=[], end="")
				sys.stdout.flush()
			time.sleep(0.01)

		# Send a byte every SEND_INTERVAL_SECONDS seconds
		if time.time() - last_sent_at > SEND_INTERVAL_SECONDS:
			last_sent_byte = (last_sent_byte + INCREMENT_BYTE_BY) % 256
			ser.write(bytes([last_sent_byte]))
			last_sent_at = time.time()
			cprint(f"\n> Sent byte: {last_sent_byte} (0x{last_sent_byte:02X})", "yellow", attrs=[])

