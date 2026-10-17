
#include <libopencm3/nrf/51/i2c.h>

/**@{*/

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
 * @param[in] scl_pin GPIO pin used for SCL signal
 * @param[in] sda_pin GPIO pin used for SDA signal
 */
void i2c_select_pins(uint32_t i2c, uint32_t scl_pin, uint32_t sda_pin)
{
	if (scl_pin != GPIO_UNCONNECTED) {
		I2C_PSELSCL(i2c) = __GPIO2PIN(scl_pin);
	} else {
		I2C_PSELSCL(i2c) = scl_pin;
	}

	if (sda_pin != GPIO_UNCONNECTED) {
		I2C_PSELSDA(i2c) = __GPIO2PIN(sda_pin);
	} else {
		I2C_PSELSDA(i2c) = sda_pin;
	}
}

/** @} */
