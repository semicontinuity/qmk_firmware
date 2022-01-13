#include QMK_KEYBOARD_H
#include "version.h"
#include "layouts.h"
#include "casemodes.h"
//#include <stdio.h>
#include <common/timer.h>


enum {
    TD_RAISE
};

enum layer_id {
    ENGRAM,
    QWERTY,
    RPE,      // russian phonetic engram; switched on left keyboard half: Win+Space
    RPE_EXT,  // russian phonetic engram extra characters (perhaps, delete)
    LOWER,
    R_LOWER,  // lower layer (special chars), invoked from russian layout + extra russian characters
    MULTI,
    QMULTI,
    MOUSE,
    FUNC,
    NUM,
    QNUM,     // Numbers (invoked from QWERTY)
    //  NAV,
    NAV2,
    //  C_NAV,
    //  S_NAV,
    S_NAV2,
    //  CS_NAV
    F_A,      // Alt+Function keys
    F_C,      // Ctrl+Function keys
};

enum custom_keycodes {
    KC_NEW = SAFE_RANGE,
    KC_INT,
    KC_STR,
    KC_CHAR,
    KC_PQUEUE,
    KC_LINKED,
    KC_ARRAY,
    KC_LIST,
    KC_DEQUEUE,
    KC_COMP,
    KC_ENTRY,
    KC_TREE,
    KC_HASH_,
    KC_MAP,
    KC_SET
};

