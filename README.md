Simple transmit-only UART driver
================================

This is a very simple C-based transmit-only UART, good for low speeds up to 4800
baud when used with a 1MHz clock.

The intent of this is to provide a simple console output for debugging code on
small ATTiny-series microcontroller, but in theory should work on any AVR chip.

The only requirements are a single GPIO pin that will serve as the transmit out.

The code is 100% C code and requires no interrupts or timers.  As such, it
might be prudent to call `cli()` before these routines and restore interrupts
with `sei()` later as the code is not guaranteed to behave if interrupts steal
too much CPU time.

Usage
-----

Usage is pretty simple.  The configuration settings are set in `uartcfg.h`.
Adjust these for your project, and in your code, include `uart.h`.

Call `uart_init()` somewhere in your hardware initialisation, and you should
be set to send short strings to the UART for debugging purposes.
