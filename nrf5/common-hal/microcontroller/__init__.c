/*
 * This file is P0_rt of the MicroPython project, http://micropython.org/
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
 * FITNESS FOR A P0_RTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "py/mphal.h"

#include "nrf5_pins.h"

void common_hal_mcu_delay_us(uint32_t delay) {
    mp_hal_delay_us(delay);
}

void common_hal_mcu_disable_interrupts(void) {
#ifndef BLUETOOTH_SD
    __disable_irq();
#endif
}

void common_hal_mcu_enable_interrupts(void) {
#ifndef BLUETOOTH_SD
    __enable_irq();
#endif
}

// This maps MCU pin names to pin objects.
STATIC const mp_map_elem_t mcu_pin_global_dict_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_00), (mp_obj_t)&pin_P0_00 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_01), (mp_obj_t)&pin_P0_01 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_02), (mp_obj_t)&pin_P0_02 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_03), (mp_obj_t)&pin_P0_03 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_04), (mp_obj_t)&pin_P0_04 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_05), (mp_obj_t)&pin_P0_05 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_06), (mp_obj_t)&pin_P0_06 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_07), (mp_obj_t)&pin_P0_07 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_08), (mp_obj_t)&pin_P0_08 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_09), (mp_obj_t)&pin_P0_09 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_10), (mp_obj_t)&pin_P0_10 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_11), (mp_obj_t)&pin_P0_11 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_12), (mp_obj_t)&pin_P0_12 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_13), (mp_obj_t)&pin_P0_13 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_14), (mp_obj_t)&pin_P0_14 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_15), (mp_obj_t)&pin_P0_15 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_16), (mp_obj_t)&pin_P0_16 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_17), (mp_obj_t)&pin_P0_17 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_18), (mp_obj_t)&pin_P0_18 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_19), (mp_obj_t)&pin_P0_19 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_20), (mp_obj_t)&pin_P0_20 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_21), (mp_obj_t)&pin_P0_21 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_22), (mp_obj_t)&pin_P0_22 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_23), (mp_obj_t)&pin_P0_23 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_24), (mp_obj_t)&pin_P0_24 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_25), (mp_obj_t)&pin_P0_25 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_26), (mp_obj_t)&pin_P0_26 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_27), (mp_obj_t)&pin_P0_27 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_28), (mp_obj_t)&pin_P0_28 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_29), (mp_obj_t)&pin_P0_29 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_30), (mp_obj_t)&pin_P0_30 },
    #if defined(NRF52832_XXAA) || defined(NRF52840_XXAA)
    { MP_OBJ_NEW_QSTR(MP_QSTR_P0_31), (mp_obj_t)&pin_P0_31 },
    #endif

    #ifdef NRF52840_XXAA
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_00), (mp_obj_t)&pin_P1_00 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_01), (mp_obj_t)&pin_P1_01 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_02), (mp_obj_t)&pin_P1_02 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_03), (mp_obj_t)&pin_P1_03 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_04), (mp_obj_t)&pin_P1_04 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_05), (mp_obj_t)&pin_P1_05 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_06), (mp_obj_t)&pin_P1_06 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_07), (mp_obj_t)&pin_P1_07 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_08), (mp_obj_t)&pin_P1_08 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_09), (mp_obj_t)&pin_P1_09 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_10), (mp_obj_t)&pin_P1_10 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_11), (mp_obj_t)&pin_P1_11 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_12), (mp_obj_t)&pin_P1_12 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_13), (mp_obj_t)&pin_P1_13 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_14), (mp_obj_t)&pin_P1_14 },
    { MP_OBJ_NEW_QSTR(MP_QSTR_P1_15), (mp_obj_t)&pin_P1_15 },
    #endif
};
MP_DEFINE_CONST_DICT(mcu_pin_globals, mcu_pin_global_dict_table);
