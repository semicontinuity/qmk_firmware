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

#include QMK_KEYBOARD_H
#include "casemodes.h"
#include "layouts.h"
#include <stdio.h>

enum {
  TD_RAISE
};

enum layer_id {
  ENGRAM,
  QWERTY,
  RPE,      // russian phonetic engram
  RPE_EXT,  // russian phonetic engram extra characters
  LOWER,
  R_LOWER,  // lower layer (special chars), invoked from russian layout
  MULTI,
  MOUSE,
  FUNC,
  NUM,
  NAV2,
  C_NAV,
  S_NAV2,
  CS_NAV
};


#define C_S(kc) (QK_LCTL | QK_LSFT| (kc))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [ENGRAM] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      KC_B,         KC_Y,         KC_O,         KC_U,               KC_Z,                                                   KC_Q,               KC_L,             KC_D,          KC_W,          KC_V,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      LGUI_T(KC_C), LALT_T(KC_I), LCTL_T(KC_E), LSFT_T(KC_A),       KC_COMMA,                                               KC_DOT,             LSFT_T(KC_H),     RCTL_T(KC_T),  LALT_T(KC_S),  RGUI_T(KC_N),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_G,         RALT_T(KC_X), KC_J,         KC_K,               KC_UNDS,                                                KC_QUES,            KC_R,             KC_M,          RALT_T(KC_F),  KC_P,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|
      XXXXXXX,                    LT(MULTI, KC_ESC),  KC_SPACE,     TD(TD_RAISE), LT(MOUSE, KC_TAB),    LT(FUNC, KC_BSPC),  OSL(LOWER),         KC_ENT,           LT(NUM, KC_DEL),              XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [QWERTY] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      KC_Q,         KC_W,         KC_E,         KC_R,               KC_T,                                                   KC_Y,               KC_U,             KC_I,          KC_O,          KC_P,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_A,         LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),       KC_G,                                                   KC_H,               LSFT_T(KC_J),     RCTL_T(KC_K),  LALT_T(KC_L),  RGUI_T(KC_SCLN),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_Z,         KC_X,         KC_C,         KC_V,               KC_B,                                                   KC_N,               KC_M,             KC_COMM,       RALT_T(KC_DOT),KC_SLASH,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    _______,      _______,            _______,     _______,               _______,            _______,            _______,          _______,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [RPE] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,----------------------------------------------------------------------------------.
      KC_COMMA,     KC_S,         KC_J,         KC_E,               KC_P,   /*з*/                                           KC_X,    /*ч*/      KC_K,             KC_L,          KC_I,          KC_D,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_W,         KC_B,         KC_T,         KC_F,               KC_QUES,/*,*/                                           KC_SLASH,/*.*/      KC_LBRACKET,/*х*/ KC_N, /*т*/    KC_C, /*с*/    KC_Y, /*н*/
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+--------------|
      KC_U,         KC_SCOLON,    KC_Q,         KC_R,               _______,                                                KC_AMPR, /*?*/      KC_H,             KC_V,          KC_A,          KC_G,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+--------------|
      XXXXXXX,                    OSL(RPE_EXT), _______,            _______,     _______,               _______,            OSL(R_LOWER),       _______,          _______,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [RPE_EXT] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      XXXXXXX,      KC_RBRACKET,  KC_GRAVE,     KC_DOT,             XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       KC_O,          XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,      KC_M,         KC_QUOTE,     KC_Z,               XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    KC_ESC,       XXXXXXX,            XXXXXXX,     XXXXXXX,               XXXXXXX,            XXXXXXX,            XXXXXXX,          XXXXXXX,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  // with underscore (inaccessible from QWERTY)
  [LOWER] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      KC_MINUS,     KC_LT,        KC_GT,        KC_AMPR,            _______,                                                _______,            KC_AT,            KC_ASTERISK,   KC_SLASH,      KC_GRAVE,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_PLUS,      KC_LPRN,      KC_RPRN,      KC_EQUAL,           KC_PERC,                                                KC_TILDE,           KC_SCOLON,        KC_LCBR,       KC_RCBR,       KC_DQUO,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_EXLM,      KC_LBRACKET,  KC_RBRACKET,  KC_PIPE,            KC_UNDS,                                                _______,            KC_COLON,         KC_CIRC,       KC_BSLASH,     KC_QUOTE,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    KC_HASH,      _______,            _______,     KC_DOLLAR,             _______,            _______,            _______,          _______,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [R_LOWER] = LAYOUT_split_3x5_3_p( // LOWER when toggled to russian layout: same as lower, but masked out characters that cannot be typed (=> unicode?)
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      KC_MINUS,     XXXXXXX,      XXXXXXX,      KC_AMPR,            _______,                                                _______,            XXXXXXX,          KC_ASTERISK,   KC_PIPE, /*/*/ XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_PLUS,      KC_LPRN,      KC_RPRN,      KC_EQUAL,           KC_PERC,                                                XXXXXXX,            KC_DOLLAR,/*;*/   XXXXXXX,       XXXXXXX,       KC_AT,   /*"*/
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_EXLM,      XXXXXXX,      XXXXXXX,      XXXXXXX,            KC_UNDS,                                                _______,            KC_CIRC,  /*:*/   XXXXXXX,       KC_BSLASH,     XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    KC_HASH, /*№*/      _______,      _______,     XXXXXXX,               XXXXXXX,            _______,            _______,          XXXXXXX,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [MULTI] = LAYOUT_split_3x5_3_p(
  //--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
     LCTL(KC_B),   LCTL(KC_Y),   LCTL(KC_O),   LCTL(KC_U),         LCTL(KC_Z),                                             TG(QWERTY),         XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
     LCTL(KC_C),   LCTL(KC_I),   LCTL(KC_E),   LCTL(KC_A),         C(KC_COMM),                                             XXXXXXX,            KC_MPRV,          KC_VOLD,       KC_VOLU,       KC_MNXT,
  //-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
     LCTL(KC_G),   LCTL(KC_X),   LCTL(KC_J),   LCTL(KC_K),         C(KC_SCLN),                                             XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
     XXXXXXX,                    XXXXXXX,      XXXXXXX,            XXXXXXX,     XXXXXXX,               XXXXXXX,            KC_MEDIA_STOP,      KC_MPLY,          KC_MUTE,                      XXXXXXX
  // =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [MOUSE] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      LALT(KC_B),   LALT(KC_Y),   LALT(KC_O),   LALT(KC_U),         LALT(KC_Z),                                             KC_CUT,             KC_PASTE,         XXXXXXX,       XXXXXXX,       KC_COPY,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      LALT(KC_C),   LALT(KC_I),   LALT(KC_E),   LALT(KC_A),         A(KC_COMM),                                             KC_UNDO,            KC_MS_LEFT,       KC_MS_DOWN,    KC_MS_UP,      KC_MS_RIGHT,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      LALT(KC_G),   LALT(KC_X),   LALT(KC_J),   LALT(KC_K),         C(KC_SCLN),                                             XXXXXXX,            KC_WH_L,          KC_WH_D,       KC_WH_U,       KC_WH_R,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    XXXXXXX,      XXXXXXX,            XXXXXXX,     XXXXXXX,               XXXXXXX,            KC_BTN1,            KC_BTN3,          KC_BTN2,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [FUNC] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      KC_F12,       KC_F7,        KC_F8,        KC_F9,              KC_PSCR,                                                LALT(KC_Q),         LALT(KC_L),       LALT(KC_D),    LALT(KC_W),    LALT(KC_V),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_F11,       KC_F4,        KC_F5,        KC_F6,              KC_SLCK,                                                LALT(KC_DOT),       LALT(KC_H),       LALT(KC_T),    LALT(KC_S),    LALT(KC_N),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_F10,       KC_F1,        KC_F2,        KC_F3,              KC_PAUSE,                                               LALT(KC_QUOTE),     LALT(KC_R),       LALT(KC_M),    LALT(KC_F),    LALT(KC_P),
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    KC_APP,       KC_INSERT,          XXXXXXX,     XXXXXXX,               XXXXXXX,            XXXXXXX,            XXXXXXX,          XXXXXXX,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [NUM] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      KC_MINUS,     KC_7,         KC_8,         KC_9,               KC_SLASH,                                               LCTL(KC_Q),         LCTL(KC_L),       LCTL(KC_D),    LCTL(KC_W),    LCTL(KC_V),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      KC_PLUS,      KC_4,         KC_5,         KC_6,               KC_EQUAL,                                               LCTL(KC_DOT),       LCTL(KC_H),       LCTL(KC_T),    LCTL(KC_S),    LCTL(KC_N),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      TG(NUM),      KC_1,         KC_2,         KC_3,               KC_ASTR,                                                LCTL(KC_QUOTE),     LCTL(KC_R),       LCTL(KC_M),    LCTL(KC_F),    LCTL(KC_P),
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    KC_DOT,       KC_0,               KC_SPACE,    XXXXXXX,               XXXXXXX,            XXXXXXX,            XXXXXXX,          XXXXXXX,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [NAV2] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            KC_LEFT,          KC_DOWN,       KC_UP,         KC_RIGHT,
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            KC_HOME,          KC_PGDOWN,     KC_PGUP,       KC_END,
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    XXXXXXX,      XXXXXXX,            XXXXXXX,     XXXXXXX,               XXXXXXX,            TT(C_NAV),          KC_MPLY,            KC_MUTE,                    XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [C_NAV] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,      
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            C(KC_LEFT),       C(KC_DOWN),    C(KC_UP),      C(KC_RIGHT),  
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            C(KC_HOME),       C(KC_PGDOWN),  C(KC_PGUP),    C(KC_END),    
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    XXXXXXX,      XXXXXXX,            XXXXXXX,     XXXXXXX,               XXXXXXX,            XXXXXXX,            XXXXXXX,          XXXXXXX,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [S_NAV2] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,      
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            S(KC_LEFT),       S(KC_DOWN),    S(KC_UP),      S(KC_RIGHT),  
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            S(KC_HOME),       S(KC_PGDOWN),  S(KC_PGUP),    S(KC_END),    
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    XXXXXXX,      XXXXXXX,            XXXXXXX,     XXXXXXX,               XXXXXXX,            TT(CS_NAV),         XXXXXXX,          XXXXXXX,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  ),

  [CS_NAV] = LAYOUT_split_3x5_3_p(
  //,--------------------------------------------------------------------------.                                          ,-----------------------------------------------------------------------------------.
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,      
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            C_S(KC_LEFT),     C_S(KC_DOWN),  C_S(KC_UP),    C_S(KC_RIGHT),
  //|-------------+-------------+-------------+-------------------+------------|                                          |-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,            XXXXXXX,                                                XXXXXXX,            C_S(KC_HOME),     C_S(KC_PGDOWN),C_S(KC_PGUP),  C_S(KC_END),  
  //|-------------+-------------+-------------+-------------------+------------+-------------------|  |-------------------+-------------------+-----------------+--------------+--------------+---------------|
      XXXXXXX,                    XXXXXXX,      XXXXXXX,            XXXXXXX,     XXXXXXX,               XXXXXXX,            XXXXXXX,            XXXXXXX,          XXXXXXX,                      XXXXXXX
  //  =======                 //`------------------------------------------------------------------'  `------------------------------------------------------------------------'                =======
  )
};



