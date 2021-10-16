#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE + 2,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_LBRACKET,    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TT(7),                                          TT(2),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_RBRACKET,
    KC_HASH,        KC_B,           KC_Y,           KC_O,           KC_U,           KC_QUOTE,       KC_LEFT,                                        KC_UP,          KC_DQUO,        KC_L,           KC_D,           KC_W,           KC_V,           KC_Z,
    KC_SLASH,       LGUI_T(KC_C),   LALT_T(KC_I),   LCTL_T(KC_E),   LT(11,KC_A),    KC_COMMA,                                                                       KC_DOT,         LT(10,KC_H),    RCTL_T(KC_T),   LALT_T(KC_S),   RGUI_T(KC_N),   KC_Q,
    LM(9,MOD_LSFT), LT(8,KC_G),     RALT_T(KC_X),   KC_J,           KC_K,           KC_MINUS,       KC_RIGHT,                                       KC_DOWN,        KC_QUES,        KC_R,           KC_M,           RALT_T(KC_F),   KC_P,           LM(9,MOD_RSFT),
    KC_AT,          KC_LABK,        KC_RABK,        KC_PSCREEN,     LT(2,KC_ESCAPE),                                                                                                LT(5,KC_DELETE),KC_INSERT,      KC_LBRACKET,    KC_RBRACKET,    KC_CAPSLOCK,
                                                                                                    KC_LCTRL,       KC_LALT,        KC_LALT,        KC_RCTRL,
                                                                                                                    KC_HOME,        KC_PGUP,
                                                                                    LT(1,KC_SPACE), LT(3,KC_TAB),   KC_END,         KC_PGDOWN,      LT(6,KC_ENTER), LT(4,KC_BSPACE)
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PC_CUT,      KC_FIND,        KC_PC_UNDO,     LCTL(LSFT(KC_Z)),KC_CAPSLOCK,    KC_NO,
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_NO,                                                                          KC_PC_COPY,     KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_RALT,        KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PC_PASTE,    KC_HOME,        KC_PGUP,        KC_PGDOWN,      KC_END,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PERC,        KC_7,           KC_8,           KC_9,           KC_BSLASH,      LSFT(KC_TAB),
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_NO,                                                                          KC_PLUS,        KC_4,           KC_5,           KC_6,           KC_ASTR,        KC_TAB,
    KC_TRANSPARENT, KC_NO,          KC_RALT,        KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MINUS,       KC_1,           KC_2,           KC_3,           KC_SLASH,       KC_EQUAL,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_0,           KC_UNDS,        KC_LPRN,        KC_RPRN,        KC_ENTER,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_DELETE,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPACE,      KC_COMMA,       KC_DOT
  ),
  [3] = LAYOUT_ergodox_pretty(
    RESET,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PSCREEN,     KC_F7,          KC_F8,          KC_F9,          KC_CALCULATOR,  KC_NO,
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_NO,                                                                          KC_SCROLLLOCK,  KC_F4,          KC_F5,          KC_F6,          KC_MY_COMPUTER, KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_RALT,        KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PAUSE,       KC_F1,          KC_F2,          KC_F3,          KC_WWW_HOME,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_WWW_SEARCH,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EQUAL,       KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_AMPR,        KC_LABK,                                        KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_CIRC,        KC_LPRN,        KC_RPRN,        KC_DLR,         KC_PERC,                                                                        KC_NO,          KC_RSHIFT,      KC_RCTRL,       KC_LALT,        KC_RGUI,        KC_TRANSPARENT,
    KC_PLUS,        KC_MINUS,       KC_LBRACKET,    KC_RBRACKET,    KC_EXLM,        KC_QUES,        KC_RABK,                                        KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_RALT,        KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_SCOLON,      KC_COMMA,       KC_DOT,         KC_ASTR,                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_UNDS,        KC_TRANSPARENT,
                                                                                    KC_BSLASH,      KC_TILD,        KC_SLASH,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  KC_MS_ACCEL2,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MS_BTN4,     KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_ACCEL1,                                                                   KC_NO,          KC_RSHIFT,      KC_RCTRL,       KC_LALT,        KC_RGUI,        KC_TRANSPARENT,
    KC_NO,          KC_MS_BTN5,     KC_MS_WH_LEFT,  KC_ESCAPE,      KC_MS_WH_RIGHT, KC_MS_ACCEL0,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_RALT,        KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_MS_BTN3,                                                                                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_AUDIO_MUTE,                                                                  KC_NO,          KC_RSHIFT,      KC_RCTRL,       KC_LALT,        KC_RGUI,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MEDIA_STOP,  KC_MEDIA_REWIND,KC_MEDIA_FAST_FORWARD,KC_MEDIA_PLAY_PAUSE,KC_WWW_FAVORITES,KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_RALT,        KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_EJECT, KC_WWW_REFRESH, KC_WWW_SEARCH,                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_MEDIA_PLAY_PAUSE,KC_MEDIA_STOP,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_EQUAL,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,
    KC_ENTER,       KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_SPACE,       KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,
    KC_LALT,        KC_LBRACKET,    KC_RBRACKET,    KC_LSHIFT,      KC_LCTRL,                                                                                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSLASH,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_PAUSE,       KC_LGUI,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 LCTL(KC_C),     ST_MACRO_0,     LSFT(KC_H),     LSFT(KC_M),     LSFT(KC_L),     LSFT(KC_G),     ST_MACRO_1,
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_NO,                                                                          KC_0,           KC_B,           ST_MACRO_2,     KC_E,           KC_W,           KC_DLR,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_RALT,        KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_COLN,        LCTL(KC_I),     LSFT(KC_T),     LSFT(KC_F),     KC_F,           KC_T,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 LCTL(KC_O),     ST_MACRO_3,     ST_MACRO_4,     ST_MACRO_5,     KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, ST_MACRO_6,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_7,     ST_MACRO_8,     ST_MACRO_9
  ),
  [9] = LAYOUT_ergodox_pretty(
    KC_LCBR,        KC_PIPE,        KC_EQUAL,       KC_TILD,        KC_PLUS,        KC_LABK,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_RABK,        KC_CIRC,        KC_AMPR,        KC_PERC,        KC_ASTR,        KC_RCBR,
    KC_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LPRN,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_RPRN,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_BSLASH,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SCOLON,                                                                      KC_COLN,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UNDS,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_EXLM,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_GRAVE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LCBR,        KC_RCBR,        KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [10] = LAYOUT_ergodox_pretty(
    KC_LCBR,        KC_PIPE,        KC_EQUAL,       KC_TILD,        KC_PLUS,        KC_LABK,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_DLR,         RSFT(KC_B),     RSFT(KC_Y),     RSFT(KC_O),     RSFT(KC_U),     KC_LPRN,        RSFT(KC_LEFT),                                  KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_BSLASH,      RSFT(KC_C),     RSFT(KC_I),     RSFT(KC_E),     RSFT(KC_A),     KC_SCOLON,                                                                      KC_NO,          KC_TRANSPARENT, RSFT(KC_RCTRL), RSFT(KC_LALT),  RSFT(KC_RGUI),  KC_NO,
    KC_TRANSPARENT, RSFT(KC_G),     RSFT(KC_X),     RSFT(KC_J),     RSFT(KC_K),     KC_UNDS,        RSFT(KC_RIGHT),                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          RSFT(KC_RALT),  KC_NO,          KC_TRANSPARENT,
    KC_GRAVE,       KC_TRANSPARENT, KC_TRANSPARENT, RSFT(KC_PSCREEN),RSFT(KC_ESCAPE),                                                                                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    RSFT(KC_LCTRL), RSFT(KC_LALT),  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    RSFT(KC_HOME),  KC_TRANSPARENT,
                                                                                    RSFT(KC_SPACE), RSFT(KC_TAB),   RSFT(KC_END),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [11] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_RABK,        KC_CIRC,        KC_AMPR,        KC_PERC,        KC_ASTR,        KC_RCBR,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 LSFT(KC_UP),    KC_RPRN,        LSFT(KC_L),     LSFT(KC_D),     LSFT(KC_W),     LSFT(KC_V),     LSFT(KC_Z),
    KC_NO,          LSFT(KC_LGUI),  LSFT(KC_LALT),  LSFT(KC_LCTRL), KC_TRANSPARENT, KC_NO,                                                                          KC_COLN,        LSFT(KC_H),     LSFT(KC_T),     LSFT(KC_S),     LSFT(KC_N),     LSFT(KC_Q),
    KC_TRANSPARENT, KC_NO,          LSFT(KC_RALT),  KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 LSFT(KC_DOWN),  KC_EXLM,        LSFT(KC_R),     LSFT(KC_M),     LSFT(KC_F),     LSFT(KC_P),     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 LSFT(KC_DELETE),LSFT(KC_INSERT),KC_LCBR,        KC_RCBR,        LSFT(KC_CAPSLOCK),
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_LALT),  LSFT(KC_RCTRL),
                                                                                                                    KC_TRANSPARENT, LSFT(KC_PGUP),
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_PGDOWN),LSFT(KC_ENTER), LSFT(KC_BSPACE)
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_G) SS_DELAY(100) SS_TAP(X_G));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_G) SS_DELAY(100) SS_TAP(X_A));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_G) SS_DELAY(100) SS_LSFT(SS_TAP(X_E)));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_GRAVE));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_LBRACKET));

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_RBRACKET));

    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(100) SS_TAP(X_UP));

    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH) SS_DELAY(100) SS_TAP(X_UP));

    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_G) SS_DELAY(100) SS_LSFT(SS_TAP(X_V)));

    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_G) SS_DELAY(100) SS_TAP(X_V));

    }
    break;
  }
  return true;
}
