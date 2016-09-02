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

#include <util/delay.h>
#include <avr/pgmspace.h>
#include "uart.h"

const char hello_str[] PROGMEM = {"Hello World!\r\n"};

int main(void) {
	uint32_t ctr = 0;
	uart_init();

	while(1) {
		uart_tx_hex_lword(ctr++);
		uart_tx_str(hello_str);
		_delay_ms(500);
	}
}
