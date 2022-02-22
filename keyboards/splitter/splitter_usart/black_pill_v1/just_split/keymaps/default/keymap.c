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


#define C_S(kc) (QK_LCTL | QK_LSFT| (kc))
#define A_S(kc) (QK_LALT | QK_LSFT| (kc))

// ******************************************
// Left pedal does not work, reason - unknown
// ******************************************

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [ENGRAM] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      KC_B,         KC_Y,         KC_O,         KC_U,               KC_Q,                                                   KC_Z,               LT(F_S,KC_L),     LT(F_C,KC_D),  LT(F_A,KC_W),  KC_V,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      LGUI_T(KC_C), LALT_T(KC_I), LCTL_T(KC_E), LSFT_T(KC_A),       KC_COMMA,                                               KC_DOT,             LSFT_T(KC_H),     RCTL_T(KC_T),  LALT_T(KC_S),  RGUI_T(KC_N),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_G,         RALT_T(KC_X), KC_J,         KC_K,               KC_UNDS,                                                KC_QUES,            KC_R,             KC_M,          RALT_T(KC_F),  KC_P,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|
      KC_B,                       LT(MULTI, KC_TAB),  KC_SPACE,     TD(TD_RAISE), LT(MOUSE, KC_ESC),    LT(FUNC, KC_DEL),   KC_ENT,             OSL(LOWER),       LT(NUM, KC_BSPC),             TD(TD_RAISE)
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [QWERTY] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      KC_Q,         KC_W,         KC_E,         KC_R,               KC_T,                                                   KC_Y,               LT(F_S,KC_U),     LT(F_C,KC_I),  LT(F_A,KC_O),  KC_P,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),       KC_G,                                                   KC_H,               LSFT_T(KC_J),     RCTL_T(KC_K),  LALT_T(KC_L),  RGUI_T(KC_SCLN),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_Z,         KC_X,         KC_C,         KC_V,               KC_B,                                                   KC_N,               KC_M,             KC_COMM,       RALT_T(KC_DOT),KC_SLASH,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    _______,      _______,            _______,     _______,               _______,            _______,            _______,          _______,                      _______
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  // Russian layout: Switched on left keyboard half: Win+Space
  //  б             ы             о             у                   ч                                                       з                   л                 д              ш              в
  //  ц             и             е             а                   ,                                                       .                   х                 т              с              н
  //  г             ж             й             к                   _                                                       ?                   р                 м              ф              п
  [RPE] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      KC_COMMA,     KC_S,         KC_J,         KC_E,               KC_P,                                                   KC_X,               LT(F_S,KC_D),     LT(F_C,KC_L),  LT(F_A,KC_I),  KC_D,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      LGUI_T(KC_W), LALT_T(KC_B), LCTL_T(KC_T), LSFT_T(KC_F),       KC_QUES,                                                KC_SLASH,           KC_LBRACKET,      KC_N,          KC_C,          KC_Y,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_U,         KC_SCOLON,    KC_Q,         KC_R,               _______,                                                KC_AMPR,            KC_H,             KC_V,          KC_A,          KC_G,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|
      XXXXXXX,                    _______,      _______,            _______,     _______,               _______,            _______,            OSL(R_LOWER),     _______,                      _______
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

