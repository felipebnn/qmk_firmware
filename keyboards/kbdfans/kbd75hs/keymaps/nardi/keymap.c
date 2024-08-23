/* Copyright 2021 DZTECH <moyi4681@Live.cn>
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
#include "raw_hid.h"

#define KC_VUP KC_KB_VOLUME_UP
#define KC_VDWN KC_KB_VOLUME_DOWN

enum custom_keycodes {
    FN = SAFE_RANGE,
    FN2,
    // CTRBSPC,
    // CTRDEL,
    MAC_TOG,
    PAS_TOG,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_75_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_INS,  KC_DEL,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGUP,
        FN2,      KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGDN,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
        KC_LCTL,  KC_LGUI,  KC_LALT,                               KC_SPC,              KC_RALT,            FN,       KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    [1] = LAYOUT_75_ansi(
        _______,  KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_F21,   KC_F22,   KC_F23,   KC_F24,   _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  QK_BOOT,  _______,
        _______,  RGB_TOG,  RGB_M_P,  RGB_HUI,  RGB_HUD,  _______,  _______,  _______,  _______,  _______,  PAS_TOG,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MPLY,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  MAC_TOG,  _______,  _______,  _______,  _______,            KC_VUP,   _______,
        _______,  _______,  _______,                                _______,            _______,            _______,  _______,  _______,  KC_VDWN,  _______
    ),

    // [2] = LAYOUT_75_ansi(
    //     TO(0),    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_0,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PGUP,  KC_UP,    KC_PGDN,  _______,  _______,  _______,  _______,  _______,
    //     _______,  CTRBSPC,  KC_BSPC,  KC_DEL,   CTRDEL,   _______,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,   _______,            KC_PENT,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  CTRBSPC,  KC_BSPC,  KC_DEL,   CTRDEL,   _______,            _______,  _______,
    //     _______,  _______,  _______,                                _______,            _______,            _______,  _______,  _______,  _______,  _______
    // ),

    [2] = LAYOUT_75_ansi(
        TO(0),    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_0,  KC_PMNS,  KC_PPLS,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            KC_PENT,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,            _______,            _______,  _______,  _______,  _______,  _______
    ),

    [3] = LAYOUT_75_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,            _______,            _______,  _______,  _______,  _______,  _______
    )
};

#define TAP_DURATION 250
#define TURBO_DELAY 250

#define TAP_HOLD_MACRO(pressBlock, tapBlock, releaseBlock) do {                                 \
    if (record->event.pressed) {                                                                \
        pressBlock;                                                                             \
        lastPressTimer = timer_read();                                                          \
    } else if (lastKeycode == keycode && timer_elapsed(lastPressTimer) < TAP_DURATION) {        \
        tapBlock;                                                                               \
    } else {                                                                                    \
        releaseBlock;                                                                           \
    }                                                                                           \
    lastKeycode = keycode;                                                                      \
} while (0)

#define CLEAR_VARS() do {                  \
    if (record->event.pressed) {           \
        lastAccentKeycode = 0;             \
        /*secondToLastKeycode = lastKeycode;*/ \
        lastKeycode = keycode;             \
    }                                      \
} while (0)                                \

#define CAPSLOCK_STATE (host_keyboard_leds() & 2)
#define SHIFT_STATE (get_mods() & MOD_MASK_SHIFT)

#define REMAP_CODE(key) do { if (record->event.pressed) register_code(key); else unregister_code(key); } while (0)

enum nardi_flags {
    turboOn = 1 << 0,
};

uint16_t enabledFlags = 0;

uint16_t turboTimer = 0;
uint16_t lastPressTimer = 0;
uint16_t lastEventTimer = 0;

uint16_t lastKeycode = 0;
// uint16_t secondToLastKeycode = 0;
uint16_t lastAccentKeycode = 0;
uint16_t turboKeycode = 0;

uint8_t superDown = false;
uint8_t macMode = true;
uint8_t macDesktop = 0;
uint8_t passiveMode = false;

uint8_t strafeLeft = false;
uint8_t strafeRight = false;

