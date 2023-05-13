#include QMK_KEYBOARD_H
#include "casemodes.h"
#include "layouts.h"
#include <stdio.h>
#include <common/timer.h>


enum {
  TD_RAISE,
  TD_LOWER,
};

enum layer_id {
  ENGRAM        = 0,
  ENGRAM_T      = 1,    // Engram TURBO layer: these character keys lose their double purpose and become ordinary keys when typing very fast
  QWERTY        = 2,
  RPE           = 3,    // Russian phonetic layout (phonetically close to ENGRAM)
  LOWER         = 4,
  R_LOWER       = 5,    // Modified LOWER layer (special chars), invoked from RPE layout
  MULTI         = 6,
  MOUSE         = 7,
  FUNC          = 8,
  NUM           = 9,
  NAV           = 10,
  S_NAV         = 11,
  F_A           = 12,   // Alt+Function keys
  F_C           = 13,   // Ctrl+Function keys
  F_S           = 14,   // Shift+Function keys
  ENGRAM_WIN    = 15,   // Engram keys with Win modifier
};

enum custom_keycodes {
    KC_NEW = SAFE_RANGE,
    KC_BOOL,
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
    KC_SET,

    KC_RETURN_,

    KC_SWATCH1,
    KC_SWATCH2,
    KC_SWATCH3,

    KC_TURBO,

    KC_BL_LESS,
    KC_BL_MORE,

    KC_PEDAL1,
};

void backlight(void);
