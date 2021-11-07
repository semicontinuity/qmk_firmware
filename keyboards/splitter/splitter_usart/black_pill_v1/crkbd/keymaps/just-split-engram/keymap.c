/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include "casemodes.h"
#include "layouts.h"
#include <stdio.h>

enum {
  TD_SHIFT
};

enum layer_id {
  ENGRAM,
  QWERTY,
  S_QWERTY,
  RAISE2,
  MULTI,
  MULTI2,
  MOUSE,
  FUNC,
  NUM,
  SHIFT,
  S_RAISE,
  S_MULTI,
  RUSSIAN, // phonetic engram
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [ENGRAM] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      KC_LALT,     KC_B,         KC_Y,         KC_O,         KC_U,               KC_Z,                                                   KC_Q,               KC_L,             KC_D,          KC_W,          KC_V,          TD(TD_SHIFT),
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------+-------------------|
      OSL(RAISE2), LGUI_T(KC_C), LALT_T(KC_I), LCTL_T(KC_E), LT(SHIFT, KC_A),    KC_COMMA,                                               KC_DOT,             LT(SHIFT, KC_H),  RCTL_T(KC_T),  LALT_T(KC_S),  RGUI_T(KC_N),  OSL(SHIFT),
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------+-------------------|
      KC_LCTL,     KC_G,         RALT_T(KC_X), KC_J,         KC_K,               KC_UNDS,                                                KC_QUES,            KC_R,             KC_M,          RALT_T(KC_F),  KC_P,          KC_LGUI,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------+-------------------|
                                                             LT(MULTI2, KC_ESC), KC_SPACE,    LT(MOUSE, KC_TAB),     LT(FUNC, KC_BSPC),  LT(RAISE2, KC_ENT),  LT(NUM, KC_DEL)
                                                         //`----------------------------------------------------'  `---------------------------------------------------------'
  ),

  [QWERTY] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      _______,     KC_Q,         KC_W,         KC_E,         KC_R,               KC_T,                                                   KC_Y,               KC_U,             KC_I,          KC_O,          KC_P,           _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     KC_A,         LALT_T(KC_S), LCTL_T(KC_D), LT(S_QWERTY, KC_F), KC_G,                                                   KC_H,               LT(S_QWERTY,KC_J), RCTL_T(KC_K), LALT_T(KC_L),  RGUI_T(KC_SCLN),_______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     KC_Z,         KC_X,         KC_C,         KC_V,               KC_B,                                                   KC_N,               KC_M,             KC_COMM,       RALT_T(KC_DOT),KC_SLASH,       _______,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------+------------------|
                                                             _______,            _______,     _______,               _______,            _______,            _______
                                                         //`--------------------------------------------------'    `---------------------------------------------------------'
  ),
  // became unnecessary
  [S_QWERTY] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      _______,     S(KC_Q),      S(KC_W),      S(KC_E),      S(KC_R),            S(KC_T),                                                S(KC_Y),             S(KC_U),         S(KC_I),       S(KC_O),       S(KC_P),        _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     S(KC_A),      S(KC_S),      S(KC_D),      S(KC_F),            S(KC_G),                                                S(KC_H),             S(KC_J),         S(KC_K),       S(KC_L),       S(KC_SCLN),     _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     S(KC_Z),      S(KC_X),      S(KC_C),      S(KC_V),            S(KC_B),                                                S(KC_N),             S(KC_M),         S(KC_COMMA),   S(KC_DOT),     S(KC_SLASH),    _______,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------+------------------|
                                                             _______,            _______,     _______,               _______,            _______,            _______
                                                         //`--------------------------------------------------'    `---------------------------------------------------------'
  ),