void raw_hid_receive(uint8_t *data, uint8_t length) {
    if (length > 0 && data[0] == 'l') {
        macMode = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (passiveMode) {
        if (keycode == FN && record->event.pressed) {
            passiveMode = false;
        }
        return true;
    }

    if (record->event.pressed) {
        if (timer_elapsed(lastEventTimer) > 1000) {
            lastKeycode = 0;
            // secondToLastKeycode = 0;
        }
        lastEventTimer = timer_read();

        // // KC_MINS is to enable using -i on terminal. E.g. grep -i
        // if (lastKeycode == KC_I && keycode != KC_LSFT && (secondToLastKeycode < KC_A || secondToLastKeycode > KC_0) && secondToLastKeycode != KC_MINS) {
        //     switch (keycode) {
        //         case KC_SPC: case KC_COMM: case KC_DOT: case KC_ENT: case KC_QUOT:
        //             tap_code(KC_BSPC);
        //             tap_code16(LSFT(KC_I));
        //     }
        // }
    }

    if (macMode) {
        switch (keycode) {
        case KC_LCTL:
            REMAP_CODE(KC_LGUI);
            return false;

        case KC_LGUI:
            superDown = record->event.pressed;
            REMAP_CODE(KC_LCTL);
            return false;

        // case KC_GRV:
        //     if (superDown) {
        //         macDesktop = 0;
        //         return false;
        //     }
        //     break;

        // case KC_1: case KC_2: case KC_3: case KC_4: case KC_5: case KC_6: case KC_7: case KC_8: case KC_9: case KC_0:
        //     if (!superDown || SHIFT_STATE) {
        //         break;
        //     }
        //     if (!record->event.pressed) {
        //         return false;
        //     }
        //     uint8_t targetDesktop = keycode-KC_1;
        //     while (macDesktop > targetDesktop) {
        //         tap_code(KC_LEFT);
        //         --macDesktop;
        //     }
        //     while (macDesktop < targetDesktop) {
        //         tap_code(KC_RIGHT);
        //         ++macDesktop;
        //     }
        //     return false;
        }
    }

    switch (keycode) {
        case FN:
            TAP_HOLD_MACRO(layer_move(1), layer_move(0), layer_move(0));
            return false;

        case FN2:
            TAP_HOLD_MACRO(layer_move(2), layer_move(0), layer_move(0));
            return false;

        // case CTRBSPC:
        //     if (record->event.pressed) {
        //         register_code(KC_LCTL);
        //         register_code(KC_BSPC);
        //     } else {
        //         unregister_code(KC_LCTL);
        //         unregister_code(KC_BSPC);
        //     }
        //     break;

        // case CTRDEL:
        //     if (record->event.pressed) {
        //         register_code(KC_LCTL);
        //         register_code(KC_DEL);
        //     } else {
        //         unregister_code(KC_LCTL);
        //         unregister_code(KC_DEL);
        //     }
        //     break;

        case KC_LSFT: case KC_RSFT:
            if (macMode) {
                break;
            }
            if (record->event.pressed) {
                if (CAPSLOCK_STATE || (lastKeycode == keycode && timer_elapsed(lastPressTimer) < 2*TAP_DURATION)) {
                    tap_code(KC_CAPS);
                }

                lastKeycode = keycode;
                lastPressTimer = timer_read();
            }
            return true;

        case KC_ENT:
            if (CAPSLOCK_STATE) {
                tap_code(KC_CAPS);
            }
            break;

        case KC_6:
            if (!SHIFT_STATE || macMode) break;
            // FALLTHROUGH
        case KC_QUOT: case KC_GRV:
            if (get_mods() & MOD_MASK_CAG) break;
            CLEAR_VARS();

            if (record->event.pressed) {
                tap_code(keycode);
                // if (keycode != KC_6) {
                    tap_code(KC_SPC);
                // }

                lastAccentKeycode = SHIFT_STATE ? LSFT(keycode) : keycode;
            }

            // return keycode == KC_6;
            return false;

        case KC_SPC:
            if (lastAccentKeycode) {
                CLEAR_VARS();
                return false;
            }
            break;

        case KC_C: //Ç
            if (lastAccentKeycode != KC_QUOT) break;
            // FALLTHROUGH
        case KC_A:
            strafeLeft = record->event.pressed;
            if (strafeLeft && strafeRight) {
                unregister_code(KC_D);
            }
            // FALLTHROUGH
        case KC_E: case KC_I: case KC_O: case KC_U:
            if (record->event.pressed && (lastAccentKeycode == KC_QUOT || (lastAccentKeycode & KC_GRV) == KC_GRV || lastAccentKeycode == LSFT(KC_6))) {
                bool letter_shift_enabled = !(lastAccentKeycode & QK_LSFT) && SHIFT_STATE;

                tap_code(KC_BSPC);
                if (letter_shift_enabled) {
                    unregister_code(KC_LSFT);
                }
                tap_code16(lastAccentKeycode);
                if (letter_shift_enabled) {
                    register_code(KC_LSFT);
                }

                // So words like "aí" will keep working with the upperCaseI macro.
                CLEAR_VARS();
                // secondToLastKeycode = KC_A; // Any alphabet letter will work.
                return true;
            }
            break;

        case KC_D:
            strafeRight = record->event.pressed;
            if (strafeLeft && strafeRight) {
                unregister_code(KC_A);
            }
            break;

        case MAC_TOG:
            if (record->event.pressed) {
                macMode = !macMode;
                passiveMode = false;
            }
            return false;

        case PAS_TOG:
            if (record->event.pressed) {
                passiveMode = true;
                macMode = false;
                layer_move(0);
            }
            return false;

        case KC_LGUI:
            superDown = record->event.pressed;
            break;

        /********** TURBO **********/
        // case KC_Q:
        //     if (record->event.pressed) {
        //         enabledFlags |= turboOn;
        //     } else {
        //         enabledFlags &= ~turboOn;
        //     }
        //     turboTimer = timer_read() - TURBO_DELAY;
        //     turboKeycode = keycode;
        //     return false;
    }

    CLEAR_VARS();
    return true;
}

// void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
// }

// void matrix_scan_user(void) {
//     if (enabledFlags) {
//         if ((enabledFlags & turboOn) && timer_elapsed(turboTimer) >= TURBO_DELAY) {
//             tap_code(turboKeycode);
//             turboTimer = timer_read();
//         }
//     }
// }

// bool process_detected_host_os_kb(os_variant_t detected_os) {
//     if (!process_detected_host_os_user(detected_os)) {
//         return false;
//     }
//     macMode = (detected_os == OS_MACOS);
//     return true;
// }
