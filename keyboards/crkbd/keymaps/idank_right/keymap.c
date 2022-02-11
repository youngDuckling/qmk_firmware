/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_us_international.h"

#include "drivers/sensors/pimoroni_trackball.h"
#include "pointing_device.h"
#include "keyboards/crkbd/keymaps/idank_right/secrets.h"

enum crkbd_layers {
    _BASE,
    _NAV,
    _SYM,
    _QWERTY
};


enum custom_keycodes {
    BALL_LC = SAFE_RANGE,
    BALL_RC,
    BALL_SCR,
    BSP_DEL,
    SWITCH,
    KC_PSTRING,
    KC_TABWIN
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  BSP_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCPO,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RSPC,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,   RSFT_T(KC_ESC),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_RALT,  MO(_NAV),  KC_SPC,     KC_ENT,   MO(_SYM), LGUI_T(KC_TABWIN)
                                      //`--------------------------'  `--------------------------'

  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, BSP_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCPO, KC_PSTRING, XXXXXXX, BALL_SCR,BALL_LC, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RSPC, XXXXXXX, XXXXXXX, XXXXXXX, BALL_RC, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_RALT, _______,  KC_SPC,     KC_ENT,   _______, KC_LGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, BSP_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCPO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_RALT, _______,  KC_SPC,     KC_ENT, _______, KC_LGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  BSP_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCPO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RSPC,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          SWITCH,   MO(_NAV),  KC_SPC,     KC_ENT,   MO(_SYM), KC_LGUI
                                      //`--------------------------'  `--------------------------'

  )

};


void keyboard_post_init_user(void) {
    pimoroni_trackball_set_rgbw(0,0,0,80);
}

bool set_scrolling = false;
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = mouse_report.y = 0; 
    }
    return mouse_report;
}

uint16_t key_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record){
  static uint8_t saved_mods   = 0;

  switch (keycode){
  case BALL_LC:
     record->event.pressed?register_code(KC_BTN1):unregister_code(KC_BTN1);
     break;
  case BALL_RC:
     record->event.pressed?register_code(KC_BTN2):unregister_code(KC_BTN2);
     break;
  case BALL_SCR:
     if(record->event.pressed){
     set_scrolling = true;
   } else{
     set_scrolling = false;
   }
    break;
  case BSP_DEL:
    if (record->event.pressed) {
        saved_mods = get_mods() & MOD_MASK_SHIFT;

        if (saved_mods == MOD_MASK_SHIFT) {  // Both shifts pressed
            register_code(KC_DEL);
        } else if (saved_mods) {   // One shift pressed
            del_mods(saved_mods);  // Remove any Shifts present
            register_code(KC_DEL);
            add_mods(saved_mods);  // Add shifts again
        } else {
            register_code(KC_BSPC);
        }
    } else {
        unregister_code(KC_DEL);
        unregister_code(KC_BSPC);
    }
    return false;
  case KC_PSTRING:
    if (record->event.pressed) {
        SEND_STRING(PASS);
    }
    break;
  case LGUI_T(KC_TABWIN):
    if (record->tap.count && record->event.pressed) {
        tap_code16(G(KC_GRV));
        return false;        // Return false to ignore further processing of key
    }
    break;
  case SWITCH:
//     if (record->event.pressed) {
//         key_timer = timer_read();
//         register_code(KC_LALT);
//     } else {
//         unregister_code(KC_LALT);
//         if (timer_elapsed(key_timer) < TAPPING_TERM) {
//             set_single_persistent_default_layer(get_highest_layer(default_layer_state) == _QWERTY ? _BASE : _QWERTY);
//             tap_code16(C(LOPT(KC_SPACE)));
//         }
//     }
//     break;
  default:
    break;
  }
  return true;
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_TABWIN):
            return 150;
        default:
            return TAPPING_TERM;
    }
}


layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        pimoroni_trackball_set_rgbw(0,0,0,80);
        break;
    case _NAV:
        pimoroni_trackball_set_rgbw(0,153,95,0);
        break;
    case _SYM:
        pimoroni_trackball_set_rgbw(153,113,0,0);
        break;
    default: //  for any other layers, or the default layer
        pimoroni_trackball_set_rgbw(0,0,0,80);
        break;
    }
  return state;
}
