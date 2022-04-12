#pragma once
#include "config_common.h"

#define VERBOSE

#define FORCE_NKRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define IGNORE_MOD_TAP_INTERRUPT // this makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)

#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY 0
#define TAPPING_TOGGLE  2

/* key combination for command */
#define IS_COMMAND() ( \
get_mods() == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)) || \
get_mods() == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)) \
)

#define DEBOUNCE    5
#define USB_MAX_POWER_CONSUMPTION 500
