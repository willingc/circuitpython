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
    // TODO(tannewt)
}

void common_hal_mcu_enable_interrupts(void) {
    // TODO(tannewt)
}

// This maps MCU pin names to pin objects.
STATIC const mp_map_elem_t mcu_pin_global_dict_table[] = {
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_00), (mp_obj_t)&pin_P0_00 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_01), (mp_obj_t)&pin_P0_01 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_02), (mp_obj_t)&pin_P0_02 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_03), (mp_obj_t)&pin_P0_03 },
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
};
MP_DEFINE_CONST_DICT(mcu_pin_globals, mcu_pin_global_dict_table);
