//#pragma once

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
    QWERTY,

    ENGRAM,
    ENGRAM_TURBO,
    RPE,      // russian phonetic engram; switched on left keyboard half: Win+Space
    LOWER,
    R_LOWER,  // lower layer (special chars), invoked from russian layout + extra russian characters
    MULTI,
    QMULTI,
    MOUSE,
    FUNC,
    NUM,
    QNUM,     // Numbers (invoked from QWERTY)
    NAV2,
    S_NAV2,
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
    KC_SET,

    KC_SWATCH1,
    KC_SWATCH2,
    KC_SWATCH3,

    KC_TURBO,
    KC_PEDAL1,
};