//[RPE_EXT] = LAYOUT_split_3x5_3_p(
////,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
//    XXXXXXX,      KC_RBRACKET,  KC_GRAVE,     KC_DOT,             XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       KC_O,          XXXXXXX,
////|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
//    XXXXXXX,      KC_M,         KC_QUOTE,     KC_Z,               XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
////|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
//    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
////|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
//    XXXXXXX,                    XXXXXXX,      XXXXXXX,            XXXXXXX,     KC_ESC,                XXXXXXX,            XXXXXXX,            XXXXXXX,          XXXXXXX,                      XXXXXXX
////  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
//),

  // with underscore (inaccessible from QWERTY)
  [LOWER] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      KC_EXLM,      KC_LT,        KC_GT,        KC_AMPR,            KC_CIRC,                                                KC_TILDE,           KC_AT,            KC_LBRACKET,   KC_RBRACKET,   KC_GRAVE,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_MINUS,     KC_LPRN,      KC_RPRN,      KC_EQUAL,           KC_0,                                                   KC_2,               KC_SCOLON,        KC_LCBR,       KC_RCBR,       KC_DQUO,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_PLUS,      KC_ASTERISK,  KC_SLASH,     KC_PIPE,            KC_1,                                                   KC_3,               KC_COLON,         KC_DOLLAR,     KC_PERC,       KC_QUOTE,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    KC_HASH,      KC_SPACE,           KC_UNDS,     C(KC_SLASH),           KC_CIRC,            KC_BSLASH,          KC_COMMA,         KC_TILDE,                     XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [R_LOWER] = LAYOUT_split_3x5_3_p( // LOWER layer, when activated from RPE (russian layout): same as LOWER, except characters that cannot be typed + extra russian characters (э ё ю я ь ъ щ)
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      KC_EXLM,      KC_QUOT,/*э*/ KC_GRV,/*ё*/  KC_DOT,  /*ю*/      KC_CIRC,                                                _______,            XXXXXXX,          XXXXXXX,       KC_O,   /*щ*/  XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_MINUS,     KC_LPRN,      KC_RPRN,      KC_EQUAL,           KC_0,                                                   KC_2,               KC_DOLLAR,/*;*/   KC_M,   /*ь*/  KC_RBRC,/*ъ*/  KC_AT,   /*"*/
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_PLUS,      KC_ASTERISK,  KC_PIPE,/*/*/ KC_Z,    /*я*/      KC_1,                                                   KC_3,               KC_CIRC,  /*:*/   XXXXXXX,       KC_PERC,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    KC_HASH,/*№*/ KC_SPACE,           KC_UNDS,     XXXXXXX,               XXXXXXX,            KC_BSLASH,          KC_QUES,  /*,*/   XXXXXXX,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [MULTI] = LAYOUT_split_3x5_3_p(
  //--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
     LCTL(KC_B),   LCTL(KC_Y),   LCTL(KC_O),   LCTL(KC_U),         LCTL(KC_Q),                                             KC_PQUEUE,          KC_LINKED,        KC_ARRAY,      KC_LIST,       KC_DEQUEUE,
  //-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
     LCTL(KC_C),   LCTL(KC_I),   LCTL(KC_E),   LCTL(KC_A),         C(KC_COMM),                                             KC_COMP,            KC_LT,            KC_COMMA,      KC_SPACE,      KC_GT,
  //-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
     LCTL(KC_G),   LCTL(KC_X),   LCTL(KC_J),   LCTL(KC_K),         C(KC_SCLN),                                             KC_ENTRY,           KC_TREE,          KC_HASH_,      KC_MAP,        KC_SET,
  //-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
     XXXXXXX,                    XXXXXXX,      C_S(KC_C),          C_S(KC_V),   TG(QWERTY),            KC_NEW,             KC_INT,             KC_STR,           KC_CHAR,                      XXXXXXX
  // =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [MOUSE] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      LALT(KC_B),   LALT(KC_Y),   LALT(KC_O),   LALT(KC_U),         LALT(KC_Q),                                             KC_CUT,             KC_PASTE,         XXXXXXX,       XXXXXXX,       KC_COPY,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      LALT(KC_C),   LALT(KC_I),   LALT(KC_E),   LALT(KC_A),         A(KC_COMM),                                             KC_UNDO,            KC_MS_LEFT,       KC_MS_DOWN,    KC_MS_UP,      KC_MS_RIGHT,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      LALT(KC_G),   LALT(KC_X),   LALT(KC_J),   LALT(KC_K),         A(KC_SCLN),                                             XXXXXXX,            KC_WH_L,          KC_WH_D,       KC_WH_U,       KC_WH_R,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    KC_SWATCH1,   KC_SWATCH2,         KC_SWATCH3,  XXXXXXX,               C(KC_SLASH),        KC_BTN1,            KC_BTN3,          KC_BTN2,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [FUNC] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      KC_F12,       KC_F7,        KC_F8,        KC_F9,              KC_PSCR,                                                LALT(KC_Z),         LALT(KC_L),       LALT(KC_D),    LALT(KC_W),    LALT(KC_V),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_F11,       KC_F4,        KC_F5,        KC_F6,              KC_SLCK,                                                LALT(KC_DOT),       LALT(KC_H),       LALT(KC_T),    LALT(KC_S),    LALT(KC_N),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_F10,       KC_F1,        KC_F2,        KC_F3,              KC_PAUSE,                                               LALT(KC_QUOTE),     LALT(KC_R),       LALT(KC_M),    LALT(KC_F),    LALT(KC_P),
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    LALT(KC_TAB), KC_INSERT,          KC_APP,      LALT(KC_ESC),          XXXXXXX,            XXXXXXX,            XXXXXXX,          XXXXXXX,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  // TG(NUM) does not work
  [NUM] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      KC_DOT,       KC_7,         KC_8,         KC_9,               KC_SLASH,                                               LCTL(KC_Z),         LCTL(KC_L),       LCTL(KC_D),    LCTL(KC_W),    LCTL(KC_V),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_MINUS,     KC_4,         KC_5,         KC_6,               KC_EQUAL,                                               LCTL(KC_DOT),       LCTL(KC_H),       LCTL(KC_T),    LCTL(KC_S),    LCTL(KC_N),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_PLUS,      KC_1,         KC_2,         KC_3,               KC_ASTR,                                                LCTL(KC_QUOTE),     LCTL(KC_R),       LCTL(KC_M),    LCTL(KC_F),    LCTL(KC_P),
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    KC_DOT,       KC_0,               KC_SPACE,    XXXXXXX,               XXXXXXX,            XXXXXXX,            XXXXXXX,          XXXXXXX,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  // // KC_EXSEL is a dummy keycode, to implement Shift locking
  [NAV2] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      A(KC_LEFT),   A(KC_DOWN),   A(KC_UP),     A(KC_RIGHT),        C(KC_A),                                                C(KC_W),            A(KC_HOME),       A(KC_PGDOWN),  A(KC_PGUP),    A(KC_END),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      C(KC_LEFT),   C(KC_DOWN),   C(KC_UP),     C(KC_RIGHT),        C(KC_C),                                                C(KC_V),            KC_LEFT,          KC_DOWN,       KC_UP,         KC_RIGHT,
  //|-------------+-------------+-------------+---------------+----------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      C(KC_HOME),   C(KC_PGDOWN), C(KC_PGUP),   C(KC_END),          C(KC_Z),                                                C(KC_X),            KC_HOME,          KC_PGDOWN,     KC_PGUP,       KC_END,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    KC_TAB,       C(KC_ENT),          KC_ALT_ERASE, KC_ESC,               KC_DEL,             KC_ENT,             TT(S_NAV2),       KC_BSPC,                      KC_ALT_ERASE
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

//[C_NAV] = LAYOUT_split_3x5_3_p(
////,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
//    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
////|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
//    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            C(KC_LEFT),       C(KC_DOWN),    C(KC_UP),      C(KC_RIGHT),
////|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
//    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            C(KC_HOME),       C(KC_PGDOWN),  C(KC_PGUP),    C(KC_END),
////|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
//    XXXXXXX,                    XXXXXXX,      XXXXXXX,            XXXXXXX,     XXXXXXX,               XXXXXXX,            XXXXXXX,            XXXXXXX,          XXXXXXX,                      XXXXXXX
////  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
//),

  // // TD_SINGLE_TAP_THEN_HOLD
  [S_NAV2] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      A_S(KC_LEFT), A_S(KC_DOWN), A_S(KC_UP),   A_S(KC_RIGHT),      C_S(KC_A),                                              C_S(KC_W),          A_S(KC_HOME),     A_S(KC_PGDOWN),A_S(KC_PGUP),  A_S(KC_END),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      C_S(KC_LEFT), C_S(KC_DOWN), C_S(KC_UP),   C_S(KC_RIGHT),      C_S(KC_C),                                              C_S(KC_V),          S(KC_LEFT),       S(KC_DOWN),    S(KC_UP),      S(KC_RIGHT),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      C_S(KC_HOME), C_S(KC_PGDN), C_S(KC_PGUP), C_S(KC_END),        C_S(KC_Z),                                              C_S(KC_X),          S(KC_HOME),       S(KC_PGDOWN),  S(KC_PGUP),    S(KC_END),
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    A(KC_TAB),    A(KC_ENT),          KC_ALT_ERASE, A(KC_ESC),            XXXXXXX,            XXXXXXX,            TT(S_NAV2),       C(KC_SLASH),                  KC_ALT_ERASE
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

//[CS_NAV] = LAYOUT_split_3x5_3_p(
////,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
//    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
////|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
//    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            C_S(KC_LEFT),     C_S(KC_DOWN),  C_S(KC_UP),    C_S(KC_RIGHT),
////|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
//    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            C_S(KC_HOME),     C_S(KC_PGDOWN),C_S(KC_PGUP),  C_S(KC_END),
////|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
//    XXXXXXX,                    XXXXXXX,      XXXXXXX,            XXXXXXX,     XXXXXXX,               XXXXXXX,            XXXXXXX,            XXXXXXX,          XXXXXXX,                      XXXXXXX
////  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
//)


  [F_A] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      A(KC_F12),    A(KC_F7),     A(KC_F8),     A(KC_F9),           A(KC_PSCR),                                             XXXXXXX,            KC_LSFT,          KC_LCTL,       KC_LALT,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      A(KC_F11),    A(KC_F4),     A(KC_F5),     A(KC_F6),           A(KC_SLCK),                                             XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      A(KC_F10),    A(KC_F1),     A(KC_F2),     A(KC_F3),           A(KC_PAUSE),                                            XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    XXXXXXX,      A(KC_INS),          A(KC_APP),   XXXXXXX,               XXXXXXX,            XXXXXXX,            XXXXXXX,          XXXXXXX,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),


  [F_C] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      C(KC_F12),    C(KC_F7),     C(KC_F8),     C(KC_F9),           C(KC_PSCR),                                             XXXXXXX,            KC_LSFT,          KC_LCTL,       KC_LALT,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      C(KC_F11),    C(KC_F4),     C(KC_F5),     C(KC_F6),           C(KC_SLCK),                                             XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      C(KC_F10),    C(KC_F1),     C(KC_F2),     C(KC_F3),           C(KC_PAUSE),                                            XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    XXXXXXX,      C(KC_INS),          C(KC_APP),   XXXXXXX,               XXXXXXX,            XXXXXXX,            XXXXXXX,          XXXXXXX,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [F_S] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      S(KC_F12),    S(KC_F7),     S(KC_F8),     S(KC_F9),           S(KC_PSCR),                                             XXXXXXX,            KC_LSFT,          KC_LCTL,       KC_LALT,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      S(KC_F11),    S(KC_F4),     S(KC_F5),     S(KC_F6),           S(KC_SLCK),                                             XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      S(KC_F10),    S(KC_F1),     S(KC_F2),     S(KC_F3),           S(KC_PAUSE),                                            XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    XXXXXXX,      S(KC_INS),          S(KC_APP),   XXXXXXX,               XXXXXXX,            XXXXXXX,            XXXXXXX,          XXXXXXX,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),
};
