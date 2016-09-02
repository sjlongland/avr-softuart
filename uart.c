/*!
 * Very simple software UART for AVR microcontrollers
 * (C) 2016 Stuart Longland
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA.
 */

#include "uart.h"
#include "uartcfg.h"

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/pgmspace.h>

#define TX_BIT	(1 << UART_TX_BIT)

#define BIT_US	(1000000/UART_BAUD)	/*!< Bit period in microseconds */

/*!
 * Configure the UART pins.
 */
void uart_init() {
	UART_TX_DDR	|= TX_BIT;
	UART_TX_PORT	|= TX_BIT;
}

/*!
 * Send a raw byte to the UART.
 */
void uart_tx(uint8_t byte) {
	uint8_t mask = 1;
	/* Start bit */
	UART_TX_PORT &= ~TX_BIT;	_delay_us(BIT_US);
	while(mask) {
		if (mask & byte)
			UART_TX_PORT |= TX_BIT;
		else
			UART_TX_PORT &= ~TX_BIT;
		_delay_us(BIT_US);
		mask <<= 1;
	}
	/* Stop bit */
	UART_TX_PORT |= TX_BIT;	_delay_us(BIT_US);
}

/*!
 * Send a text string (in pgmspace) to the UART.
 * String shall be null-terminated!
 */
void uart_tx_str(const char* str) {
	char c = pgm_read_byte(str);
	while (c) {
		str++;
		uart_tx(c);
		c = pgm_read_byte(str);
	}
}

/*!
 * Send a 4-bit nybble to the UART.
 */
void uart_tx_hex(uint8_t nybble) {
	if (nybble >= 10)
		uart_tx(nybble - 10 + 'a');
	else
		uart_tx(nybble + '0');
}

/*!
 * Send a 8-bit byte to the UART.
 */
void uart_tx_hex_byte(uint8_t byte) {
	uart_tx_hex(byte >> 4);
	uart_tx_hex(byte & 0x0f);
}

/*!
 * Send a 16-bit word to the UART.
 */
void uart_tx_hex_word(uint16_t word) {
	uart_tx_hex_byte(word >> 8);
	uart_tx_hex_byte(word & 0xff);
}

/*!
 * Send a 32-bit long word to the UART.
 */
void uart_tx_hex_lword(uint32_t lword) {
	uart_tx_hex_word(lword >> 16);
	uart_tx_hex_word(lword & 0xffff);
}