/*
  [RAISE] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      _______,     KC_MINUS,     KC_LT,        KC_GT,        KC_AMPR,            KC_CIRC,                                                KC_BSLASH,          KC_ASTERISK,      KC_LCBR,       KC_RCBR,       KC_SLASH,       _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     KC_PLUS,      KC_LPRN,      KC_RPRN,      KC_EQUAL,           KC_PERC,                                                KC_AT,              KC_LEFT,          KC_DOWN,       KC_UP,         KC_RIGHT,       LGUI(KC_SPACE),
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     KC_EXLM,      KC_LBRACKET,  KC_RBRACKET,  KC_PIPE,            KC_TILDE,                                               KC_GRAVE,           KC_HOME,          KC_PGDOWN,     KC_PGUP,       KC_END,         _______,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------+------------------|
                                                             KC_HASH,            _______,     KC_DOLLAR,             _______,            _______,            _______
                                                         //`----------------------------------------------------'  `---------------------------------------------------------'
  ),
*/

/*
  [RAISE2] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      _______,     KC_MINUS,     KC_LT,        KC_GT,        KC_AMPR,            _______,                                                _______,            KC_AT,            KC_ASTERISK,   KC_SLASH,      KC_GRAVE,       _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     KC_PLUS,      KC_LPRN,      KC_RPRN,      KC_EQUAL,           KC_PERC,                                                KC_TILDE,           KC_SCOLON,        KC_LCBR,       KC_RCBR,       KC_DQUO,        LGUI(KC_SPACE),
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     KC_EXLM,      KC_LBRACKET,  KC_RBRACKET,  KC_PIPE,            _______,                                                _______,            KC_COLON,         KC_CIRC,       KC_BSLASH,     KC_QUOTE,       _______,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------+------------------|
                                                             KC_HASH,            _______,     KC_DOLLAR,             _______,            _______,            _______
                                                         //`----------------------------------------------------'  `---------------------------------------------------------'
  ),
*/

  [RAISE2] = LAYOUT_split_3x6_3( // same as RAISE2 + underscore, inaccessible from QWERTY: _?
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      _______,     KC_MINUS,     KC_LT,        KC_GT,        KC_AMPR,            _______,                                                _______,            KC_AT,            KC_ASTERISK,   KC_SLASH,      KC_GRAVE,       _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     KC_PLUS,      KC_LPRN,      KC_RPRN,      KC_EQUAL,           KC_PERC,                                                KC_TILDE,           KC_SCOLON,        KC_LCBR,       KC_RCBR,       KC_DQUO,        LGUI(KC_SPACE),
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     KC_EXLM,      KC_LBRACKET,  KC_RBRACKET,  KC_PIPE,            KC_UNDS,                                                _______,            KC_COLON,         KC_CIRC,       KC_BSLASH,     KC_QUOTE,       _______,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------+------------------|
                                                             KC_HASH,            _______,     KC_DOLLAR,             _______,            _______,            _______
                                                         //`----------------------------------------------------'  `---------------------------------------------------------'
  ),

