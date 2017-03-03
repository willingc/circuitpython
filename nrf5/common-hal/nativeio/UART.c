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

#include "shared-bindings/microcontroller/__init__.h"
#include "shared-bindings/nativeio/UART.h"

#include "mpconfigport.h"
#include "py/gc.h"
#include "py/mperrno.h"
#include "py/nlr.h"
#include "py/runtime.h"
#include "py/stream.h"

void common_hal_nativeio_uart_construct(nativeio_uart_obj_t *self,
        const mcu_pin_obj_t * tx, const mcu_pin_obj_t * rx, uint32_t baudrate,
        uint8_t bits, uart_parity_t parity, uint8_t stop, uint32_t timeout,
        uint8_t receiver_buffer_size) {

}

void common_hal_nativeio_uart_deinit(nativeio_uart_obj_t *self) {

}

// Read characters.
size_t common_hal_nativeio_uart_read(nativeio_uart_obj_t *self, uint8_t *data, size_t len, int *errcode) {

    return 0;
}

// Write characters.
size_t common_hal_nativeio_uart_write(nativeio_uart_obj_t *self, const uint8_t *data, size_t len, int *errcode) {
    return MP_STREAM_ERROR;
}

uint32_t common_hal_nativeio_uart_rx_characters_available(nativeio_uart_obj_t *self) {
    return 0;
}

bool common_hal_nativeio_uart_ready_to_tx(nativeio_uart_obj_t *self) {
    return false;
}
