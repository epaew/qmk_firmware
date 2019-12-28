/* Copyright 2019 peraneko
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        C(KC_Z), C(KC_X), C(KC_C), C(KC_V),
        KC_LCTL, KC_LSFT, KC_LALT, C(KC_S)
    )
};

/* Rotary encoder settings */
void encoder_update_user(uint16_t index, bool clockwise) {
   if (clockwise) {
        tap_code(KC_MS_WH_DOWN);  // Rotary encoder clockwise
    } else {
        tap_code(KC_MS_WH_UP);    // Rotary encoder reverse clockwise
    }
}