/*
  [MULTI] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      _______,     LCTL(KC_B),   LCTL(KC_Y),   LCTL(KC_O),   LCTL(KC_U),         LCTL(KC_Z),                                             TG(QWERTY),         KC_RPRN,          KC_SPACE,      KC_LCBR,       KC_ENT,         _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     LCTL(KC_C),   LCTL(KC_I),   LCTL(KC_E),   LCTL(KC_A),         C(KC_COMM),                                             XXXXXXX,            KC_MPRV,          KC_VOLD,       KC_VOLU,       KC_MNXT,        _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     LCTL(KC_G),   LCTL(KC_X),   LCTL(KC_J),   LCTL(KC_K),         C(KC_SCLN),                                             XXXXXXX,            KC_EQUAL,         KC_SPACE,      KC_0,          KC_SCOLON,      _______,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------+------------------|
                                                             XXXXXXX,            XXXXXXX,     XXXXXXX,               KC_MEDIA_STOP,      KC_MPLY,            KC_MUTE
                                                         //`----------------------------------------------------'  `---------------------------------------------------------'
  ),*/

  [MULTI2] = LAYOUT_split_3x6_3( // with nav keys
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      _______,     LCTL(KC_B),   LCTL(KC_Y),   LCTL(KC_O),   LCTL(KC_U),         LCTL(KC_Z),                                             TG(QWERTY),         KC_MPRV,          KC_VOLD,       KC_VOLU,       KC_MNXT,       _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     LCTL(KC_C),   LCTL(KC_I),   LCTL(KC_E),   LCTL(KC_A),         C(KC_COMM),                                             KC_AT,              KC_LEFT,          KC_DOWN,       KC_UP,         KC_RIGHT,       _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     LCTL(KC_G),   LCTL(KC_X),   LCTL(KC_J),   LCTL(KC_K),         C(KC_SCLN),                                             KC_GRAVE,           KC_HOME,          KC_PGDOWN,     KC_PGUP,       KC_END,         _______,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------+------------------|
                                                             XXXXXXX,            XXXXXXX,     XXXXXXX,               KC_MEDIA_STOP,      KC_MPLY,            KC_MUTE
                                                         //`----------------------------------------------------'  `---------------------------------------------------------'
  ),

  [MOUSE] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      XXXXXXX,     LALT(KC_B),   LALT(KC_Y),   LALT(KC_O),   LALT(KC_U),         LALT(KC_Z),                                             KC_CUT,             KC_PASTE,         XXXXXXX,       XXXXXXX,       KC_COPY,        XXXXXXX,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      XXXXXXX,     LALT(KC_C),   LALT(KC_I),   LALT(KC_E),   LALT(KC_A),         A(KC_COMM),                                             KC_UNDO,            KC_MS_LEFT,       KC_MS_DOWN,    KC_MS_UP,      KC_MS_RIGHT,    XXXXXXX,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      XXXXXXX,     LALT(KC_G),   LALT(KC_X),   LALT(KC_J),   LALT(KC_K),         C(KC_SCLN),                                             XXXXXXX,            KC_WH_L,          KC_WH_D,       KC_WH_U,       KC_WH_R,        XXXXXXX,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------+------------------|
                                                             XXXXXXX,            XXXXXXX,     XXXXXXX,               KC_BTN1,            KC_BTN3,            KC_BTN2
                                                         //`----------------------------------------------------'  `---------------------------------------------------------'
  ),


  [FUNC] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      XXXXXXX,     KC_F12,       KC_F7,        KC_F8,        KC_F9,              KC_PSCR,                                                LALT(KC_Q),         LALT(KC_L),       LALT(KC_D),    LALT(KC_W),    LALT(KC_V),     XXXXXXX,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      XXXXXXX,     KC_F11,       KC_F4,        KC_F5,        KC_F6,              KC_SLCK,                                                LALT(KC_DOT),       LALT(KC_H),       LALT(KC_T),    LALT(KC_S),    LALT(KC_N),     XXXXXXX,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      XXXXXXX,     KC_F10,       KC_F1,        KC_F2,        KC_F3,              KC_PAUSE,                                               LALT(KC_QUOTE),     LALT(KC_R),       LALT(KC_M),    LALT(KC_F),    LALT(KC_P),     XXXXXXX,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------+------------------|
                                                             KC_APPLICATION,     KC_INSERT,   LALT(KC_TAB),          XXXXXXX,            XXXXXXX,            XXXXXXX
                                                         //`----------------------------------------------------'  `---------------------------------------------------------'
  ),

  [NUM] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      XXXXXXX,     KC_MINUS,     KC_7,         KC_8,         KC_9,               KC_SLASH,                                               LCTL(KC_Q),         LCTL(KC_L),       LCTL(KC_D),    LCTL(KC_W),    LCTL(KC_V),     XXXXXXX,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      XXXXXXX,     KC_PLUS,      KC_4,         KC_5,         KC_6,               KC_EQUAL,                                               LCTL(KC_DOT),       LCTL(KC_H),       LCTL(KC_T),    LCTL(KC_S),    LCTL(KC_N),     XXXXXXX,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      XXXXXXX,     TG(NUM),      KC_1,         KC_2,         KC_3,               KC_ASTR,                                                LCTL(KC_QUOTE),     LCTL(KC_R),       LCTL(KC_M),    LCTL(KC_F),    LCTL(KC_P),     XXXXXXX,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------+------------------|
                                                             KC_DOT,             KC_0,        KC_SPACE,              XXXXXXX,            XXXXXXX,            XXXXXXX
                                                         //`----------------------------------------------------'  `---------------------------------------------------------'
  ),
