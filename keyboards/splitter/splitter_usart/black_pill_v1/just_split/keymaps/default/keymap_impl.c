#include "keymap.h"
#include "wpm_mod.h"

bool raise_active = false;
uint16_t raise_activation_time16 = 0;
uint32_t raise_activation_time = 0;
uint32_t nav_layer_pressed_mask = 0;


// Stopwatch
uint32_t stopwatch_start_ts = 0;
uint32_t unit_minutes = 0;
int16_t cur_time_slot = -1;


// Turbo
#include "wpm.h"

enum turbo_mode_t {
    TURBO_OFF,
    TURBO_AUTO,
    TURBO_ON
};

uint32_t turbo_mode = TURBO_OFF;


// Backlight
volatile uint8_t bl_brightness = 0x20;


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

    if (state->count == 1) {
        if (state->pressed) {
            return TD_SINGLE_HOLD;
        } else {
            uint16_t elapsed = TIMER_DIFF_16(ql_tap_state.release_timestamp, ql_tap_state.press_timestamp);

            if (elapsed > 150) {
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


void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            // Ideally, implement it so that when single tapped, caps lock lights up (how?)
            add_oneshot_mods(MOD_MASK_SHIFT);
            raise_active = true;
            break;
        case TD_SINGLE_LONG_TAP:
            set_lock(LOCK_NAV, true);
            layer_on(NAV);
            break;
        case TD_SINGLE_HOLD:
            layer_on(NAV);
            raise_active = true;
            break;
        case TD_DOUBLE_TAP:
            toggle_caps_word();
            break;
        case TD_SINGLE_TAP_THEN_HOLD:
            layer_on(NAV);
            layer_on(S_NAV);
            break;
        case TD_NONE:
        case TD_UNKNOWN:
            break;
    }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            raise_active = false;
            del_mods(MOD_MASK_SHIFT);   // del_oneshot_mods?
            break;
        case TD_SINGLE_HOLD:
            raise_active = false;
            layer_off(NAV);
            break;
        case TD_SINGLE_TAP_THEN_HOLD:
            layer_off(NAV);
            layer_off(S_NAV);
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


// =============================================================================================================
// Tap dance for LOWER key
// The functionality is equivalent to one-shot layer: OSL(LOWER), i.e.
// - tap LOWER, then key: enter character from LOWER layer
// - hold LOWER, keys, release LOWER: enter multiple characters from LOWER layer, while LOWER key is held down.
// The difference is, that "standard" OSL is a bit buggy:
// if "press LOWER, key1, key2, release LOWER" is executed quickly, unexpected characters are registered.
// E.g., instead of "+=", "++" is registered.
// First character has implicit "Shift" modifier that is erroneously applied to the next character.
typedef enum {
    TD_LOWER_NONE,
    TD_LOWER_UNKNOWN,
    TD_LOWER_SINGLE_TAP,
    TD_LOWER_SINGLE_HOLD,
} td_lower_state_t;

typedef struct {
    td_lower_state_t state;
} td_lower_tap_t;

static td_lower_tap_t ql_lower_tap_state = {
    .state = TD_LOWER_NONE
};

// Function associated with all LOWER key tap dances
td_lower_state_t lower_cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);


// Determine the current tap dance state of LOWER key
td_lower_state_t lower_cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->pressed) {
            return TD_LOWER_SINGLE_HOLD;
        } else {
            return TD_LOWER_SINGLE_TAP;
        }
    } else return TD_LOWER_UNKNOWN;
}


void ql_lower_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_lower_tap_state.state = lower_cur_dance(state);
    switch (ql_lower_tap_state.state) {
        case TD_LOWER_SINGLE_TAP:
            if (layer_state_is(RPE)) {
                layer_on(R_LOWER);
                set_oneshot_layer(R_LOWER, ONESHOT_START);
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            } else {
                layer_on(LOWER);
                set_oneshot_layer(LOWER, ONESHOT_START);
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
            break;
        case TD_LOWER_SINGLE_HOLD:
            if (layer_state_is(RPE)) {
                layer_on(R_LOWER);
            } else {
                layer_on(LOWER);
            }
            break;
        case TD_NONE:
        case TD_UNKNOWN:
            break;
    }
}

