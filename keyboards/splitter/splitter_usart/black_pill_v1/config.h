#pragma once

#include "config_common.h"

#define UNUSED_PINS

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
//#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 250

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