#define C_S(kc) (QK_LCTL | QK_LSFT| (kc))
#define A_S(kc) (QK_LALT | QK_LSFT| (kc))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Mostly compatible with ENGRAM; `Q`, `Z` are in the middle columns, middle colums are different
  [ENGRAM] = LAYOUT_ergodox_pretty(
    KC_ESC,         KC_LBRC,        KC_2,           KC_3,           KC_4,             KC_5,           KC_LPRN,                                                KC_RPRN,        KC_6,           KC_7,             KC_8,           KC_9,           KC_RBRC,        KC_PSCR,        //
    KC_TAB,         KC_1,           KC_Y,           KC_O,           KC_U,             KC_Q,           KC_PGUP,                                                KC_UP,          KC_Z,           KC_L,             LT(F_C,KC_D),   LT(F_A,KC_W),   KC_0,           KC_INSERT,      //
    KC_BSPC,        KC_B,           LALT_T(KC_I),   LCTL_T(KC_E),   LSFT_T(KC_A),     KC_COMMA,                                                                               KC_DOT,         LSFT_T(KC_H),     RCTL_T(KC_T),   LALT_T(KC_S),   KC_V,           KC_DELETE,      //
    KC_LSFT,        LGUI_T(KC_C),   RALT_T(KC_X),   KC_J,           KC_K,             KC_UNDS,        KC_PGDOWN,                                              KC_DOWN,        KC_QUES,        KC_R,             KC_M,           RALT_T(KC_F),   RGUI_T(KC_N),   KC_RSFT,        //
    KC_LCTL,        KC_G,           KC_LALT,        KC_COMMA,       LT(MULTI, KC_TAB),                                                                                                        LT(NUM, KC_BSPC), KC_DOT,         KC_RALT,        KC_P,           KC_RCTL,        //
 // ---------------------------------------------------------------|-----------------|-------------------------------------------------|   |-------------------------------------------------|-----------------|----------------------------------------------------------------//
                                                                                                      KC_HOME,        KC_END,               KC_LEFT,          KC_RIGHT,                                                                                                         //
                                                                                                                      KC_LGUI,              KC_APP,                                                                                                                             //
                                                                                      KC_SPACE,       TD(TD_RAISE),   LT(MOUSE, KC_ESC),    LT(FUNC, KC_DEL), KC_ENTER,       OSL(LOWER)                                                                                        //
 //                                                                                  |-------------------------------------------------|   |---------------------------------------------|                                                                                      //
  ),

  // Mostly compatible with QWERTY; `-`, `+`, `=` are on LOWER layer; `_` is at the bottom
  [QWERTY] = LAYOUT_ergodox_pretty(
    _______,        _______,        _______,        _______,        _______,          _______,        _______,                                                _______,        _______,        _______,          _______,        _______,        _______,        _______,        //
    _______,        _______,        KC_W,           KC_E,           KC_R,             KC_T,           _______,                                                _______,        KC_Y,           KC_U,             LT(F_C,KC_I),   LT(F_A,KC_O),   _______,        _______,        //
    _______,        KC_Q,           LALT_T(KC_I),   LCTL_T(KC_E),   LSFT_T(KC_A),     KC_COMMA,                                                                               KC_H,           LSFT_T(KC_J),     RCTL_T(KC_K),   LALT_T(KC_L),   KC_P,           _______,        //
    _______,        LGUI_T(KC_C),   RALT_T(KC_X),   KC_J,           KC_K,             KC_UNDS,        _______,                                                _______,        KC_N,           KC_M,             KC_COMMA,       RALT_T(KC_DOT), RGUI_T(KC_SCLN),_______,        //
    _______,        KC_G,           _______,        KC_UNDS,        _______,                                                                                                                  _______,          KC_COMMA,       _______,        KC_SLASH,       _______,        //
 // ---------------------------------------------------------------|-----------------|-------------------------------------------------|   |-------------------------------------------------|-----------------|----------------------------------------------------------------//
                                                                                                      _______,        _______,              _______,          _______,                                                                                                          //
                                                                                                                      _______,              _______,                                                                                                                            //
                                                                                      _______,        _______,        _______,              _______,          _______,        _______                                                                                           //
 //                                                                                  |-------------------------------------------------|   |---------------------------------------------|                                                                                      //
  ),

  // Russian phonetic Engram layout: Switched on left keyboard half: Win+Space (activated programmatically)
  //                б               ы               о               у                 ч                                                                                       з               л                 д               ш              в
  //                ц               и               е               а                 ,                                                                                       .               х                 т               с              н
  //                г               ж               й               к                 _                                                                                       ?               р                 м               ф              п
  [RPE] = LAYOUT_ergodox_pretty(
    _______,        _______,        _______,        _______,        _______,          _______,        _______,                                                _______,        _______,        _______,          _______,        _______,        _______,        _______,        //
    _______,        _______,        KC_S,           KC_J,           KC_E,             KC_X,           _______,                                                _______,        KC_P,           KC_K,             LT(F_C,KC_L),   LT(F_A,KC_I),   _______,        _______,        //
    _______,        KC_COMMA,       LALT_T(KC_B),   LCTL_T(KC_T),   LSFT_T(KC_F),     KC_QUES,                                                                                KC_SLASH,       RSFT_T(KC_LBRC),  RCTL_T(KC_N),   LALT_T(KC_C),   KC_D,           _______,        //
    _______,        LGUI_T(KC_W),   RALT_T(KC_SCLN),KC_Q,           KC_R,             KC_UNDS,        _______,                                                _______,        KC_AMPR,        KC_H,             KC_V,           RALT_T(KC_A),   RGUI_T(KC_Y),   _______,        //
    _______,        KC_U,           _______,        KC_UNDS,        _______,                                                                                                                  _______,          KC_COMMA,       _______,        KC_G,           _______,        //
 // ---------------------------------------------------------------|-----------------|-------------------------------------------------|   |-------------------------------------------------|-----------------|----------------------------------------------------------------//
                                                                                                      _______,        _______,              _______,          _______,                                                                                                          //
                                                                                                                      _______,              _______,                                                                                                                            //
                                                                                      _______,        _______,        _______,              _______,          _______,        OSL(R_LOWER)                                                                                      //
 //                                                                                  |-------------------------------------------------|   |---------------------------------------------|                                                                                      //
  ),

  // Symbols layer, activated when LOWER is tapped or held
  [LOWER] = LAYOUT_ergodox_pretty(
    _______,        _______,        _______,        _______,        _______,          _______,        _______,                                                _______,        _______,        _______,          _______,        _______,        _______,        _______,        //
    _______,        _______,        KC_LT,          KC_GT,          KC_AMPR,          KC_PERC,        _______,                                                _______,        KC_TILDE,       KC_AT,            KC_ASTERISK,    KC_SLASH,       _______,        _______,        //
    _______,        KC_MINUS,       KC_LPRN,        KC_RPRN,        KC_EQUAL,         KC_0,                                                                                   KC_2,           KC_SCOLON,        KC_LCBR,        KC_RCBR,        KC_GRAVE,       _______,        //
    _______,        KC_PLUS,        KC_LBRACKET,    KC_RBRACKET,    KC_PIPE,          KC_1,           _______,                                                _______,        KC_3,           KC_COLON,         KC_CIRC,        KC_BSLASH,      KC_DQUO,        _______,        //
    _______,        KC_EXLM,        _______,        _______,        KC_HASH,                                                                                                                  KC_PERC,          _______,        _______,        KC_QUOTE,       _______,        //
 // ---------------------------------------------------------------|-----------------|-------------------------------------------------|   |-------------------------------------------------|-----------------|----------------------------------------------------------------//
                                                                                                      _______,        _______,              _______,          _______,                                                                                                          //
                                                                                                                      _______,              _______,                                                                                                                            //
                                                                                      KC_DOT,         KC_UNDS,        KC_DOLLAR,            KC_TILDE,         KC_QUES,        KC_COMMA                                                                                          //
 //                                                                                  |-------------------------------------------------|   |---------------------------------------------|                                                                                      //
  ),

  // LOWER layer, when activated from RPE (russian layout): same as LOWER, except characters that cannot be typed + extra russian characters
  [R_LOWER] = LAYOUT_ergodox_pretty(
    _______,        _______,        _______,        _______,        _______,          _______,        _______,                                                _______,        _______,        _______,          _______,        _______,        _______,        _______,        //
    _______,        _______,        KC_QUOT, /*э*/  KC_GRV,/*ё*/    XXXXXXX,          KC_PERC,        _______,                                                _______,        KC_TILDE,       XXXXXXX,          KC_ASTERISK,    KC_PIPE, /*/*/  _______,        _______,        //
    _______,        KC_MINUS,       KC_LPRN,        KC_RPRN,        KC_EQUAL,         KC_0,                                                                                   KC_2,           KC_DOLLAR,/*;*/   KC_M,    /*ь*/  KC_O,    /*щ*/  XXXXXXX,        _______,        //
    _______,        KC_PLUS,        XXXXXXX,        KC_DOT,/*ю*/    KC_Z,    /*я*/    KC_1,           _______,                                                _______,        KC_3,           KC_CIRC,  /*:*/   KC_RBRC, /*ъ*/  KC_BSLASH,      KC_AT,   /*"*/  _______,        //
    _______,        KC_EXLM,        _______,        _______,        KC_HASH, /*№*/                                                                                                            KC_PERC,          _______,        _______,        XXXXXXX,        _______,        //
 // ---------------------------------------------------------------|-----------------|-------------------------------------------------|   |-------------------------------------------------|-----------------|----------------------------------------------------------------//
                                                                                                      _______,        _______,              _______,          _______,                                                                                                          //
                                                                                                                      _______,              _______,                                                                                                                            //
                                                                                      KC_SLASH,/*.*/  _______,        _______,              _______,          KC_AMPR, /*?*/  KC_QUES /*,*/                                                                                     //
 //                                                                                  |-------------------------------------------------|   |---------------------------------------------|                                                                                      //
  ),

  // Historically, multimedia layer, now only programming macros
  [MULTI] = LAYOUT_ergodox_pretty(
    _______,        _______,        _______,        _______,        _______,          _______,        _______,                                                _______,        _______,        _______,          _______,        _______,        _______,         _______,       //
    _______,        _______,        LCTL(KC_Y),     LCTL(KC_O),     LCTL(KC_U),       LCTL(KC_Q),     _______,                                                _______,        KC_PQUEUE,      KC_LINKED,        KC_ARRAY,       KC_LIST,        _______,         _______,       //
    _______,        LCTL(KC_B),     LCTL(KC_I),     LCTL(KC_E),     LCTL(KC_A),       C(KC_COMM),                                                                             KC_COMP,        KC_LT,            KC_COMMA,       KC_SPACE,       KC_DEQUEUE,      _______,       //
    _______,        LCTL(KC_C),     LCTL(KC_X),     LCTL(KC_J),     LCTL(KC_K),       C(KC_SCLN),     _______,                                                _______,        KC_ENTRY,       KC_TREE,          KC_HASH_,       KC_MAP,         KC_GT,           _______,       //
    _______,        LCTL(KC_G),     _______,        _______,        XXXXXXX,                                                                                                                  KC_CHAR,          _______,        _______,        KC_SET,          _______,       //
 // ---------------------------------------------------------------|-----------------|-------------------------------------------------|   |-------------------------------------------------|-----------------|----------------------------------------------------------------//
                                                                                                      _______,        _______,              _______,          _______,                                                                                                          //
                                                                                                                      _______,              _______,                                                                                                                            //
                                                                                      C_S(KC_C),      C_S(KC_V),      TG(QWERTY),           KC_NEW,           KC_INT,         KC_STR                                                                                            //
 //                                                                                  |-------------------------------------------------|   |---------------------------------------------|                                                                                      //
  ),

  // Historically, multimedia layer, now only programming macros (invoked from QWERTY)
  // TODO: then, need QMOUSE, QFUNC? easier to do it programmatically?
  [QMULTI] = LAYOUT_ergodox_pretty(
    _______,        _______,        _______,        _______,        _______,          _______,        _______,                                                _______,        _______,        _______,          _______,        _______,        _______,         _______,       //
    _______,        _______,        LCTL(KC_W),     LCTL(KC_E),     LCTL(KC_R),       LCTL(KC_T),     _______,                                                _______,        KC_PQUEUE,      KC_LINKED,        KC_ARRAY,       KC_LIST,        _______,         _______,       //
    _______,        LCTL(KC_Q),     LCTL(KC_S),     LCTL(KC_D),     LCTL(KC_F),       LCTL(KC_G),                                                                             KC_COMP,        KC_LT,            KC_COMMA,       KC_SPACE,       KC_DEQUEUE,      _______,       //
    _______,        LCTL(KC_A),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),       LCTL(KC_B),     _______,                                                _______,        KC_ENTRY,       KC_TREE,          KC_HASH_,       KC_MAP,         KC_GT,           _______,       //
    _______,        LCTL(KC_Z),     _______,        _______,        XXXXXXX,                                                                                                                  KC_CHAR,          _______,        _______,        KC_SET,          _______,       //
 // ---------------------------------------------------------------|-----------------|-------------------------------------------------|   |-------------------------------------------------|-----------------|----------------------------------------------------------------//
                                                                                                      _______,        _______,              _______,          _______,                                                                                                          //
                                                                                                                      _______,              _______,                                                                                                                            //
                                                                                      C_S(KC_C),      C_S(KC_V),      TG(QWERTY),           KC_NEW,           KC_INT,         KC_STR                                                                                            //
 //                                                                                  |-------------------------------------------------|   |---------------------------------------------|                                                                                      //
  ),

  // MOUSE (+media)
  [MOUSE] = LAYOUT_ergodox_pretty(
    _______,        _______,        _______,        _______,        _______,          _______,        _______,                                                _______,        _______,        _______,          _______,        _______,        _______,         _______,       //
    _______,        _______,        LALT(KC_Y),     LALT(KC_O),     LALT(KC_U),       LALT(KC_Q),     _______,                                                _______,        KC_MEDIA_STOP,  KC_MPRV,          KC_VOLD,        KC_VOLU,        _______,         _______,       //
    _______,        LALT(KC_B),     LALT(KC_I),     LALT(KC_E),     LALT(KC_A),       LALT(KC_COMM),                                                                          KC_MPLY,        KC_MS_LEFT,       KC_MS_DOWN,     KC_MS_UP,       KC_MNXT,         _______,       //
    _______,        LALT(KC_C),     LALT(KC_X),     LALT(KC_J),     LALT(KC_K),       LALT(KC_SCLN),  _______,                                                _______,        KC_MUTE,        KC_WH_L,          KC_WH_D,        KC_WH_U,        KC_MS_RIGHT,     _______,       //
    _______,        LALT(KC_G),     _______,        _______,        XXXXXXX,                                                                                                                  KC_BTN2,          _______,        _______,        KC_WH_R,         _______,       //
 // ---------------------------------------------------------------|-----------------|-------------------------------------------------|   |-------------------------------------------------|-----------------|----------------------------------------------------------------//
                                                                                                      _______,        _______,              _______,          _______,                                                                                                          //
                                                                                                                      _______,              _______,                                                                                                                            //
                                                                                      XXXXXXX,        XXXXXXX,        XXXXXXX,              KC_MUTE,          KC_BTN1,        KC_BTN3                                                                                           //
 //                                                                                  |-------------------------------------------------|   |---------------------------------------------|                                                                                      //
 ),


  [FUNC] = LAYOUT_ergodox_pretty(
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,                                                XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        XXXXXXX,        KC_F7,          KC_F8,          KC_F9,            KC_PSCR,        XXXXXXX,                                                XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        KC_F12,         KC_F4,          KC_F5,          KC_F6,            KC_SLCK,                                                                                XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        KC_F11,         KC_F1,          KC_F2,          KC_F3,            KC_PAUSE,       XXXXXXX,                                                XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        KC_F10,         XXXXXXX,        XXXXXXX ,       LALT(KC_TAB),                                                                                                             XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
 // ---------------------------------------------------------------|-----------------|-------------------------------------------------|   |-------------------------------------------------|-----------------|----------------------------------------------------------------//
                                                                                                      XXXXXXX,        XXXXXXX,              XXXXXXX,          XXXXXXX,                                                                                                          //
                                                                                                                      XXXXXXX,              XXXXXXX,                                                                                                                            //
                                                                                      KC_INSERT,      KC_APPLICATION, LALT(KC_ESC),         XXXXXXX,          XXXXXXX,       XXXXXXX                                                                                            //
 //                                                                                  |-------------------------------------------------|   |---------------------------------------------|                                                                                      //
  ),

  // TG(NUM) does not work
  [NUM] = LAYOUT_ergodox_pretty(
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,                                                XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        XXXXXXX,        KC_7,           KC_8,           KC_9,             KC_SLASH,       XXXXXXX,                                                XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        KC_MINUS,       KC_4,           KC_5,           KC_6,             KC_EQUAL,                                                                               XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        KC_PLUS,        KC_1,           KC_2,           KC_3,             KC_ASTR,        XXXXXXX,                                                XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        KC_DOT,         XXXXXXX,        XXXXXXX ,       KC_DOT,                                                                                                                   XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
 // ---------------------------------------------------------------|-----------------|-------------------------------------------------|   |-------------------------------------------------|-----------------|----------------------------------------------------------------//
                                                                                                      XXXXXXX,        XXXXXXX,              XXXXXXX,          XXXXXXX,                                                                                                          //
                                                                                                                      XXXXXXX,              XXXXXXX,                                                                                                                            //
                                                                                      KC_0,           KC_SPACE,       XXXXXXX,              XXXXXXX,          XXXXXXX,       XXXXXXX                                                                                            //
 //                                                                                  |-------------------------------------------------|   |---------------------------------------------|                                                                                      //
  ),

  // Basic navigation layer, momentarily activated by RAISE hold; locked after RAISE long tap
  [NAV2] = LAYOUT_ergodox_pretty(
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,                                                XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        XXXXXXX,        A(KC_DOWN),     A(KC_UP),       A(KC_RIGHT),      C(KC_A),        XXXXXXX,                                                XXXXXXX,        C(KC_W),        A(KC_HOME),       A(KC_PGDOWN),   A(KC_PGUP),     XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        A(KC_LEFT),     C(KC_DOWN),     C(KC_UP),       C(KC_RIGHT),      C(KC_C),                                                                                C(KC_V),        KC_LEFT,          KC_DOWN,        KC_UP,          A(KC_END),      XXXXXXX,        //
    XXXXXXX,        C(KC_LEFT),     C(KC_PGDOWN),   C(KC_PGUP),     C(KC_END),        C(KC_Z),        XXXXXXX,                                                XXXXXXX,        C(KC_X),        KC_HOME,          KC_PGDOWN,      KC_PGUP,        KC_RIGHT,       XXXXXXX,        //
    XXXXXXX,        C(KC_HOME),     XXXXXXX,        XXXXXXX ,       KC_TAB,                                                                                                                   KC_BSPC,          XXXXXXX,        XXXXXXX,        KC_END,         XXXXXXX,        //
 // ---------------------------------------------------------------|-----------------|-------------------------------------------------|   |-------------------------------------------------|-----------------|----------------------------------------------------------------//
                                                                                                      XXXXXXX,        XXXXXXX,              XXXXXXX,          XXXXXXX,                                                                                                          //
                                                                                                                      XXXXXXX,              XXXXXXX,                                                                                                                            //
                                                                                      C(KC_ENT),      KC_ALT_ERASE,   KC_ESC,               C(KC_DEL),        KC_ENT,         TT(S_NAV2)                                                                                        //
 //                                                                                  |-------------------------------------------------|   |---------------------------------------------|                                                                                      //
  ),

  // Basic navigation layer, momentarily activated by RAISE hold; locked after RAISE long tap
  [S_NAV2] = LAYOUT_ergodox_pretty(
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,                                                XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        XXXXXXX,        A_S(KC_DOWN),   A_S(KC_UP),     A_S(KC_RIGHT),    C_S(KC_A),      XXXXXXX,                                                XXXXXXX,        C_S(KC_W),      A_S(KC_HOME),     A_S(KC_PGDOWN), A_S(KC_PGUP),   XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        A_S(KC_LEFT),   C_S(KC_DOWN),   C_S(KC_UP),     C_S(KC_RIGHT),    C_S(KC_C),                                                                              C_S(KC_V),      S(KC_LEFT),       S(KC_DOWN),     S(KC_UP),       A(KC_END),      XXXXXXX,        //
    XXXXXXX,        C_S(KC_LEFT),   C_S(KC_PGDOWN), C_S(KC_PGUP),   C_S(KC_END),      C_S(KC_Z),      XXXXXXX,                                                XXXXXXX,        C_S(KC_X),      S(KC_HOME),       S(KC_PGDOWN),   S(KC_PGUP),     S(KC_RIGHT),    XXXXXXX,        //
    XXXXXXX,        C_S(KC_HOME),   XXXXXXX,        XXXXXXX ,       KC_TAB,                                                                                                                   C_S(KC_BSPC),     XXXXXXX,        XXXXXXX,        S(KC_END),      XXXXXXX,        //
 // ---------------------------------------------------------------|-----------------|-------------------------------------------------|   |-------------------------------------------------|-----------------|----------------------------------------------------------------//
                                                                                                      XXXXXXX,        XXXXXXX,              XXXXXXX,          XXXXXXX,                                                                                                          //
                                                                                                                      XXXXXXX,              XXXXXXX,                                                                                                                            //
                                                                                      C(KC_ENT),      KC_ALT_ERASE,   KC_ESC,               XXXXXXX,          KC_ENT,         TT(S_NAV2)                                                                                        //
 //                                                                                  |-------------------------------------------------|   |---------------------------------------------|                                                                                      //
  ),

  [F_A] = LAYOUT_ergodox_pretty(
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,                                                XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        XXXXXXX,        A(KC_F7),       A(KC_F8),       A(KC_F9),         A(KC_PSCR),     XXXXXXX,                                                XXXXXXX,        XXXXXXX,        KC_LSFT,          KC_LCTL,        KC_LALT,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        A(KC_F12),      A(KC_F4),       A(KC_F5),       A(KC_F6),         A(KC_SLCK),                                                                             XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        A(KC_F11),      A(KC_F1),       A(KC_F2),       A(KC_F3),         A(KC_PAUSE),    XXXXXXX,                                                XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        A(KC_F10),      XXXXXXX,        XXXXXXX ,       XXXXXXX,                                                                                                                  XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
 // ---------------------------------------------------------------|-----------------|-------------------------------------------------|   |-------------------------------------------------|-----------------|----------------------------------------------------------------//
                                                                                                      XXXXXXX,        XXXXXXX,              XXXXXXX,          XXXXXXX,                                                                                                          //
                                                                                                                      XXXXXXX,              XXXXXXX,                                                                                                                            //
                                                                                      A(KC_INS),      A(KC_APP),      XXXXXXX,              XXXXXXX,          XXXXXXX,       XXXXXXX                                                                                            //
 //                                                                                  |-------------------------------------------------|   |---------------------------------------------|                                                                                      //
  ),

  [F_C] = LAYOUT_ergodox_pretty(
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,                                                XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        XXXXXXX,        C(KC_F7),       C(KC_F8),       C(KC_F9),         C(KC_PSCR),     XXXXXXX,                                                XXXXXXX,        XXXXXXX,        KC_LSFT,          KC_LCTL,        KC_LALT,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        C(KC_F12),      C(KC_F4),       C(KC_F5),       C(KC_F6),         C(KC_SLCK),                                                                             XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        C(KC_F11),      C(KC_F1),       C(KC_F2),       C(KC_F3),         C(KC_PAUSE),    XXXXXXX,                                                XXXXXXX,        XXXXXXX,        XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
    XXXXXXX,        C(KC_F10),      XXXXXXX,        XXXXXXX ,       XXXXXXX,                                                                                                                  XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        //
 // ---------------------------------------------------------------|-----------------|-------------------------------------------------|   |-------------------------------------------------|-----------------|----------------------------------------------------------------//
                                                                                                      XXXXXXX,        XXXXXXX,              XXXXXXX,          XXXXXXX,                                                                                                          //
                                                                                                                      XXXXXXX,              XXXXXXX,                                                                                                                            //
                                                                                      C(KC_INS),      C(KC_APP),      XXXXXXX,              XXXXXXX,          XXXXXXX,       XXXXXXX                                                                                            //
 //                                                                                  |-------------------------------------------------|   |---------------------------------------------|                                                                                      //
  ),
};