// Tap dance

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_SINGLE_TAP_THEN_HOLD,
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
        return state->pressed ? TD_SINGLE_HOLD : TD_SINGLE_TAP;
    } else if (state->count == 2) {
        return state->pressed ? TD_SINGLE_TAP_THEN_HOLD : TD_DOUBLE_TAP;
    }
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
            // Ideally, implement it so that when single tapped, caps lock lights up (how?)
            if (layer_state_is(QWERTY)) {
                add_oneshot_mods(MOD_MASK_SHIFT);
            } else {
                add_oneshot_mods(MOD_MASK_SHIFT);
            }
            break;
        case TD_SINGLE_HOLD:
            layer_on(NAV2);
            break;
        case TD_DOUBLE_TAP:
            toggle_caps_word();
            break;
        case TD_SINGLE_TAP_THEN_HOLD:
            layer_on(S_NAV2);
            break;
        case TD_NONE:
        case TD_UNKNOWN:
            break;
    }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            if (layer_state_is(QWERTY)) {
                del_mods(MOD_MASK_SHIFT);
            } else {
                del_mods(MOD_MASK_SHIFT);
            }
            break;
        case TD_SINGLE_HOLD:
            layer_off(NAV2);
            layer_off(C_NAV);
            break;
        case TD_SINGLE_TAP_THEN_HOLD:
            layer_off(S_NAV2);
            layer_off(CS_NAV);
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
    [TD_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 250)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    uprintf("process_record_user\n");
    uint8_t mod_state = get_mods();
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

    case KC_SPACE:    //
        uprintf("KC_SPACE\n");
        if (mod_state == 8 && record->event.pressed) {
          if (layer_state_is(RPE)) {
            uprintf("russian off\n");
            layer_off(RPE);
          } else {
            uprintf("russian on\n");
            layer_on(RPE);
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
}
