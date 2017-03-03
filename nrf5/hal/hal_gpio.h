/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Glenn Ruben Bakke
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __NRF52_HAL_GPIO
#define __NRF52_HAL_GPIO

#include <stdbool.h>

#include <nrf.h>

#if NRF51
  #define POINTERS ((const uint32_t[]){NRF_GPIO_BASE})
#endif

#if NRF52
  #ifdef NRF52832_XXAA
    #define POINTERS ((const uint32_t[]){NRF_P0_BASE})
  #endif

  #ifdef NRF52840_XXAA
    #define POINTERS ((const uint32_t[]){NRF_P0_BASE, NRF_P1_BASE})
  #endif
#endif

#define GPIO_BASE(x) ((NRF_GPIO_Type *)POINTERS[x])

/**
  * @brief   GPIO Init structure definition
  */
typedef struct
{
  uint32_t Pin;       /*!< Specifies the GPIO pins to be configured.
                           This parameter can be any value of @ref GPIO_pins_define */

  uint32_t Mode;      /*!< Specifies the operating mode for the selected pins.
                           This parameter can be a value of @ref GPIO_mode_define */

  uint32_t Pull;      /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
                           This parameter can be a value of @ref GPIO_pull_define */

  uint32_t Speed;     /*!< Specifies the speed for the selected pins.
                           This parameter can be a value of @ref GPIO_speed_define */

  uint32_t Alternate;  /*!< Peripheral to be connected to the selected pins.
                            This parameter can be a value of @ref GPIO_Alternat_function_selection */
} GPIO_InitTypeDef;

typedef enum {
	HAL_GPIO_PULL_DISABLED = (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos),
	HAL_GPIO_PULL_DOWN = (GPIO_PIN_CNF_PULL_Pulldown << GPIO_PIN_CNF_PULL_Pos),
	HAL_GPIO_PULL_UP = (GPIO_PIN_CNF_PULL_Pullup << GPIO_PIN_CNF_PULL_Pos)
} hal_gpio_pull_t;

typedef enum {
	HAL_GPIO_MODE_OUTPUT = (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos),
	HAL_GPIO_MODE_INPUT = (GPIO_PIN_CNF_DIR_Input << GPIO_PIN_CNF_DIR_Pos),
} hal_gpio_mode_t;

// This is smaller than a pointer so pass it by value.
// TODO(tannewt): If we need more space then use a bitfield. That adds code size
// though...
typedef struct {
    uint8_t port;
    uint8_t pin;
} hal_gpio_pin_t;

static inline void hal_gpio_cfg_pin(hal_gpio_pin_t pin, hal_gpio_mode_t mode, hal_gpio_pull_t pull) {
    GPIO_BASE(pin.port)->PIN_CNF[pin.pin] = (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)
                                          | (GPIO_PIN_CNF_DRIVE_S0S1 << GPIO_PIN_CNF_DRIVE_Pos)
                                          | pull
                                          | (GPIO_PIN_CNF_INPUT_Connect << GPIO_PIN_CNF_INPUT_Pos)
                                          | mode;
}

static inline void hal_gpio_out_set(uint8_t port, uint32_t pin_mask) {
	GPIO_BASE(port)->OUTSET = pin_mask;
}

static inline void hal_gpio_pin_set(hal_gpio_pin_t pin) {
	GPIO_BASE(pin.port)->OUTSET = (1 << pin.pin);
}

static inline bool hal_gpio_pin_get(hal_gpio_pin_t pin) {
	return (GPIO_BASE(pin.port)->OUT & (1 << pin.pin)) != 0;
}

static inline void hal_gpio_pin_clear(hal_gpio_pin_t pin) {
	GPIO_BASE(pin.port)->OUTCLR = (1 << pin.pin);
}

static inline void hal_gpio_pin_toggle(hal_gpio_pin_t pin) {
	uint32_t pin_mask = (1 << pin.pin);

	if (GPIO_BASE(pin.port)->OUT ^ pin_mask) {
		GPIO_BASE(pin.port)->OUTSET = pin_mask;
	} else {
		GPIO_BASE(pin.port)->OUTCLR = pin_mask;
	}
}

#endif  // __NRF52_HAL_GPIO
