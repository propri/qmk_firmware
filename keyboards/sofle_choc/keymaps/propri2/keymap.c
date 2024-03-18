/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NEO_4,
    
    _NUM_LAYERS, // ~ sofle_layers.length
};

enum custom_keycodes {
    // KC_PRVWD = SAFE_RANGE,
    // KC_NXTWD,
    // KC_LSTRT,
    // KC_LEND,
    // KC_DLINE
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
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LCMD | LALT | /Enter  /       \Space \  | RALT | RCMD | RGUI | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_NUHS,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, NEO_LAYER3_Y,
    KC_LSFT,  MT_Z,   MT_X,    MT_C,    MT_V,    KC_B,    KC_DEL,    KC_F12, KC_N,     MT_M,     MT_COMM, MT_DOT,  KC_SLSH, KC_LGUI,
                      KC_LALT, TL_LOWR, KC_ESC, KC_LSFT, KC_ENT,    KC_SPC, KC_RSFT, KC_BSPC, TL_UPPR,  KC_RCTL
),
/* LOWER
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Right|  Del | Bspc |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
    _______, _______, _______, _______, _______,  _______,                         _______, _______,   _______, _______,   _______,  _______,
    // _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX,  XXXXXXX,                         KC_PGUP, KC_PRVWD,  KC_UP,   KC_NXTWD,  KC_DLINE, KC_BSPC,
    _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX,  XXXXXXX,                         KC_PGUP, XXXXXXX,  KC_UP,   XXXXXXX,  XXXXXXX, KC_BSPC,
    _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,  KC_CAPS,                         KC_PGDN, KC_LEFT,   KC_DOWN, KC_RGHT,   KC_DEL,   KC_BSPC,
    // _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, XXXXXXX, _______,       _______, XXXXXXX, KC_LSTRT,  XXXXXXX, KC_LEND,   XXXXXXX,  _______,
    _______, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, XXXXXXX, _______,       _______, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,   XXXXXXX,  _______,
                      _______, _______, _______,  _______, _______,       _______, _______,  _______,   _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
    _______, KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_GRV,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
    _______, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    _______, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                     _______, _______, _______, _______,  _______,       _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BOOT | Spd+ | Val+ | Sat+ | Hue+ |Mode+ |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Spd- | Val- | Sat- | Hue- |Mode- |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |MacWin|      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    QK_BOOT, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MODE_FORWARD,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_MODE_REVERSE,                       XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
    CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
)
};

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
        // case KC_PRVWD:
        //     if (record->event.pressed) {
        //         if (keymap_config.swap_lctl_lgui) {
        //             register_mods(mod_config(MOD_LALT));
        //             register_code(KC_LEFT);
        //         } else {
        //             register_mods(mod_config(MOD_LCTL));
        //             register_code(KC_LEFT);
        //         }
        //     } else {
        //         if (keymap_config.swap_lctl_lgui) {
        //             unregister_mods(mod_config(MOD_LALT));
        //             unregister_code(KC_LEFT);
        //         } else {
        //             unregister_mods(mod_config(MOD_LCTL));
        //             unregister_code(KC_LEFT);
        //         }
        //     }
        //     return false;
        // case KC_NXTWD:
        //      if (record->event.pressed) {
        //         if (keymap_config.swap_lctl_lgui) {
        //             register_mods(mod_config(MOD_LALT));
        //             register_code(KC_RIGHT);
        //         } else {
        //             register_mods(mod_config(MOD_LCTL));
        //             register_code(KC_RIGHT);
        //         }
        //     } else {
        //         if (keymap_config.swap_lctl_lgui) {
        //             unregister_mods(mod_config(MOD_LALT));
        //             unregister_code(KC_RIGHT);
        //         } else {
        //             unregister_mods(mod_config(MOD_LCTL));
        //             unregister_code(KC_RIGHT);
        //         }
        //     }
        //     return false;
        // case KC_LSTRT:
        //     if (record->event.pressed) {
        //         if (keymap_config.swap_lctl_lgui) {
        //              // CMD-arrow on Mac, but we have CTL and GUI swapped
        //             register_mods(mod_config(MOD_LCTL));
        //             register_code(KC_LEFT);
        //         } else {
        //             register_code(KC_HOME);
        //         }
        //     } else {
        //         if (keymap_config.swap_lctl_lgui) {
        //             unregister_mods(mod_config(MOD_LCTL));
        //             unregister_code(KC_LEFT);
        //         } else {
        //             unregister_code(KC_HOME);
        //         }
        //     }
        //     return false;
        // case KC_LEND:
        //     if (record->event.pressed) {
        //         if (keymap_config.swap_lctl_lgui) {
        //             // CMD-arrow on Mac, but we have CTL and GUI swapped
        //             register_mods(mod_config(MOD_LCTL));
        //             register_code(KC_RIGHT);
        //         } else {
        //             register_code(KC_END);
        //         }
        //     } else {
        //         if (keymap_config.swap_lctl_lgui) {
        //             unregister_mods(mod_config(MOD_LCTL));
        //             unregister_code(KC_RIGHT);
        //         } else {
        //             unregister_code(KC_END);
        //         }
        //     }
        //     return false;
        // case KC_DLINE:
        //     if (record->event.pressed) {
        //         register_mods(mod_config(MOD_LCTL));
        //         register_code(KC_BSPC);
        //     } else {
        //         unregister_mods(mod_config(MOD_LCTL));
        //         unregister_code(KC_BSPC);
        //     }
        //     return false;
        // case KC_COPY:
        //     if (record->event.pressed) {
        //         // CMD-c on Mac, but we have CTL and GUI swapped
        //         register_mods(mod_config(MOD_LCTL));
        //         register_code(KC_C);
        //     } else {
        //         unregister_mods(mod_config(MOD_LCTL));
        //         unregister_code(KC_C);
        //     }
        //     return false;
        // case KC_PASTE:
        //     if (record->event.pressed) {
        //         // CMD-v on Mac, but we have CTL and GUI swapped
        //         register_mods(mod_config(MOD_LCTL));
        //         register_code(KC_V);
        //     } else {
        //         unregister_mods(mod_config(MOD_LCTL));
        //         unregister_code(KC_V);
        //     }
        //     return false;
        // case KC_CUT:
        //     if (record->event.pressed) {
        //         // CMD-x on Mac, but we have CTL and GUI swapped
        //         register_mods(mod_config(MOD_LCTL));
        //         register_code(KC_X);
        //     } else {
        //         unregister_mods(mod_config(MOD_LCTL));
        //         unregister_code(KC_X);
        //     }
        //     return false;
        //     return false;
        // case KC_UNDO:
        //     if (record->event.pressed) {
        //         // CMD-z on Mac, but we have CTL and GUI swapped
        //         register_mods(mod_config(MOD_LCTL));
        //         register_code(KC_Z);
        //     } else {
        //         unregister_mods(mod_config(MOD_LCTL));
        //         unregister_code(KC_Z);
        //     }
        //     return false;
        case NEO_LAYER3_Y:
            return process_tap_or_long_press_custom_mod_key(record, KC_NUHS);
        case _KONAMI_CODE:
            if (record->event.pressed) {
                // "ba" because browsers always use qwerty layout?
                // nope, in citrix ist es gemappt -.-'
                SEND_STRING(SS_DELAY(10)SS_TAP(X_UP)SS_DELAY(10)SS_TAP(X_UP)SS_DELAY(10)SS_TAP(X_DOWN)SS_DELAY(10)SS_TAP(X_DOWN)SS_DELAY(10)SS_TAP(X_LEFT)SS_DELAY(10)SS_TAP(X_RGHT)SS_DELAY(10)SS_TAP(X_LEFT)SS_DELAY(10)SS_TAP(X_RIGHT)SS_DELAY(10)"ba");
            }
            return false;
        case _VIM_EXIT_TERMINAL:
            if (record->event.pressed) {
                // ctrl-a ctrl-j because neo makes it u j
                SEND_STRING(SS_LCTL(SS_DOWN(X_CAPS)SS_DELAY(20)"a"SS_DELAY(50)SS_UP(X_CAPS)SS_DELAY(20)"j"));
            }
            return false;
        default:
            return true;
    }
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif
