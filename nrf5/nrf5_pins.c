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

#include <nrf.h>

#include "common-hal/microcontroller/types.h"
#include "shared-bindings/microcontroller/Pin.h"

#define NO_ADC 0x7f

#define PIN(p_name, p_port, p_pin, p_adc_channel) \
const mcu_pin_obj_t pin_## p_name = { \
    { &mcu_pin_type }, \
    .name = MP_QSTR_P ## p_name, \
    .hal_pin = { p_port , p_pin}, \
    .has_adc = p_adc_channel != NO_ADC, \
    .adc_channel = p_adc_channel, \
};

PIN(P0_00, 0, 0, NO_ADC);
PIN(P0_01, 0, 1, NO_ADC);
PIN(P0_02, 0, 2, NO_ADC);
PIN(P0_03, 0, 3, NO_ADC);
PIN(P0_04, 0, 4, NO_ADC);
PIN(P0_05, 0, 5, NO_ADC);
PIN(P0_06, 0, 6, NO_ADC);
PIN(P0_07, 0, 7, NO_ADC);
PIN(P0_08, 0, 8, NO_ADC);
PIN(P0_09, 0, 9, NO_ADC);
PIN(P0_10, 0, 10, NO_ADC);
PIN(P0_11, 0, 11, NO_ADC);
PIN(P0_12, 0, 12, NO_ADC);
PIN(P0_13, 0, 13, NO_ADC);
PIN(P0_14, 0, 14, NO_ADC);
PIN(P0_15, 0, 15, NO_ADC);
PIN(P0_16, 0, 16, NO_ADC);
PIN(P0_17, 0, 17, NO_ADC);
PIN(P0_18, 0, 18, NO_ADC);
PIN(P0_19, 0, 19, NO_ADC);
PIN(P0_20, 0, 20, NO_ADC);
PIN(P0_21, 0, 21, NO_ADC);
PIN(P0_22, 0, 22, NO_ADC);
PIN(P0_23, 0, 23, NO_ADC);
PIN(P0_24, 0, 24, NO_ADC);
PIN(P0_25, 0, 25, NO_ADC);
PIN(P0_26, 0, 26, NO_ADC);
PIN(P0_27, 0, 27, NO_ADC);
PIN(P0_28, 0, 28, NO_ADC);
PIN(P0_29, 0, 29, NO_ADC);
PIN(P0_30, 0, 30, NO_ADC);
#if defined(NRF52832_XXAA) || defined(NRF52840_XXAA)
PIN(P0_31, 0, 31, NO_ADC);
#endif

#ifdef NRF52840_XXAA
PIN(P1_00, 1, 0, NO_ADC);
PIN(P1_01, 1, 1, NO_ADC);
PIN(P1_02, 1, 2, NO_ADC);
PIN(P1_03, 1, 3, NO_ADC);
PIN(P1_04, 1, 4, NO_ADC);
PIN(P1_05, 1, 5, NO_ADC);
PIN(P1_06, 1, 6, NO_ADC);
PIN(P1_07, 1, 7, NO_ADC);
PIN(P1_08, 1, 8, NO_ADC);
PIN(P1_09, 1, 9, NO_ADC);
PIN(P1_10, 1, 10, NO_ADC);
PIN(P1_11, 1, 11, NO_ADC);
PIN(P1_12, 1, 12, NO_ADC);
PIN(P1_13, 1, 13, NO_ADC);
PIN(P1_14, 1, 14, NO_ADC);
PIN(P1_15, 1, 15, NO_ADC);
#endif
