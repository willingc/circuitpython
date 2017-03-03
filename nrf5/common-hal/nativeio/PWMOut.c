/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Damien P. George
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

#include "py/runtime.h"
#include "common-hal/nativeio/PWMOut.h"
#include "shared-bindings/nativeio/PWMOut.h"

void pwmout_reset(void) {

}

void common_hal_nativeio_pwmout_construct(nativeio_pwmout_obj_t* self,
                                          const mcu_pin_obj_t* pin,
                                          uint16_t duty,
                                          uint32_t frequency,
                                          bool variable_frequency) {

}

extern void common_hal_nativeio_pwmout_deinit(nativeio_pwmout_obj_t* self) {

}

extern void common_hal_nativeio_pwmout_set_duty_cycle(nativeio_pwmout_obj_t* self, uint16_t duty) {

}

uint16_t common_hal_nativeio_pwmout_get_duty_cycle(nativeio_pwmout_obj_t* self) {
    return 0;
}


void common_hal_nativeio_pwmout_set_frequency(nativeio_pwmout_obj_t* self,
                                              uint32_t frequency) {

}

uint32_t common_hal_nativeio_pwmout_get_frequency(nativeio_pwmout_obj_t* self) {
    return 0;
}

bool common_hal_nativeio_pwmout_get_variable_frequency(nativeio_pwmout_obj_t* self) {
    return self->variable_frequency;
}
