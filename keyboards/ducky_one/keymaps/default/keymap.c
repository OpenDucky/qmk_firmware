#include "ducky_one.h"
#include "string.h"

enum my_keycodes {
    LED_RESET = SAFE_RANGE,
    LED_LOW,
    LED_HIGH,
};

enum ducky_layers {
  _QWERTY,
  _FUNCTION,
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_108_ANSI( /* Base */
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4,   KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12,    KC_PSCR, KC_SLCK, KC_PAUS,    KC_MYCM, KC_CALC, KC_MPLY, KC_NO,
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,   KC_BSPC,       KC_INS,  KC_HOME, KC_PGUP,    KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,    KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,         KC_ENT,                                 KC_P4,   KC_P5,   KC_P6,
    KC_LSFT,           KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,   KC_RSFT,              KC_UP,               KC_P1,   KC_P2,    KC_P3,   KC_PENT,
    KC_LCTL, KC_LALT  ,  KC_LGUI,               KC_SPC,             KC_RALT,  KC_RGUI,  MO(_FUNCTION), KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT,        KC_P0,  KC_PDOT
  ),
  [_FUNCTION] = LAYOUT_108_ANSI( /* Base */
    LED_RESET, LED_LOW, LED_HIGH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};

const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

layer_state_t layer_state_set_user(layer_state_t layer) {
    switch(get_highest_layer(layer)) {
        case _QWERTY:
            led_matrix_data[4*16+15] = 0;
            break;
        case _FUNCTION:
            led_matrix_data[4*16+15] = 0x4F;
            break;
    }

    return layer;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LED_RESET:
            if (record->event.pressed) {
                for (size_t i = 0; i < 16 * 8; i++)
                {
                    led_matrix_data[i] = 0;
                }
            }
            return false;
        case LED_LOW:
            if (record->event.pressed) {
                for (size_t i = 0; i < 16 * 8; i++)
                {
                    led_matrix_data[i] = 0x4F;
                }
            }
            return false;
        case LED_HIGH:
            if (record->event.pressed) {
                for (size_t i = 0; i < 16 * 8; i++)
                {
                    led_matrix_data[i] = 0x2000;
                }
            }
            return false;
        default:
            break;
    }
    return true;
}
