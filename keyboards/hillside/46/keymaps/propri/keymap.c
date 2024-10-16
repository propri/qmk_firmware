// Copyright 2022 Michael McCoyd (@mmccoyd)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// List of Layers
enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NEO_4,
};

// custom keycodes, checked in process_record_user
enum custom_keycodes {
  _KONAMI_CODE = SAFE_RANGE,
  _VIM_EXIT_TERMINAL,
};

// combined key - layer 3 on hold, y on tap (with neo layout)
#define NEO_LAYER3_Y LT(0, KC_QUOT)

// keys for switching to layer 4. Separate alias to use in combo.
#define NEO_LAYER4_MOMENTARY_LEFT LT(_NEO_4, KC_V)
#define NEO_LAYER4_MOMENTARY_RIGHT LT(_NEO_4, KC_M)

// mod-tap shortcuts base layer
#define MT_Z LGUI_T(KC_Z)
#define MT_X LALT_T(KC_X)
#define MT_C LCTL_T(KC_C)
#define MT_V NEO_LAYER4_MOMENTARY_LEFT
#define MT_M NEO_LAYER4_MOMENTARY_RIGHT
#define MT_COMM LCTL_T(KC_COMM)
#define MT_DOT LALT_T(KC_DOT)

#define _X XXXXXXX

// define combos
// both layer4 Taps to lock layer4
const uint16_t PROGMEM combo_layer4_enable[] = {NEO_LAYER4_MOMENTARY_LEFT, NEO_LAYER4_MOMENTARY_RIGHT, COMBO_END};
// both layer4 Taps on locked layer4 to return to default layer
const uint16_t PROGMEM combo_layer4_disable[] = {KC_PENT, KC_P1, COMBO_END};

combo_t key_combos[] = {
  COMBO(combo_layer4_enable, TG(_NEO_4)),
  COMBO(combo_layer4_disable, TG(_NEO_4)),
};

// #define LY_NAV MO(_NAV)
// #define LY_SYM MO(_SYM)
// #define LY_ADJ MO(_ADJUST)
// #define ALT_GR OSM(MOD_RALT)
// #define OSM_SFT OSM(MOD_LSFT)
// #define PLY_PAU  KC_MEDIA_PLAY_PAUSE
//
// #define UNDO LCTL(KC_Z)
// #define CUT  LCTL(KC_X)
// #define COPY LCTL(KC_C)
// #define PASTE LCTL(KC_V)
// #define REDO LCTL(KC_Y)
// // (For OS X, you'll want to change these editing keys to LGUI(KC_Z) etc.)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NUHS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, NEO_LAYER3_Y,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    MT_Z,    MT_X,    MT_C,    MT_V,    KC_B, XXXXXXX,   XXXXXXX,     KC_N,    MT_M, MT_COMM,  MT_DOT, KC_SLSH, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                          MO(_LOWER),   KC_ENT,  LSFT_T(KC_ESC), _X,    _X, RSFT_T(KC_SPC),   KC_BSPC, MO(_RAISE)
                                      //`--------------------------'  `--------------------------'

  ),

    [_LOWER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_GRV,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,   _______,  XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              _______, _______,  _______, _______,      _______, _______,   _______, MO(_ADJUST)
                                      //`--------------------------'  `--------------------------'
  ),

    [_RAISE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,   _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                          MO(_ADJUST),  _______,  _______, _______,   _______, _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_ADJUST] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, KC_KB_VOLUME_UP,   DT_UP, XXXXXXX,                      XXXXXXX, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, DT_PRNT, _VIM_EXIT_TERMINAL,      _KONAMI_CODE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_KB_VOLUME_DOWN, DT_DOWN, XXXXXXX, _______,            _______, XXXXXXX, KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  _______, _______,  _______, _______,  _______, _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_NEO_4] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_PSCR, KC_PGUP, KC_BSPC,   KC_UP,  KC_DEL, KC_PGDN,                      XXXXXXX,   KC_P7,   KC_P8,   KC_P9, KC_PPLS, KC_PMNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,                      XXXXXXX,   KC_P4,   KC_P5,   KC_P6, KC_PCMM, KC_PDOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, LGUI_T(KC_ESC), LALT_T(KC_TAB), LCTL_T(KC_INS), KC_PENT, KC_UNDO, _X, _X, XXXXXXX,   KC_P1, LCTL_T(KC_P2), LALT_T(KC_P3), KC_APP, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  _______, _______, _______, _______,   _______, RSFT_T(KC_P0), _______, _______
                                      //`--------------------------'  `--------------------------'
  )
    // [_QWERTY] = LAYOUT(
    //  KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    //  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    //  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,                       CW_TOGG, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    //                                      KC_LGUI, KC_LALT, OSM_SFT, LY_NAV ,    LY_SYM , KC_SPC , KC_LALT, KC_RGUI
    // ),
    // [_NAV] = LAYOUT(
    //  COPY   , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
    //  CUT    , KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, PASTE  ,                                        KC_PGUP, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_PGDN,
    //  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , UNDO   ,                      REDO   , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_RCTL,
    //                                      _______, _______, _______, _______,    LY_ADJ , _______, _______, _______
    // ),
    // [_SYM] = LAYOUT(
    //  KC_INS,  KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    //  xxxxxxx, KC_BSLS, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC,                                        KC_HOME, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, KC_END,
    //  _______, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, ALT_GR ,                      KC_APP , KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, xxxxxxx, KC_RCTL,
    //                                      _______, _______, _______, LY_ADJ ,    _______, _______, _______, _______ 
    // ),
    // [_ADJUST] = LAYOUT(
    //  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, AG_SWAP, CG_SWAP,                                        xxxxxxx, KC_F11 , KC_F12 , KC_PSCR, xxxxxxx, EE_CLR,
    //  xxxxxxx, xxxxxxx, KC_BRID, KC_BRIU, AG_NORM, CG_NORM,                                        RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, xxxxxxx, xxxxxxx, 
    //  xxxxxxx, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, xxxxxxx, xxxxxxx,                     RGB_TOG, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, xxxxxxx, QK_BOOT,
    //                                      xxxxxxx, xxxxxxx, xxxxxxx, _______,    _______, xxxxxxx, xxxxxxx, xxxxxxx
    // ),
};

