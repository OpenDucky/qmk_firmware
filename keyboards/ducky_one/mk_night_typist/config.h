/*
 * Copyright (c) 2018 Charlie Waters
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

#pragma once

#include "layouts.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x04d9
#define PRODUCT_ID      0x0141
#define DEVICE_VER      0x0001
#define MANUFACTURER    Holtek
#define PRODUCT         MK Night Typist QMK
#define DESCRIPTION     MK Night Typist with QMK
#define NAME_SLUG       "ducky_one/mk_night_typist"


// key matrix size
#define MATRIX_ROWS 15
#define MATRIX_COLS 8
// layer size: MATRIX_ROWS * MATRIX_COLS * sizeof(uint16_t) = 144 bytes

// Max available layers
#define MAX_LAYERS 8
// keymaps size: layer size * MAX_LAYERS = 1152 bytes

#define KEYMAP_60_ANSI
// Number of supported layouts
#define NUM_LAYOUTS 4

// #include "layouts.h"

// Matrix keymap

#define KEYMAP( \
    K00,      K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K60, K61,     K62, K63, K64,      K65, K66, K67, K68, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K70, K71, K72,     K73, K74, K75,      K76, K77, K78, K69,  \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K80, K81, K82,     K83, K84, K85,      K86, K87, K79, K6A, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K91,      K93,                         K96, K97, K88, \
    K40,      K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A,      K90,          K95,           K98, K99, K89, K7A, \
    K50, K51, K52,                K53,                K54, K55, K56, K57,     K58, K59, K5A,      K9A,      K8A \
) { \
    /*            COL1   COL2   COL3   COL4   COL5   COL6   COL7   COL8   */ \
    /* ROW1  */ { K00,   K01,   K02,   K03,   KC_NO, KC_NO, K62,   K63,   }, \
    /* ROW2  */ { K04,   K05,   K06,   K64,   K68,   K67,   K65,   K66,   }, \
    /* ROW3  */ { K10,   K11,   K20,   K21,   K30,   K31,   K40,   K41,   }, \
    /* ROW4  */ { K12,   K13,   K22,   K23,   K32,   K33,   K42,   K43,   }, \
    /* ROW5  */ { K14,   K15,   K24,   K25,   K34,   K35,   K44,   K45,   }, \
    /* ROW6  */ { K16,   K17,   K26,   K27,   K36,   K37,   K46,   K47,   }, \
    /* ROW7  */ { K18,   K19,   K28,   K29,   K38,   K39,   K48,   K49,   }, \
    /* ROW8  */ { K1A,   K70,   K2A,   K80,   K3A,   K91,   K4A,   K90,   }, \
    /* ROW9  */ { K71,   K72,   K81,   K82,   K93,   KC_NO, K57,   KC_NO, }, \
    /* ROW10 */ { K73,   K74,   K83,   K84,   K56,   K95,   K59,   K58,   }, \
    /* ROW11 */ { K75,   KC_NO, K85,   K0A,   K60,   K61,   K5A,   K9A,   }, \
    /* ROW12 */ { K07,   K08,   K09,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, }, \
    /* ROW13 */ { K76,   K77,   K86,   K87,   K96,   K97,   K98,   K99,   }, \
    /* ROW14 */ { K78,   K69,   K79,   K6A,   K88,   K7A,   K89,   K8A,   }, \
    /* ROW15 */ { KC_NO, KC_NO, K51,   K50,   K52,   K53,   K54,   K55,   }, \
}

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 10

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is userful for the Windows task manager shortcut (ctrl+shift+esc).
 */
// #define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
#define FORCE_NKRO

/*
 * Magic Key Options
 *
 * Magic keys are hotkey commands that allow control over firmware functions of
 * the keyboard. They are best used in combination with the HID Listen program,
 * found here: https://www.pjrc.com/teensy/hid_listen.html
 *
 * The options below allow the magic key functionality to be changed. This is
 * useful if your keyboard/keypad is missing keys and you want magic key support.
 *
 */

/* key combination for magic key command */
/*
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)
*/

/* control how magic key switches layers */
//#define MAGIC_KEY_SWITCH_LAYER_WITH_FKEYS  true
//#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS  true
//#define MAGIC_KEY_SWITCH_LAYER_WITH_CUSTOM false

/* override magic key keymap */
//#define MAGIC_KEY_SWITCH_LAYER_WITH_FKEYS
//#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS
//#define MAGIC_KEY_SWITCH_LAYER_WITH_CUSTOM
//#define MAGIC_KEY_HELP1          H
//#define MAGIC_KEY_HELP2          SLASH
//#define MAGIC_KEY_DEBUG          D
//#define MAGIC_KEY_DEBUG_MATRIX   X
//#define MAGIC_KEY_DEBUG_KBD      K
//#define MAGIC_KEY_DEBUG_MOUSE    M
//#define MAGIC_KEY_VERSION        V
//#define MAGIC_KEY_STATUS         S
//#define MAGIC_KEY_CONSOLE        C
//#define MAGIC_KEY_LAYER0_ALT1    ESC
//#define MAGIC_KEY_LAYER0_ALT2    GRAVE
//#define MAGIC_KEY_LAYER0         0
//#define MAGIC_KEY_LAYER1         1
//#define MAGIC_KEY_LAYER2         2
//#define MAGIC_KEY_LAYER3         3
//#define MAGIC_KEY_LAYER4         4
//#define MAGIC_KEY_LAYER5         5
//#define MAGIC_KEY_LAYER6         6
//#define MAGIC_KEY_LAYER7         7
//#define MAGIC_KEY_LAYER8         8
//#define MAGIC_KEY_LAYER9         9
//#define MAGIC_KEY_BOOTLOADER     R
//#define MAGIC_KEY_LOCK           CAPS
//#define MAGIC_KEY_EEPROM         E
//#define MAGIC_KEY_NKRO           N
//#define MAGIC_KEY_SLEEP_LED      Z

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINTg

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

