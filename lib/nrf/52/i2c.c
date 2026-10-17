/** @addtogroup i2c_file I2C peripheral API 
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2022 Eduard Drusa <ventyl86(at)netkosice(dot)sk>
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

#include <libopencm3/nrf/52/i2c.h>

/**@{*/

/** Configure I2C transmit buffer properties
 *
 * Configures transmit buffer for EasyDMA transaction. This API
 * is only available if @ref I2C_MODE_MASTER mode is activated.
 *
 * Configures linear TX buffer for EasyDMA transmission.
 * @param[in] i2c i2c peripheral base, see @ref i2c_block
 * @param[in] buffer address of buffer start
 * @param[in] len length of data in the buffer
 */
void i2c_set_tx_buffer(uint32_t i2c, const uint8_t *buffer, uint8_t len)
{
	I2C_TXDPTR(i2c) = (uint32_t) buffer;
	I2C_TXDMAXCNT(i2c) = len;
	I2C_TXDLIST(i2c) = 0;
}

/** Configure I2C receive buffer properties
 *
 * Configures receive buffer for EasyDMA transaction. This API
 * is only available if @ref I2C_MODE_MASTER mode is activated.
 *
 * Configures linear RX buffer for EasyDMA transmission.
 * @param[in] i2c i2c peripheral base, see @ref i2c_block
 * @param[in] buffer address of buffer start
 * @param[in] len length of the buffer
 */
void i2c_set_rx_buffer(uint32_t i2c, uint8_t *buffer, uint8_t len)
{
	I2C_RXDPTR(i2c) = (uint32_t) buffer;
	I2C_RXDMAXCNT(i2c) = len;
	I2C_RXDLIST(i2c) = 0;
}
/** @brief Select GPIO pins to be used by this peripheral.
 *
 * Configures GPIO pins assigned to SCL and SDA signals. These pins are only occupied
 * by I2C peripheral whenever it is enabled using @ref i2c_enable. It is possible to
 * ignore any given signal and not map it to pin by using special value of 
 * @ref GPIO_UNCONNECTED instead of @ref gpio_pin_id values.
 *
 * This needs to be configured when no transaction is in progress.
 *
 * @param[in] i2c i2c peripheral base, see @ref i2c_block
 * @param[in] scl_port GPIO port used for the SCL signal
 * @param[in] scl_pin GPIO pin used for SCL signal
 * @param[in] sda_port GPIO port used for the SDA signal
 * @param[in] sda_pin GPIO pin used for SDA signal
 */
void i2c_select_pins(uint32_t i2c, uint32_t scl_port, uint32_t scl_pin, uint32_t sda_port, uint32_t sda_pin)
{
	if (scl_pin != GPIO_UNCONNECTED) {
		I2C_PSELSCL(i2c) =  __PORT2PSEL(scl_port) | __GPIO2PIN(scl_pin);
	} else {
		I2C_PSELSCL(i2c) = GPIO_UNCONNECTED;
	}

	if (sda_pin != GPIO_UNCONNECTED) {
		I2C_PSELSDA(i2c) = __PORT2PSEL(sda_port) | __GPIO2PIN(sda_pin);
	} else {
		I2C_PSELSDA(i2c) = GPIO_UNCONNECTED;
	}
}

/** @} */
