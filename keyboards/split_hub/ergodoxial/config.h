#pragma once

#include "config_common.h"

#define PRODUCT Bluepill STM32F103

#define MATRIX_ROWS 14
#define MATRIX_ROWS_PER_SIDE (MATRIX_ROWS / 2)
#define MATRIX_COLS 6

#define UNUSED_PINS

#define DIRECT_PINS {\
    /* L00, L10, ... */                                   \
    /* L01, L11, ... */                                   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, A0,     NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, A1,     NO_PIN },   \
    /* R00, R10, ... */                                   \
    /* R01, R11, ... */                                   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, B8,     NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, B9,     NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN }    \
}

/* USB Device descriptor parameter */
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x6465
#define DEVICE_VER   0x0001
#define MANUFACTURER QMK

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 250

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
