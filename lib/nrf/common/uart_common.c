/** @addtogroup uart_file UART peripheral API
 *
 * @brief <b>Access functions for the UART controller</b>
 *
 * @ingroup peripheral_apis
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Maxim Sloyko <maxims@google.com>
 *
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017-2018 Unicore MX project<dev(at)lists(dot)unicore-mx(dot)org>
 * Copyright (C) 2021 Eduard Drusa <ventyl86(at)netkosice(dot)sk>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/nrf/uart.h>
#include <libopencm3/nrf/gpio.h>
/**@{*/

/** @brief Enable the peripheral
 *
 * @param[in] uart uint32_t uart base
 */
void uart_enable(uint32_t uart)
{
	UART_ENABLE(uart) = UART_ENABLE_ENABLED;
}

/** @brief Disable the peripheral
 *
 * @param[in] uart uint32_t uart base
 */
void uart_disable(uint32_t uart)
{
	UART_ENABLE(uart) = UART_ENABLE_DISABLED;
}

#undef _LOG2

void uart_set_baudrate(uint32_t uart, enum uart_baud br)
{
	UART_BAUDRATE(uart) = br;
}

void uart_set_parity(uint32_t uart, int parity)
{
	UART_CONFIG(uart) |= parity ? UART_CONFIG_PARITY : 0;
}

void uart_set_flow_control(uint32_t uart, int flow)
{
	UART_CONFIG(uart) |= flow ? UART_CONFIG_HWFC : 0;
}

void uart_start_tx(uint32_t uart)
{
	PERIPH_TRIGGER_TASK(UART_TASK_STARTTX((uart)));
}

void uart_send(uint32_t uart, uint16_t byte)
{
	UART_TXD((uart)) = byte;
}

void uart_stop_tx(uint32_t uart)
{
	PERIPH_TRIGGER_TASK(UART_TASK_STOPTX((uart)));
}

void uart_start_rx(uint32_t uart)
{
	PERIPH_TRIGGER_TASK(UART_TASK_STARTRX((uart)));
}

uint16_t uart_recv(uint32_t uart)
{
	return UART_RXD(uart);
}

void uart_stop_rx(uint32_t uart)
{
	PERIPH_TRIGGER_TASK(UART_TASK_STOPRX((uart)));
}
/**@}*/

