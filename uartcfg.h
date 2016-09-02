#ifndef _UARTCFG_H
#define _UARTCFG_H
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

/* The following defines the configuration for the UART driver. */

/*!
 * UART BAUD rate.  This is the speed that we transmit at.  For the 1MHz
 * RC clock, 4800 is the maximum speed (out of the "standard" ones) that
 * will work.  If you're running at 8MHz or with an external crystal, you
 * may go higher.
 */
#define UART_BAUD	(4800)

/* Port settings */
#define UART_TX_PORT	PORTA	/*!< GPIO port register for Tx */
#define UART_TX_DDR	DDRA	/*!< GPIO direction register for Tx */
#define UART_TX_BIT	1	/*!< GPIO pin for Tx */

#endif
