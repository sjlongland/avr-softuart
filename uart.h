#ifndef _UART_H
#define _UART_H

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

#include <stdint.h>

/*!
 * Configure the UART pins.
 */
void uart_init();

/*!
 * Send a raw byte to the UART.
 */
void uart_tx(uint8_t byte);

/*!
 * Send a text string (in pgmspace) to the UART.
 * String shall be null-terminated!
 */
void uart_tx_str(const char* str);

/*!
 * Send a 8-bit byte to the UART.
 */
void uart_tx_hex_byte(uint8_t byte);

/*!
 * Send a 16-bit word to the UART.
 */
void uart_tx_hex_word(uint16_t word);

/*!
 * Send a 32-bit long word to the UART.
 */
void uart_tx_hex_lword(uint32_t lword);
#endif
