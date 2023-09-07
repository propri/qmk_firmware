#include QMK_KEYBOARD_H

// hoffentlich seltener hold keys versehentlich getriggert
#define PERMISSIVE_HOLD

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NEO_4,
};

enum custom_keycodes {
  _KONAMI_CODE = SAFE_RANGE,
  _VIM_EXIT_TERMINAL,
};

// combined key - layer 3 on hold, y on tap (with neo layout)
#define NEO_LAYER3_Y LT(0, KC_QUOT)

// keys for switching to layer 4. Separate alias to use in combo.
#define NEO_LAYER4_MOMENTARY_LEFT LT(4, KC_V)
#define NEO_LAYER4_MOMENTARY_RIGHT LT(4, KC_M)

// mod-tap shortcuts base layer
#define MT_Z LGUI_T(KC_Z)
#define MT_X LALT_T(KC_X)
#define MT_C LCTL_T(KC_C)
#define MT_V NEO_LAYER4_MOMENTARY_LEFT
#define MT_M NEO_LAYER4_MOMENTARY_RIGHT
#define MT_COMM LCTL_T(KC_COMM)
#define MT_DOT LALT_T(KC_DOT)

// define combos
// both layer4 Taps to lock layer4
const uint16_t PROGMEM combo_layer4_enable[] = {NEO_LAYER4_MOMENTARY_LEFT, NEO_LAYER4_MOMENTARY_RIGHT, COMBO_END};
// both layer4 Taps on locked layer4 to return to default layer
const uint16_t PROGMEM combo_layer4_disable[] = {KC_PENT, KC_P1, COMBO_END};

combo_t key_combos[] = {
  COMBO(combo_layer4_enable, TG(_NEO_4)),
  COMBO(combo_layer4_disable, TG(_NEO_4)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      | NUHS |
 * | CAPS |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Del  |    |  F12  |------+------+------+------+------+------|
 * |      | (GUI)| (ALT)| (CTL)| (L4) |      |       |    |       |      | (L4) |(CTL) |(ALT) |      |      |
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | LGUI |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /(SHFT) /       \(SHFT)\  |      |      |      |
 *                   | LAlt | LOWER| ESC  | /Enter  /       \Space \  |BackSP| RAISE| RCtl |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5,                    KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_GRV,
  KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                    KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC,
  KC_NUHS, KC_A, KC_S, KC_D, KC_F, KC_G,                    KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, NEO_LAYER3_Y,
  KC_LSFT, MT_Z, MT_X, MT_C, MT_V, KC_B, KC_DEL,   KC_F12,  KC_N, MT_M, MT_COMM, MT_DOT, KC_SLSH, KC_LGUI,
   KC_LALT, MO(_LOWER), KC_ESC, LSFT_T(KC_ENT),    RSFT_T(KC_SPC), KC_BSPC, MO(_RAISE), KC_RCTL
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|  Del  |    |  F12  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /(SHFT) /       \(SHFT)\  |      |      |      |
 *                   | LAlt | LOWER| ESC  | /Enter  /       \Space \  |BackSP| RAISE| RCtl |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|  Del  |    |  F12  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /(SHFT) /       \(SHFT)\  |      |      |      |
 *                   | LAlt | LOWER| ESC  | /Enter  /       \Space \  |BackSP| RAISE| RCtl |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /(SHFT) /       \(SHFT)\  |      |      |      |
 *                   | LAlt | LOWER| ESC  | /Enter  /       \Space \  |BackSP| RAISE| RCtl |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DT_UP,   XXXXXXX,                   XXXXXXX, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DT_PRNT, _VIM_EXIT_TERMINAL,                   _KONAMI_CODE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DT_DOWN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  ),

/* NEO LAYER 4 equivalent
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |PG_UP |BackSP|  UP  | Del  |PG_DWN|                    |      |  7   |  8   |  9   |  +   |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | HOME | LEFT | DOWN |RIGHT | END  |-------.    ,-------|      |  4   |  5   |  6   |  ,   |  .   |
 * |------+------+------+------+------+------|       |    |PrtScr |------+------+------+------+------+------|
 * |      | (GUI)| (ALT)| (CTL)| (L4) |      |       |    |       |      | (L4) |(CTL) |(ALT) |      |      |
 * |      | ESC  | Tab  |Insert|Enter | UNDO |-------|    |-------|      |  1   |  2   |  3   |      | LGui |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /(SHFT) /       \(SHFT)\  |      |      |      |
 *                   | LAlt | LOWER| ESC  | /Enter  /       \  0   \  |BackSP| RAISE| RCtl |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_NEO_4] = LAYOUT(
  XXXXXXX, XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX,
  XXXXXXX, KC_PGUP,        KC_BSPC,        KC_UP,          KC_DEL,  KC_PGDN,                   XXXXXXX, KC_P7,   KC_P8,         KC_P9,         KC_PPLS, KC_PMNS,
  XXXXXXX, KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RGHT, KC_END,                    XXXXXXX, KC_P4,   KC_P5,         KC_P6,         KC_PCMM, KC_PDOT,
  XXXXXXX, LGUI_T(KC_ESC), LALT_T(KC_TAB), LCTL_T(KC_INS), KC_PENT, KC_UNDO, _______, KC_PSCR, XXXXXXX, KC_P1,   LCTL_T(KC_P2), LALT_T(KC_P3), XXXXXXX, KC_LGUI,
                                                _______, _______, _______, _______,    RSFT_T(KC_P0),  _______, _______, _______
  ),
};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

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
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
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

