/*
 * Copyright (c) 2018 Jonathan A. Kollasch
 *           (c) 2020 Yaotian Feng, Codetector <codetector@codetector.cn>
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

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "config.h"
#include "ducky_one.h"
#include "quantum.h"
#include "raw_hid.h"

#define MIN(A, B) (A < B ? A : B)

// Default keymaps
extern const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t keymaps_size;

void OVERRIDE matrix_init_kb(void) {
    matrix_init_user();
}

bool OVERRIDE process_record_kb(uint16_t keycode, keyrecord_t *record) {
    return process_record_user(keycode, record);
}