/*
  [SHIFT] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      _______,     LSFT(KC_B),   LSFT(KC_Y),   LSFT(KC_O),   LSFT(KC_U),         LSFT(KC_Z),                                             LSFT(KC_Q),         LSFT(KC_L),       LSFT(KC_D),    LSFT(KC_W),    LSFT(KC_V),    _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------+-------------------|
      _______,     LSFT(KC_C),   LSFT(KC_I),   LSFT(KC_E),   LSFT(KC_A),         KC_SCOLON,                                              KC_COLON,           LSFT(KC_H),       LSFT(KC_T),    LSFT(KC_S),    LSFT(KC_N),    _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------+-------------------|
      KC_CAPS,     LSFT(KC_G),   LSFT(KC_X),   LSFT(KC_J),   LSFT(KC_K),         KC_QUES,                                                KC_QUOTE,           LSFT(KC_R),       LSFT(KC_M),    LSFT(KC_F),    LSFT(KC_P),    KC_CAPS,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------+-------------------|
                                                             LT(S_MULTI, S(KC_ESC)), S(KC_SPACE), S(KC_TAB),         S(KC_BSPC),         S(KC_ENT),          S(KC_DEL)
                                                         //`----------------------------------------------------'  `---------------------------------------------------------'
  ),*/
  [SHIFT] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      _______,     LSFT(KC_B),   LSFT(KC_Y),   LSFT(KC_O),   LSFT(KC_U),         LSFT(KC_Z),                                             LSFT(KC_Q),         LSFT(KC_L),       LSFT(KC_D),    LSFT(KC_W),    LSFT(KC_V),    _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------+-------------------|
      _______,     LSFT(KC_C),   LSFT(KC_I),   LSFT(KC_E),   LSFT(KC_A),         _______,                                                _______,            LSFT(KC_H),       LSFT(KC_T),    LSFT(KC_S),    LSFT(KC_N),    _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |----------- --------+-----------------+--------------+--------------+--------------+-------------------|
      KC_CAPS,     LSFT(KC_G),   LSFT(KC_X),   LSFT(KC_J),   LSFT(KC_K),         _______,                                                _______,            LSFT(KC_R),       LSFT(KC_M),    LSFT(KC_F),    LSFT(KC_P),    KC_CAPS,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------+-------------------|
                                                             LT(S_MULTI, S(KC_ESC)), S(KC_SPACE), S(KC_TAB),         S(KC_BSPC),         S(KC_ENT),          S(KC_DEL)
                                                         //`----------------------------------------------------'  `---------------------------------------------------------'
  ),
/*

  [S_RAISE] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      _______,     XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,        XXXXXXX,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            S(KC_LEFT),       S(KC_DOWN),    S(KC_UP),      S(KC_RIGHT),    XXXXXXX,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            S(KC_HOME),       S(KC_PGDOWN),  S(KC_PGUP),    S(KC_END),      XXXXXXX,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------+------------------|
                                                             XXXXXXX,            XXXXXXX,     XXXXXXX,               XXXXXXX,            XXXXXXX,            XXXXXXX
                                                         //`----------------------------------------------------'  `---------------------------------------------------------'
  ),
*/

  [S_MULTI] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      _______,     XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,        XXXXXXX,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            S(KC_LEFT),       S(KC_DOWN),    S(KC_UP),      S(KC_RIGHT),    XXXXXXX,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------+------------------|
      _______,     XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            S(KC_HOME),       S(KC_PGDOWN),  S(KC_PGUP),    S(KC_END),      XXXXXXX,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------+------------------|
                                                             XXXXXXX,            XXXXXXX,     XXXXXXX,               XXXXXXX,            XXXXXXX,            XXXXXXX
                                                         //`----------------------------------------------------'  `---------------------------------------------------------'
  ),

  [RUSSIAN] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------.                                          ,------------------------------------------------------------------------------------------------------.
      _______,     KC_COMMA,     KC_S,         KC_J,         KC_E,               KC_P,                                                   KC_X,               KC_K,             KC_L,          KC_I,          KC_D,          _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------+-------------------|
      _______,     KC_W,         KC_B,         KC_T,         KC_F,               _______,                                                _______,            KC_LBRACKET,      KC_N,          KC_S,          KC_Y,          _______,
  //|------------+-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------+-------------------|
      _______,     KC_U,         KC_SCOLON,    KC_Q,         KC_R,               _______,                                                _______,            KC_H,             KC_V,          KC_A,          KC_G,          _______,
  //|------------+-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------+-------------------|
                                                             _______,            _______,    _______,                _______,            _______,            _______
                                                         //`----------------------------------------------------'  `---------------------------------------------------------'
  ),

};



