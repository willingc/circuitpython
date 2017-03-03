/*
 * This file is part of the MicroPython project, http://micropython.org/
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

 // This file contains all of the port specific HAL functions for the machine
 // module.

#include "shared-bindings/nativeio/SPI.h"
#include "py/runtime.h"

void common_hal_nativeio_spi_construct(nativeio_spi_obj_t *self,
        const mcu_pin_obj_t * clock, const mcu_pin_obj_t * mosi,
        const mcu_pin_obj_t * miso) {

}

void common_hal_nativeio_spi_deinit(nativeio_spi_obj_t *self) {

}

bool common_hal_nativeio_spi_configure(nativeio_spi_obj_t *self,
        uint32_t baudrate, uint8_t polarity, uint8_t phase, uint8_t bits) {
    return true;
}

bool common_hal_nativeio_spi_try_lock(nativeio_spi_obj_t *self) {
    return self->has_lock;
}

bool common_hal_nativeio_spi_has_lock(nativeio_spi_obj_t *self) {
    return self->has_lock;
}

void common_hal_nativeio_spi_unlock(nativeio_spi_obj_t *self) {
    self->has_lock = false;
}

bool common_hal_nativeio_spi_write(nativeio_spi_obj_t *self,
        const uint8_t *data, size_t len) {
    return true;
}

bool common_hal_nativeio_spi_read(nativeio_spi_obj_t *self,
        uint8_t *data, size_t len, uint8_t write_value) {
    return true;
}
