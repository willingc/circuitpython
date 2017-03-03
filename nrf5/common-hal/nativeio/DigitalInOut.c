/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Scott Shawcroft for Adafruit Industries
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

#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "py/nlr.h"
#include "py/runtime.h"
#include "py/mphal.h"

#include "hal/hal_gpio.h"

#include "shared-bindings/nativeio/DigitalInOut.h"


digitalinout_result_t common_hal_nativeio_digitalinout_construct(
        nativeio_digitalinout_obj_t* self, const mcu_pin_obj_t* pin) {
    self->pin = pin;
    common_hal_nativeio_digitalinout_switch_to_input(self, PULL_NONE);
    return DIGITALINOUT_OK;
}

void common_hal_nativeio_digitalinout_deinit(nativeio_digitalinout_obj_t* self) {
    uint32_t pin = self->pin->hal_pin.pin;
    uint32_t port = self->pin->hal_pin.port;
    GPIO_BASE(port)->PIN_CNF[pin] = (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)
                                  | (GPIO_PIN_CNF_DRIVE_S0S1 << GPIO_PIN_CNF_DRIVE_Pos)
                                  | (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos)
                                  | (GPIO_PIN_CNF_INPUT_Disconnect << GPIO_PIN_CNF_INPUT_Pos)
                                  | (GPIO_PIN_CNF_DIR_Input << GPIO_PIN_CNF_DIR_Pos);
}

void common_hal_nativeio_digitalinout_switch_to_input(
        nativeio_digitalinout_obj_t* self, enum digitalinout_pull_t pull) {
    common_hal_nativeio_digitalinout_set_pull(self, pull);
}

void common_hal_nativeio_digitalinout_switch_to_output(
        nativeio_digitalinout_obj_t* self, bool value,
        enum digitalinout_drive_mode_t drive_mode) {
    // Set the value before switching.
    common_hal_nativeio_digitalinout_set_value(self, value);
    common_hal_nativeio_digitalinout_set_drive_mode(self, drive_mode);
}

enum digitalinout_direction_t common_hal_nativeio_digitalinout_get_direction(
        nativeio_digitalinout_obj_t* self) {
    uint32_t pin_mask  = (1UL << (self->pin->hal_pin.pin % 32));
    NRF_GPIO_Type *port_base = GPIO_BASE(self->pin->hal_pin.port);
    return ((port_base->DIR & pin_mask) != 0) ? DIRECTION_OUT : DIRECTION_IN;
}

void common_hal_nativeio_digitalinout_set_value(
        nativeio_digitalinout_obj_t* self, bool value) {
    printf("output on %d %d", self->pin->hal_pin.port, self->pin->hal_pin.pin);
    uint32_t pin_mask  = (1UL << (self->pin->hal_pin.pin % 32));
    NRF_GPIO_Type *port_base = GPIO_BASE(self->pin->hal_pin.port);

    /* Set the pin to high or low atomically based on the requested level */
    if (value) {
        port_base->OUTSET = pin_mask;
    } else {
        port_base->OUTCLR = pin_mask;
    }
}

bool common_hal_nativeio_digitalinout_get_value(
        nativeio_digitalinout_obj_t* self) {
    uint32_t pin_mask  = (1UL << (self->pin->hal_pin.pin % 32));
    NRF_GPIO_Type *port_base = GPIO_BASE(self->pin->hal_pin.port);
    if ((port_base->DIR & pin_mask) != 0) {
        return port_base->OUT & pin_mask;
    }
    return port_base->IN & pin_mask;
}

void common_hal_nativeio_digitalinout_set_drive_mode(
        nativeio_digitalinout_obj_t* self,
        enum digitalinout_drive_mode_t drive_mode) {// Handle open drain natively.
    uint32_t drive = GPIO_PIN_CNF_DRIVE_S0S1;
    if (drive_mode == DRIVE_MODE_OPEN_DRAIN) {
        drive = GPIO_PIN_CNF_DRIVE_S0D1;
    }
    uint32_t pin = self->pin->hal_pin.pin;
    uint32_t port = self->pin->hal_pin.port;
    GPIO_BASE(port)->PIN_CNF[pin] = (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)
                                  | (drive << GPIO_PIN_CNF_DRIVE_Pos)
                                  | (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos)
                                  | (GPIO_PIN_CNF_INPUT_Disconnect << GPIO_PIN_CNF_INPUT_Pos)
                                  | (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos);
}

enum digitalinout_drive_mode_t common_hal_nativeio_digitalinout_get_drive_mode(
        nativeio_digitalinout_obj_t* self) {
    NRF_GPIO_Type *port_base = GPIO_BASE(self->pin->hal_pin.port);
    uint32_t drive = port_base->PIN_CNF[self->pin->hal_pin.pin] & (GPIO_PIN_CNF_DRIVE_Msk << GPIO_PIN_CNF_DRIVE_Pos);
    if (drive == (GPIO_PIN_CNF_DRIVE_S0D1 << GPIO_PIN_CNF_DRIVE_Pos)) {
        return DRIVE_MODE_OPEN_DRAIN;
    } else {
        return DRIVE_MODE_PUSH_PULL;
    }
}

void common_hal_nativeio_digitalinout_set_pull(
        nativeio_digitalinout_obj_t* self, enum digitalinout_pull_t pull) {
    uint32_t nrf_pull = GPIO_PIN_CNF_PULL_Disabled;
    switch (pull) {
        case PULL_UP:
            nrf_pull = GPIO_PIN_CNF_PULL_Pullup;
            break;
        case PULL_DOWN:
            nrf_pull = GPIO_PIN_CNF_PULL_Pulldown;
            break;
        case PULL_NONE:
        default:
            break;
    }
    uint32_t pin = self->pin->hal_pin.pin;
    uint32_t port = self->pin->hal_pin.port;
    GPIO_BASE(port)->PIN_CNF[pin] = (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)
                                  | (GPIO_PIN_CNF_DRIVE_S0S1 << GPIO_PIN_CNF_DRIVE_Pos)
                                  | (nrf_pull << GPIO_PIN_CNF_PULL_Pos)
                                  | (GPIO_PIN_CNF_INPUT_Connect << GPIO_PIN_CNF_INPUT_Pos)
                                  | (GPIO_PIN_CNF_DIR_Input << GPIO_PIN_CNF_DIR_Pos);
}

enum digitalinout_pull_t common_hal_nativeio_digitalinout_get_pull(
        nativeio_digitalinout_obj_t* self) {
    NRF_GPIO_Type *port_base = GPIO_BASE(self->pin->hal_pin.port);
    uint32_t pull = (port_base->PIN_CNF[self->pin->hal_pin.pin] >> GPIO_PIN_CNF_PULL_Pos) & GPIO_PIN_CNF_PULL_Msk;

    if (pull == GPIO_PIN_CNF_PULL_Disabled) {
        return PULL_NONE;
    } if (pull == GPIO_PIN_CNF_PULL_Pullup) {
        return PULL_UP;
    } else {
        return PULL_DOWN;
    }
}
