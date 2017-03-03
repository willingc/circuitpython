#include "shared-bindings/board/__init__.h"

#include "nrf5_pins.h"

STATIC const mp_map_elem_t board_global_dict_table[] = {
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_00), (mp_obj_t)&pin_P0_00 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_01), (mp_obj_t)&pin_P0_01 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_02), (mp_obj_t)&pin_P0_02 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_03), (mp_obj_t)&pin_P0_03 },
  // 5 -8 are UART to interface chip.
  // 13 - 16 are buttons 1-4
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_13), (mp_obj_t)&pin_P0_13 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_BUTTON1), (mp_obj_t)&pin_P0_13 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_14), (mp_obj_t)&pin_P0_14 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_BUTTON2), (mp_obj_t)&pin_P0_14 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_15), (mp_obj_t)&pin_P0_15 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_BUTTON3), (mp_obj_t)&pin_P0_15 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_16), (mp_obj_t)&pin_P0_16 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_BUTTON4), (mp_obj_t)&pin_P0_16 },
  // 17 - 20 are leds
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_17), (mp_obj_t)&pin_P0_17 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_LED1), (mp_obj_t)&pin_P0_17 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_18), (mp_obj_t)&pin_P0_18 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_LED2), (mp_obj_t)&pin_P0_18 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_19), (mp_obj_t)&pin_P0_19 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_LED3), (mp_obj_t)&pin_P0_19 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_P0_20), (mp_obj_t)&pin_P0_20 },
  { MP_OBJ_NEW_QSTR(MP_QSTR_LED4), (mp_obj_t)&pin_P0_20 },

};
MP_DEFINE_CONST_DICT(board_module_globals, board_global_dict_table);
