/*
Copyright 2021 CapsUnlocked

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

// #define MOUSEKEY_WHEEL_DELAY 0
// #define MOUSEKEY_WHEEL_INTERVAL 100
// #define MOUSEKEY_WHEEL_MAX_SPEED 16
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 40

#define MK_KINETIC_SPEED
#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 16
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS 32
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48
#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
             MO(1),
    KC_PGDOWN, KC_UP,    KC_PGUP,
    KC_LEFT,   KC_DOWN,  KC_RGHT
  ),
  [1] = LAYOUT(
             _______,
    RGB_MOD,  KC_MUTE,  RESET,
    KC_MPRV,  KC_MPLY,  KC_MNXT
  ),
};

// Volume up/down on the encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (biton32(layer_state) == 0) {
    if (clockwise) {
      tap_code(KC_WH_D);
    }
    else {
      tap_code(KC_WH_U);
    }
  }
  if (biton32(layer_state) == 1) {
    if (clockwise) {
      tap_code_delay(KC_VOLU, 10);
    }
    else {
      tap_code_delay(KC_VOLD, 10);
    }
  }

  return true;
}
