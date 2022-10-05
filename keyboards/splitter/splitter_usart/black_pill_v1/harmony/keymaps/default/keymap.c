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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [ENGRAM] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      KC_B,         KC_Y,         KC_O,         KC_U,               XXXXXXX,                                                XXXXXXX,            KC_L,             LT(F_C,KC_D),  LT(F_A,KC_W),  KC_V,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      LGUI_T(KC_C), LALT_T(KC_I), LCTL_T(KC_E), LSFT_T(KC_A),       XXXXXXX,          KC_Z,                 KC_Q,           XXXXXXX,            LSFT_T(KC_H),     RCTL_T(KC_T),  LALT_T(KC_S),  RGUI_T(KC_N),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_G,         RALT_T(KC_X), KC_J,         KC_K,               XXXXXXX,                                                XXXXXXX,            KC_R,             KC_M,          RALT_T(KC_F),  KC_P,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                LT(MULTI, KC_ESC),                                                                              LT(NUM, KC_DEL),
                                  KC_SPACE,     TD(TD_RAISE),       KC_DOT,                                                 OSM(MOD_LSFT),      TD(TD_LOWER),     KC_ENT,
                                                LT(MOUSE, KC_TAB),                                                                              LT(FUNC, KC_BSPC)
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),


  // Engram TURBO layer: these character keys lose their double-purpose and become ordinary keys
    [ENGRAM_T] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      _______,      _______,      _______,      _______,            _______,                                                _______,            KC_L,             KC_D,          KC_W,          _______,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      _______,      KC_I,         KC_E,         KC_A,               _______,          _______,           _______,           _______,            KC_H,             KC_T,          KC_S,          KC_N,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      _______,      KC_X,         KC_J,         KC_K,               _______,                                                _______,            _______,          _______,       KC_F,          _______,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                _______,                                                                                        _______,
                                  _______,      _______,            _______,                                                _______,            _______,          _______,
                                                _______,                                                                                        _______
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),


  // QWERTY is not available, not enough keys
    [QWERTY] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                XXXXXXX,                                                                                        XXXXXXX,
                                  KC_SPACE,     XXXXXXX,            XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,
                                                XXXXXXX,                                                                                        XXXXXXX
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),


  // Russian layout
  //  б             ы             о             у                   ч                                                       з                   л                 д              ш              в
  //  ц             и             е             а                                                                                               х                 т              с              н
  //  г             ж             й             к                                                                                               р                 м              ф              п
    [RPE] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      KC_COMMA,     KC_S,         KC_J,         KC_E,               XXXXXXX,                                                XXXXXXX,            LT(F_S,KC_K),     LT(F_C,KC_L),  LT(F_A,KC_I),  KC_D,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      LGUI_T(KC_W), LALT_T(KC_B), LCTL_T(KC_T), LSFT_T(KC_F),       XXXXXXX,          KC_P,                 KC_X,           XXXXXXX,            LSFT_T(KC_LBRC),  RCTL_T(KC_N),  LALT_T(KC_C),  RGUI_T(KC_Y),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_U,         KC_SCOLON,    KC_Q,         KC_R,               XXXXXXX,                                                XXXXXXX,            KC_H,             KC_V,          KC_A,          KC_G,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                _______,                                                                                        _______,
                                  _______,      _______,            KC_SLASH,                                               _______,            _______,         _______,
                                                _______,                                                                                        _______
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),


    [LOWER] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      KC_EXLM,      KC_LT,        KC_GT,        KC_AMPR,            XXXXXXX,                                                XXXXXXX,            KC_AT,            KC_RBRACKET,   KC_LBRACKET,   KC_GRAVE,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_MINUS,     KC_LPRN,      KC_RPRN,      KC_EQUAL,           XXXXXXX,          KC_CIRC,              KC_TILDE,       XXXXXXX,            KC_SCOLON,        KC_RCBR,       KC_LCBR,       KC_DQUO,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_PLUS,      KC_ASTERISK,  KC_SLASH,     KC_PIPE,            XXXXXXX,                                                XXXXXXX,            KC_COLON,         KC_DOLLAR,     KC_PERC,       KC_QUOTE,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                KC_HASH,                                                                                        KC_0,
                                  KC_SPACE,     KC_UNDS,            KC_QUES,                                                KC_2,               XXXXXXX,          KC_COMMA,
                                                KC_BSLASH,                                                                                      KC_1
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),


  // LOWER layer, when activated from RPE (russian layout): same as LOWER, except characters that cannot be typed + extra russian characters (э ё ю я ь ъ щ)
  //                э             ё             ю                                                                           з                                                    щ
  //                                                                                                                                            ;                 ь              ъ              "
  //                              /             я                                                                                               :
    [R_LOWER] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      KC_EXLM,      KC_QUOT,      KC_GRV,       KC_DOT,             XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       KC_LBRACKET,   XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_MINUS,     KC_LPRN,      KC_RPRN,      KC_EQUAL,           XXXXXXX,          KC_CIRC,              KC_TILDE,       XXXXXXX,            KC_DOLLAR,        KC_M,          KC_RBRC,       KC_AT,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_PLUS,      KC_ASTERISK,  KC_PIPE,      KC_Z,               XXXXXXX,                                                XXXXXXX,            KC_CIRC,          XXXXXXX,       KC_PERC,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                KC_HASH, /* № */                                                                                KC_0,
                                  KC_SPACE,     KC_UNDS,            KC_AMPR, /* ? */                                        KC_2,               XXXXXXX,          KC_SLASH, // ,
                                                KC_BSLASH,                                                                                      KC_1
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),


    [MULTI] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      C(KC_B),      C(KC_Y),      C(KC_O),      C(KC_U),            XXXXXXX,                                                XXXXXXX,            KC_DEQUEUE,       KC_LIST,       KC_ARRAY,      KC_LINKED,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      C(KC_C),      C(KC_I),      C(KC_E),      C(KC_A),            XXXXXXX,          C(KC_Z),              KC_RETURN_,     XXXXXXX,            KC_GT,            KC_SPACE,      KC_COMMA,      KC_LT,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      C(KC_G),      C(KC_X),      C(KC_J),      C(KC_K),            XXXXXXX,                                                XXXXXXX,            KC_SET,           KC_MAP,        KC_HASH_,      KC_TREE,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                XXXXXXX,                                                                                        KC_INT,
                                  XXXXXXX,      XXXXXXX,            XXXXXXX,                                                KC_CHAR,            KC_NEW,          KC_STR,
                                                XXXXXXX,                                                                                        KC_BOOL
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),



  // TODO
    [MOUSE] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      A(KC_B),      A(KC_Y),      A(KC_O),      A(KC_U),            XXXXXXX,                                                XXXXXXX,            KC_CUT,           KC_COPY,       KC_PASTE,      KC_UNDO,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      A(KC_C),      A(KC_I),      A(KC_E),      A(KC_A),            XXXXXXX,          A(KC_Z),              KC_UNDO,        XXXXXXX,            KC_MS_LEFT,       KC_MS_DOWN,    KC_MS_UP,      KC_MS_RIGHT,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      A(KC_G),      A(KC_X),      A(KC_J),      A(KC_K),            XXXXXXX,                                                XXXXXXX,            KC_WH_L,          KC_WH_D,       KC_WH_U,       KC_WH_R,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                XXXXXXX,                                                                                        KC_BTN2,
                                  XXXXXXX,      XXXXXXX,            XXXXXXX,                                                C(KC_BSLASH),       KC_BTN3,          KC_BTN1,
                                                XXXXXXX,                                                                                        C(KC_SLASH)
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),


    [FUNC] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      KC_F12,       KC_F7,        KC_F8,        KC_F9,              XXXXXXX,                                                XXXXXXX,            A(KC_L),          A(KC_D),       A(KC_W),       A(KC_V),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_F11,       KC_F4,        KC_F5,        KC_F6,              XXXXXXX,          C(KC_BSLASH),         A(KC_Q),        XXXXXXX,            A(KC_H),          A(KC_T),       A(KC_S),       A(KC_N),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_F10,       KC_F1,        KC_F2,        KC_F3,              XXXXXXX,                                                XXXXXXX,            A(KC_R),          A(KC_M),       A(KC_F),       A(KC_P),
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                KC_PAUSE,                                                                                       XXXXXXX,
                                  KC_INSERT,    KC_APP,             KC_PSCR,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,
                                                KC_SLCK,                                                                                        XXXXXXX
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),

    [NUM] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      KC_DOT,       KC_7,         KC_8,         KC_9,               XXXXXXX,                                                XXXXXXX,            C(KC_L),          C(KC_D),       C(KC_W),       C(KC_V),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_MINUS,     KC_4,         KC_5,         KC_6,               XXXXXXX,          KC_0,                 C(KC_Q),        XXXXXXX,            C(KC_H),          C(KC_T),       C(KC_S),       C(KC_N),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_PLUS,      KC_1,         KC_2,         KC_3,               XXXXXXX,                                                XXXXXXX,            C(KC_R),          C(KC_M),       C(KC_F),       C(KC_P),
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                KC_TAB,                                                                                         XXXXXXX,
                                  KC_SPACE,     KC_EQUAL,       KC_COMMA,                                                   XXXXXXX,            XXXXXXX,          XXXXXXX,
                                                KC_ESC,                                                                                         XXXXXXX
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),


    [NAV2] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      A(KC_LEFT),   A(KC_DOWN),   A(KC_UP),     A(KC_RIGHT),        XXXXXXX,                                                XXXXXXX,            A(KC_HOME),       A(KC_PGDOWN),  A(KC_PGUP),    A(KC_END),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      C(KC_LEFT),   C(KC_DOWN),   C(KC_UP),     C(KC_RIGHT),        XXXXXXX,          C(KC_C),              C(KC_V),        XXXXXXX,            KC_LEFT,          KC_DOWN,       KC_UP,         KC_RIGHT,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      C(KC_HOME),   C(KC_PGDOWN), C(KC_PGUP),   C(KC_END),          XXXXXXX,                                                XXXXXXX,            KC_HOME,          KC_PGDOWN,     KC_PGUP,       KC_END,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                KC_TAB,                                                                                         XXXXXXX,
                                  C(KC_ENT),    KC_ALT_ERASE,       KC_COMMA,                                               XXXXXXX,            TT(S_NAV2),       KC_ENT,
                                                KC_ESC,                                                                                         XXXXXXX
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),



    [S_NAV2] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      A_S(KC_LEFT),A_S(KC_DOWN),  A_S(KC_UP),   A_S(KC_RIGHT),        XXXXXXX,                                                XXXXXXX,            A_S(KC_HOME),     A_S(KC_PGDOWN),A_S(KC_PGUP),  A_S(KC_END),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      C_S(KC_LEFT),C_S(KC_DOWN),  C_S(KC_UP),   C_S(KC_RIGHT),        XXXXXXX,          C_S(KC_C),          C_S(KC_V),        XXXXXXX,            S(KC_LEFT),       S(KC_DOWN),    S(KC_UP),      S(KC_RIGHT),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      C_S(KC_HOME),C_S(KC_PGDOWN),C_S(KC_PGUP), C_S(KC_END),          XXXXXXX,                                                XXXXXXX,            S(KC_HOME),       S(KC_PGDOWN),  S(KC_PGUP),    S(KC_END),
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                A(KC_TAB),                                                                                      XXXXXXX,
                                  XXXXXXX,      KC_ALT_ERASE,         XXXXXXX,                                                XXXXXXX,          TT(S_NAV2),       XXXXXXX,
                                                A(KC_ESC),                                                                                      LT(ENGRAM_WIN, KC_BSPC)
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),


    [F_A] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      A(KC_F12),    A(KC_F7),     A(KC_F8),     A(KC_F9),           XXXXXXX,                                                XXXXXXX,            KC_LSFT,          KC_LCTL,       KC_LALT,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      A(KC_F11),    A(KC_F4),     A(KC_F5),     A(KC_F6),           XXXXXXX,          XXXXXXX,              XXXXXXX,        XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      A(KC_F10),    A(KC_F1),     A(KC_F2),     A(KC_F3),           XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                XXXXXXX,                                                                                        XXXXXXX,
                                  A(KC_INSERT), A(KC_APP),          XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,
                                                XXXXXXX,                                                                                        XXXXXXX
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),

    [F_C] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      C(KC_F12),    C(KC_F7),     C(KC_F8),     C(KC_F9),           XXXXXXX,                                                XXXXXXX,            KC_LSFT,          KC_LCTL,       KC_LALT,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      C(KC_F11),    C(KC_F4),     C(KC_F5),     C(KC_F6),           XXXXXXX,          XXXXXXX,              XXXXXXX,        XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      C(KC_F10),    C(KC_F1),     C(KC_F2),     C(KC_F3),           XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                XXXXXXX,                                                                                        XXXXXXX,
                                  C(KC_INSERT), C(KC_APP),          XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,
                                                XXXXXXX,                                                                                        XXXXXXX
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),



    [F_S] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      S(KC_F12),    S(KC_F7),     S(KC_F8),     S(KC_F9),           XXXXXXX,                                                XXXXXXX,            KC_LSFT,          KC_LCTL,       KC_LALT,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      S(KC_F11),    S(KC_F4),     S(KC_F5),     S(KC_F6),           XXXXXXX,          XXXXXXX,              XXXXXXX,        XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      S(KC_F10),    S(KC_F1),     S(KC_F2),     S(KC_F3),           XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                XXXXXXX,                                                                                        XXXXXXX,
                                  S(KC_INSERT), S(KC_APP),          XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,
                                                XXXXXXX,                                                                                        XXXXXXX
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),


  // Special layer, to be able to use Win+Letter combinations, without leaving Navigation layer
    [ENGRAM_WIN] = LAYOUT_split_3x5_plus_5x(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      G(KC_B),      G(KC_Y),      G(KC_O),      G(KC_U),            XXXXXXX,                                                XXXXXXX,            G(KC_L),          G(KC_D),       G(KC_W),       G(KC_V),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      G(KC_C),      G(KC_I),      G(KC_E),      G(KC_A),            XXXXXXX,          G(KC_Z),              G(KC_Q),        XXXXXXX,            G(KC_H),          G(KC_T),       G(KC_S),       G(KC_N),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      G(KC_G),      G(KC_X),      G(KC_J),      G(KC_K),            XXXXXXX,                                                XXXXXXX,            G(KC_R),          G(KC_M),       G(KC_F),       G(KC_P),
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|


                                                G(KC_TAB),                                                                                      XXXXXXX,
                                  G(KC_SPACE),  XXXXXXX,            XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,
                                                G(KC_ESC),                                                                                      XXXXXXX
                              //`----------------------------------------------'                                          `----------------------------------------------------'
  ),


};