//  Template:
//    [_INDEX] = LAYOUT(
//     _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______, 
//     _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______, 
//     _______, _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______,
//                                         _______, _______, _______, _______,    _______, _______, _______, _______
//    ),

// Helper for implementing tap vs. long-press keys. Given a tap-hold
// key event, replaces the hold function with `long_press_keycode`.
static bool process_tap_or_long_press_custom_mod_key(
        keyrecord_t* record, uint16_t long_press_keycode) {
  if (record->tap.count == 0) { // Key is being held
    if (record->event.pressed) {
      // tap_code16 for tapping instead of holding the long_press_keycode
      /*tap_code16(long_press_keycode);*/
      register_code16(long_press_keycode);
    } else {
      unregister_code16(long_press_keycode);
    }
      return false; // Skip default handling.
    }
  return true; // Continue default handling.
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NEO_LAYER3_Y:
      return process_tap_or_long_press_custom_mod_key(record, KC_NUHS);
    case _KONAMI_CODE:
      if (record->event.pressed) {
        // "ba" because browsers always use qwerty layout?
        SEND_STRING(SS_DELAY(10)SS_TAP(X_UP)SS_DELAY(10)SS_TAP(X_UP)SS_DELAY(10)SS_TAP(X_DOWN)SS_DELAY(10)SS_TAP(X_DOWN)SS_DELAY(10)SS_TAP(X_LEFT)SS_DELAY(10)SS_TAP(X_RGHT)SS_DELAY(10)SS_TAP(X_LEFT)SS_DELAY(10)SS_TAP(X_RIGHT)SS_DELAY(10)"ba");
      }
      return false;
    case _VIM_EXIT_TERMINAL:
      if (record->event.pressed) {
        // ctrl-a ctrl-j because neo makes it u j
        SEND_STRING(SS_LCTL(SS_DOWN(X_CAPS)SS_DELAY(20)"a"SS_DELAY(50)SS_UP(X_CAPS)SS_DELAY(20)"j"));
      }
      return false;
  }
  return true;
}

