/*
Copyright 2021 semicontinuity

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

#include "keymap.h"

#include QMK_KEYBOARD_H
#include "casemodes.h"
#include "layouts.h"
#include <stdio.h>


// Idea: Hold G + Right Home Row = Super+Arrows, to move windows

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [ENGRAM] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      KC_B,         KC_Y,         KC_O,         KC_U,               XXXXXXX,                                                XXXXXXX,            LT(F_S,KC_L),     LT(F_C,KC_D),  LT(F_A,KC_W),  KC_V,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      LGUI_T(KC_C), LALT_T(KC_I), LCTL_T(KC_E), LSFT_T(KC_A),       XXXXXXX,          KC_Z,                 KC_Q,           XXXXXXX,            LSFT_T(KC_H),     RCTL_T(KC_T),  LALT_T(KC_S),  RGUI_T(KC_N),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_G,         RALT_T(KC_X), KC_J,         KC_K,               XXXXXXX,                                                XXXXXXX,            KC_R,             KC_M,          RALT_T(KC_F),  KC_P,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                LT(MULTI, KC_TAB),                                                                              LT(FUNC, KC_DEL),
                                  KC_SPACE,     TD(TD_RAISE),       KC_COMMA,                                               KC_DOT,             TD(TD_LOWER),     KC_ENT,
                                                LT(MOUSE, KC_ESC),                                                                              LT(NUM, KC_BSPC)
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),
};
