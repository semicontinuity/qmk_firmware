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
  ENGRAM,
  ENGRAM_T,
  QWERTY,
  RPE,      // russian phonetic engram
//  RPE_EXT,  // russian phonetic engram extra characters
  LOWER,
  R_LOWER,  // lower layer (special chars), invoked from russian layout
  MULTI,
  MOUSE,
  FUNC,
  NUM,
  NAV2,
//  C_NAV,
  S_NAV2,
//  CS_NAV
  F_A,          // Alt+Function keys
  F_C,          // Ctrl+Function keys
  F_S,          // Shift+Function keys
  ENGRAM_WIN,   // Engram keys with Win modifier
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
    KC_SET,

    KC_SWATCH1,
    KC_SWATCH2,
    KC_SWATCH3,

    KC_TURBO,
    KC_PEDAL1,
};

void backlight(void);