void ql_lower_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ql_lower_tap_state.state) {
        case TD_LOWER_SINGLE_TAP:
            break;
        case TD_LOWER_SINGLE_HOLD:
            layer_off(LOWER);
            layer_off(R_LOWER);
            break;
        case TD_NONE:
        case TD_UNKNOWN:
            break;
    }
    ql_lower_tap_state.state = TD_LOWER_NONE;
}

// =============================================================================================================

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, TAPPING_TERM),
    [TD_LOWER] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_lower_finished, ql_lower_reset, TAPPING_TERM),
};


void start_stop_stopwatch(uint16_t unit) {
    if (unit_minutes == unit && stopwatch_start_ts) {
        stopwatch_start_ts = 1L;
        cur_time_slot = -1;
    } else {
        stopwatch_start_ts = timer_read32();
        unit_minutes       = unit;
    }
}


bool is_turbo_active(void) {
    return (turbo_mode == TURBO_ON || (turbo_mode == TURBO_AUTO && get_current_wpm() > TURBO_AUTO_THRESHOLD_WPM));
}

bool is_turbo_affected_key(uint16_t keycode) {
    if (keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) {
        return true;
    } else if (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) {
        uint16_t layer = (keycode >> 8U) & 0xFU;
        if (layer >= F_A) {
            return true;
        }
    }
    return false;
}

