# Very simple software UART for AVR microcontrollers
# (C) 2016 Stuart Longland
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 2 of the License, or (at your
# option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA.


# Cross-compiler definitions
CROSS_COMPILE ?= avr-
CC = $(CROSS_COMPILE)gcc
OBJCOPY = $(CROSS_COMPILE)objcopy

# MCU selection
MCU=attiny24a

# C compiler flags
CFLAGS=-mmcu=$(MCU) -Os

# C preprocessor flags
CPPFLAGS=-DF_CPU=1000000

# Linker flags
LDFLAGS=-mmcu=$(MCU)

# Default target
all: uartdemo.hex

# Clean-up target
clean:
	-rm -fr *.elf *.hex *.o

%.hex: %.elf
	$(OBJCOPY) -O ihex $^ $@

uartdemo.elf: uart.o main.o
	$(CC) $(LDFLAGS) -o $@ $^

uart.o: uart.h uartcfg.h
main.o: uart.h

.PHONY: all clean