// Tap dance

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_LONG_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_SINGLE_TAP_THEN_HOLD,
} td_state_t;


typedef struct {
    td_state_t state;
    uint16_t press_timestamp;
    uint16_t release_timestamp;
} td_tap_t;


static td_tap_t ql_tap_state = {
    .state = TD_NONE,
    .press_timestamp = 0,
    .release_timestamp = 0
};


// Function associated with all tap dances
td_state_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);


// Determine the current tap dance state
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    uprintf("cur_dance: now %d, was %d\n", timer_read(), ql_tap_state.press_timestamp);

    if (state->count == 1) {
        if (state->pressed) {
            return TD_SINGLE_HOLD;
        } else {
            //        uint16_t elapsed = timer_elapsed(ql_tap_state.press_timestamp);
            uint16_t elapsed = TIMER_DIFF_16(ql_tap_state.release_timestamp, ql_tap_state.press_timestamp);
            uprintf("elapsed %d\n", elapsed);

            if (elapsed > 100) {
                uprintf("TD_SINGLE_LONG_TAP\n");
                return TD_SINGLE_LONG_TAP;
            } else {
                return TD_SINGLE_TAP;
            }
        }
    } else if (state->count == 2) {
        return state->pressed ? TD_SINGLE_TAP_THEN_HOLD : TD_DOUBLE_TAP;
    }
    else return TD_UNKNOWN;
}