/**
 * If returns true QMK will process the keycodes as usual.
 * If returns false QMK will skip the normal key handling, and it will be up to you to send any key up or down events that are required.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // Remap certain keys of NAV layer, if typed immediately after RAISE:
    uint16_t nav_layer_remapped_key = 0;
    uint32_t nav_layer_mask = 0;

    if (record->event.key.row == 3) {
        // Left thumb cluster
        if (record->event.key.col == 1) {
            nav_layer_remapped_key = C(KC_C);
            nav_layer_mask         = 1;
        }
        if (record->event.key.col == 2) {
            nav_layer_remapped_key = C(KC_V);
            nav_layer_mask         = 1;
        }
    }
    if (record->event.key.row == 7) {
        // Right thumb cluster
        if (record->event.key.col == 4) {
            nav_layer_remapped_key = KC_QUES;
            nav_layer_mask         = 1;
        }
        if (record->event.key.col == 3) {
            nav_layer_remapped_key = KC_COMMA;
            nav_layer_mask         = 1;
        }
        if (record->event.key.col == 2) {
            nav_layer_remapped_key = KC_DOT;
            nav_layer_mask         = 1;
        }
        if (record->event.key.col == 1) {
            nav_layer_remapped_key = C(KC_BSPC);
            nav_layer_mask         = 1;
        }
    }

    if (nav_layer_remapped_key) {
        if (record->event.pressed) {
            if ((get_oneshot_mods() & MOD_MASK_SHIFT)) {
                del_oneshot_mods(MOD_MASK_SHIFT);
                nav_layer_pressed_mask |= nav_layer_mask;
                register_code16(nav_layer_remapped_key);
                return false;
            }
        } else if (nav_layer_pressed_mask & nav_layer_mask) {
            nav_layer_pressed_mask &= ~nav_layer_mask;
            unregister_code16(nav_layer_remapped_key);
            return false;
        }
    }

    if (keycode == TT(S_NAV)) {
        // Assume that NAV layer is locked.
        if (!layer_state_is(S_NAV) && !record->event.pressed) {
            set_lock(LOCK_SHIFT, true);
        }

        if (layer_state_is(S_NAV) && record->event.pressed) {
            set_lock(LOCK_SHIFT, false);
        }

        return true;
    }

    if (keycode == KC_ALT_ERASE) {
        // KC_ALT_ERASE is a dummy keycode, to indicate, that NAV locks must be cancelled
        // Assume that NAV layer is locked.
        layer_off(NAV);
        layer_off(S_NAV);
        set_lock(LOCK_NAV, false);
        set_lock(LOCK_SHIFT, false);
        return false;
    }

    // Measure duration of tap dance
    else if (keycode == QK_TAP_DANCE) {
        // In current layout, there is only one tap dance key: TD_RAISE
        if (record->event.pressed) {
            ql_tap_state.press_timestamp = record->event.time;
        } else {
            ql_tap_state.release_timestamp = record->event.time;
        }
    }

    else if (keycode == KC_PEDAL1) {
        register_code(KC_LGUI);
        register_code(KC_SPACE);
        unregister_code(KC_SPACE);
        unregister_code(KC_LGUI);
    }

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
    }

    if (record->event.pressed) {
        switch (keycode) {
            case KC_NEW:
                SEND_STRING("new ");
                break;
            case KC_BOOL:
                SEND_STRING("Boolean");
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

            case KC_RETURN_:
                SEND_STRING("return ");
                break;

            // stopwatch_start_ts == 1L will make it expired (to stop and re-display)
            case KC_SWATCH1: // 15 min
                start_stop_stopwatch(1);
                break;
            case KC_SWATCH2: // 30 min
                start_stop_stopwatch(2);
                break;
            case KC_SWATCH3: // 60 min
                start_stop_stopwatch(4);
                break;

            case KC_TURBO:
                turbo_mode = (turbo_mode + 1) % 3;
                break;
            case KC_BL_LESS:
                if (bl_brightness > 0x00) {
                    bl_brightness -= 0x04;
                }
                break;
            case KC_BL_MORE:
                if (bl_brightness < 0xf8) {
                    bl_brightness += 0x04;
                }
                break;
        }
    }

    if (record->event.pressed) {
        update_wpm(keycode);
    }

    return true;
}

// Backlight
// =============================================================================================================

volatile layer_state_t cur_layer_state = 0;
volatile layer_state_t new_layer_state;

volatile uint8_t cur_leds = 0;


uint8_t caps_byte_for(uint8_t leds) {
    return leds ? bl_brightness : 0x00;
}

uint8_t caps_byte(void) {
    return caps_byte_for((host_keyboard_leds() & (1U << USB_LED_CAPS_LOCK)));
}


void backlight(void) {
    uint8_t leds = host_keyboard_leds() & (1U << USB_LED_CAPS_LOCK);

    if (new_layer_state != cur_layer_state || leds != cur_leds) {
        switch (get_highest_layer(new_layer_state)) {
            case ENGRAM:
                set_backlight_leds(0x00, 0x00, caps_byte_for(leds));
                break;
            case QWERTY:
                set_backlight_leds(0x80, bl_brightness, caps_byte_for(leds));
                break;
            case RPE:
                set_backlight_leds(bl_brightness, 0x00, caps_byte_for(leds));
                break;
            case NAV:
                set_backlight_leds(0x00, bl_brightness, 0x00);
                break;
            case S_NAV:
                set_backlight_leds(0x00, bl_brightness, bl_brightness);
                break;
        }

        cur_leds        = leds;
        cur_layer_state = new_layer_state;
    }
}


layer_state_t layer_state_set_user(layer_state_t state) {
    new_layer_state = state;
    backlight();
    return state;
}


// "Stopwatch" using 16 Red/Green LEDs
// =============================================================================================================

void stopwatch(void) {
    if (stopwatch_start_ts > 0) {

        if (stopwatch_start_ts == 1) {
            stopwatch_start_ts = 0;
            set_led_bars(0, 0);
            return;
        }

        uint32_t elapsed = timer_elapsed32(stopwatch_start_ts);
        int16_t time_slot = elapsed / 60000 / unit_minutes;

        if (time_slot != cur_time_slot) {
            cur_time_slot = time_slot;

            uint16_t pattern_r = 0;
            uint16_t pattern_g = 0;
            uint16_t pattern = 1U << time_slot;
            if (time_slot >= 16) {
                stopwatch_start_ts = 0;
                pattern_r = 0;
                pattern_g = 0;
            } else if (time_slot == 15) {
                pattern_r = pattern;
                pattern_g = 0;
            } else if (time_slot == 14) {
                pattern_r = pattern;
                pattern_g = pattern;
            } else  {
                pattern_r = 0;
                pattern_g = pattern;
            }

            set_led_bars(pattern_r, pattern_g);
        }
    }
}


// Auto-turbo
// =============================================================================================================

void auto_turbo(void) {
    if (is_turbo_active()) {
        if (!layer_state_is(ENGRAM_T)) {
            board_led_1_on();
            layer_on(ENGRAM_T);
        }
    } else {
        if (layer_state_is(ENGRAM_T)) {
            board_led_1_off();
            layer_off(ENGRAM_T);
        }
    }
}

// =============================================================================================================

void housekeeping_task_user(void) {
    backlight();
    stopwatch();
    auto_turbo();
}
