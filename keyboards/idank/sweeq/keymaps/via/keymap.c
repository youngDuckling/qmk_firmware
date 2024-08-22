// Copyright 2023 Idan Kamara (@idank)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_SPM2 LT(2, KC_SPC)
#define KC_BSM1 LT(1, KC_BSPC)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_CLGV CTL_T(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,
    KC_A, KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,  KC_K,    KC_L,   KC_QUOT,
    KC_Z, KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,
                                    MO(2), KC_LSFT, KC_SPC, MO(1)
  ),

  [1] = LAYOUT(
    KC_TILDE,KC_AT,   KC_UP, KC_MCTL,    KC_PGUP,            KC_BRID,    KC_BRIU,    KC_KB_MUTE,   KC_KB_VOLUME_DOWN,    KC_KB_VOLUME_UP,
    KC_BSLS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,              OSM(MOD_RGUI), OSM(MOD_RGUI),    OSM(MOD_RALT),   OSM(MOD_RCTL), OSM(MOD_RSFT),
    KC_UNDO, KC_AGAIN, KC_COPY, KC_PSTE, KC_KB_MUTE,         KC_MCTL,    KC_WH_R,    KC_WH_U,   KC_WH_D, KC_WH_L,
                                          MO(3), KC_TRNS, KC_SPC, KC_TRNS
  ),

  [2] = LAYOUT(
    KC_EXLM, KC_COLN, KC_HASH,   KC_DLR,   KC_UNDS,        KC_EQL,  KC_7,    KC_8,   KC_9, KC_MINS,
    KC_GRV,  KC_SCLN, KC_AMPR,   KC_LPRN, KC_LBRC,         KC_PLUS, KC_4,    KC_5,   KC_6, KC_ASTR,
    KC_LT,   KC_GT,   KC_PIPE,   KC_LPRN, KC_RBRC,         KC_0,    KC_1,    KC_2,   KC_3, KC_CIRC,
                                    KC_TRNS, KC_TRNS, KC_SPC, MO(3)
  ),

  [3] = LAYOUT(
  KC_EXLM, KC_COLN, KC_HASH,   KC_DLR,   KC_SLSH,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  KC_GRV,  KC_SCLN, KC_AMPR,   KC_LPRN, KC_LBRC,         KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PIPE,
  KC_LT,   KC_GT,   KC_PIPE,   KC_RPRN, KC_RBRC,         KC_UNDS, KC_PLUS, KC_TRNS, KC_TRNS, QK_BOOT,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

enum combos { 
  S_D_ESC,
  K_L_BSPC,
  DOT_COMM_ENT,
  X_C_TAB,
  LPRN_LBRC_LCBR,
  RPRN_RBRC_RCBR,
  O_I_RGUI,
  U_I_RALT,
  W_E_LGUI,
  E_R_LALT,
  R_T_BTN1,
  F_G_BTN2,
  
};

const uint16_t PROGMEM s_d_esc[] = { KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM k_l_bspc[] = { KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM dot_comm_ent[] = { KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM x_c_tab[] = { KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM lprn_lbrc_lcbr[] = { KC_LPRN, KC_LBRC, COMBO_END};
const uint16_t PROGMEM rprn_rbrc_rcbr[] = { KC_RPRN, KC_RBRC, COMBO_END};
const uint16_t PROGMEM o_i_rgui[] = { KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM u_i_ralt[] = { KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM w_e_lgui[] = { KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM e_r_lalt[] = { KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM r_t_btn1[] = { KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM f_g_btn2[] = { KC_F, KC_G, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [S_D_ESC] = COMBO(s_d_esc, KC_ESC),
  [K_L_BSPC] = COMBO(k_l_bspc, KC_BSPC),
  [DOT_COMM_ENT] = COMBO(dot_comm_ent, KC_ENT),
  [X_C_TAB] = COMBO(x_c_tab, KC_TAB),
  [LPRN_LBRC_LCBR] = COMBO(lprn_lbrc_lcbr, KC_LCBR),
  [RPRN_RBRC_RCBR] = COMBO(rprn_rbrc_rcbr, KC_RCBR),
  [O_I_RGUI] = COMBO(o_i_rgui, KC_RGUI),
  [U_I_RALT] = COMBO(u_i_ralt, KC_RALT),
  [W_E_LGUI] = COMBO(w_e_lgui, KC_LGUI),
  [E_R_LALT] = COMBO(e_r_lalt, KC_LALT),
  [R_T_BTN1] = COMBO(r_t_btn1, KC_BTN1),
  [F_G_BTN2] = COMBO(f_g_btn2, KC_BTN2),
  
};