/*

void ql_each(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t t = timer_read();
    uprintf("EACH sc=%d st=%d t=%d\n", state->count, state->timer, t);
    ql_tap_state.press_timestamp = t;

    //    if (state->count == 1) {
//        uint16_t elapsed = timer_elapsed(state->timer);
//        uprintf("elapsed %d\n", elapsed);
//        ql_tap_state.press_timestamp = elapsed;
//    }
}
*/


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
        case TD_SINGLE_LONG_TAP:
            send_led_state(LED_STATE_NAV_LOCK);
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
//            layer_off(C_NAV);
            break;
        case TD_SINGLE_TAP_THEN_HOLD:
            layer_off(S_NAV2);
//            layer_off(CS_NAV);
            break;
        case TD_DOUBLE_TAP:
        case TD_SINGLE_LONG_TAP:
        case TD_NONE:
        case TD_UNKNOWN:
            break;
    }
    ql_tap_state.state = TD_NONE;
    ql_tap_state.press_timestamp = 0;
}


// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 250)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_ALT_ERASE) {
        // KC_ALT_ERASE is a dummy keycode, to indicate, that NAV locks must be cancelled
        // Assume that NAV2 layer is locked.
        layer_off(NAV2);
        layer_off(S_NAV2);
        send_led_state(0);
        return true;
    }


    if (keycode == QK_TAP_DANCE) {
        // In current layout, there is only one tap dance key: TD_RAISE
        if (record->event.pressed) {
            ql_tap_state.press_timestamp = record->event.time;
            uprintf("process_record_user PRESSED keycode=%04x t=%d\n", keycode, record->event.time);
        } else {
            ql_tap_state.release_timestamp = record->event.time;
            uprintf("process_record_user RELEASED keycode=%04x t=%d\n", keycode, record->event.time);
        }
    }

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

    if (record->event.pressed) {
        switch (keycode) {
            case KC_NEW:
                SEND_STRING("new ");
                break;
            case KC_INT:
                SEND_STRING("Integer");
                break;
            case KC_STR:
                SEND_STRING("String");
                break;
            case KC_CHAR:
                SEND_STRING("Character");
                break;
            case KC_PQUEUE:
                SEND_STRING("PriorityQueue");
                break;
            case KC_LINKED:
                SEND_STRING("Linked");
                break;
            case KC_ARRAY:
                SEND_STRING("Array");
                break;
            case KC_LIST:
                SEND_STRING("List");
                break;
            case KC_DEQUEUE:
                SEND_STRING("Dequeue");
                break;
            case KC_COMP:
                SEND_STRING("Comparator");
                break;
            case KC_ENTRY:
                SEND_STRING("Map.Entry");
                break;
            case KC_TREE:
                SEND_STRING("Tree");
                break;
            case KC_HASH_:
                SEND_STRING("Hash");
                break;
            case KC_MAP:
                SEND_STRING("Map");
                break;
            case KC_SET:
                SEND_STRING("Set");
                break;
        }
    }

    return true;
}