// Tap dance

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;


// Function associated with all tap dances
td_state_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);


// Determine the current tap dance state
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};


// Functions that control what our tap dance key does
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            if (layer_state_is(QWERTY)) {
                add_oneshot_mods(MOD_MASK_SHIFT);
//                set_oneshot_layer(S_QWERTY, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED);
            } else {
                add_oneshot_mods(MOD_MASK_SHIFT);
//                set_oneshot_layer(SHIFT, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
            break;
        case TD_SINGLE_HOLD:
            if (layer_state_is(QWERTY)) {
                add_mods(MOD_MASK_SHIFT);
//                layer_on(S_QWERTY);
            } else {
                add_mods(MOD_MASK_SHIFT);
//                layer_on(SHIFT);
            }
            break;
        case TD_DOUBLE_TAP:
            toggle_caps_word();
            break;
        case TD_NONE:
        case TD_UNKNOWN:
            break;
    }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:   break;
        case TD_SINGLE_HOLD:
            if (layer_state_is(QWERTY)) {
                del_mods(MOD_MASK_SHIFT);
//                layer_off(S_QWERTY);
            } else {
                del_mods(MOD_MASK_SHIFT);
//                layer_off(SHIFT);
            }
            break;
        case TD_DOUBLE_TAP:
        case TD_NONE:
        case TD_UNKNOWN:
            break;
    }
    ql_tap_state.state = TD_NONE;
}


// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 250)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    uprintf("process_record_user\n");
//    uint8_t mod_state = get_mods();
//    uprintf("mods=%02x keycode=%04x\n", mod_state, keycode);
    if (!process_case_modes(keycode, record)) {
        return false;
    }

    switch (keycode) {

    case KC_TRNS:
    case KC_NO:
      /* Always cancel one-shot layer when another key gets pressed */
      if (record->event.pressed && is_oneshot_layer_active())
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return true;

    case 0x082c:
        uprintf("0x082c\n");
        if (record->event.pressed) {
          if (layer_state_is(RUSSIAN)) {
            uprintf("russian off\n");
            layer_off(RUSSIAN);
          } else {
            uprintf("russian on\n");
            layer_on(RUSSIAN);
          }
        }
        break;
/*
    case KC_SPACE:
        uprintf("space\n");
        uprintf("pressed: %d\n", record->event.pressed);
        uprintf("MOD_BIT(KC_LGUI): %02x\n", MOD_BIT(KC_LGUI));
        uprintf("(mod_state & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI): %02x\n", (mod_state & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI));
        if (((mod_state & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI) || (mod_state & MOD_BIT(KC_RGUI)) == MOD_BIT(KC_RGUI)) && record->event.pressed) {
          if (layer_state_is(RUSSIAN)) {
            uprintf("russian off\n");
            layer_off(RUSSIAN);
          } else {
            uprintf("russian on\n");
            layer_on(RUSSIAN);
          }
        }
        break;
*/
    }
    return true;
};
