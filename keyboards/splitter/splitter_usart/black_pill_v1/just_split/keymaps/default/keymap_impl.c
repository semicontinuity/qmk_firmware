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

            if (elapsed > 150) {
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


void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            // Ideally, implement it so that when single tapped, caps lock lights up (how?)
            add_oneshot_mods(MOD_MASK_SHIFT);
            uprintf("OS SHIFT\n");
            raise_active = true;
//            raise_activation_time = timer_read32();
//            raise_activation_time16 = timer_read();

//            if (layer_state_is(QWERTY)) {
//                add_oneshot_mods(MOD_MASK_SHIFT);
//            } else {
//                add_oneshot_mods(MOD_MASK_SHIFT);
//            }
            break;
        case TD_SINGLE_LONG_TAP:
            set_lock(LOCK_NAV, true);
//            indicate();
            layer_on(NAV2);
            break;
        case TD_SINGLE_HOLD:
            layer_on(NAV2);
            raise_active = true;
//            raise_activation_time16 = timer_read();
//            raise_activation_time = timer_read32();
            break;
        case TD_DOUBLE_TAP:
            toggle_caps_word();
            break;
        case TD_SINGLE_TAP_THEN_HOLD:
            layer_on(NAV2);
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
            raise_active = false;
            del_mods(MOD_MASK_SHIFT);   // del_oneshot_mods?
//            del_oneshot_mods(MOD_MASK_SHIFT);   // del_oneshot_mods?
//            if (layer_state_is(QWERTY)) {
//                del_mods(MOD_MASK_SHIFT);
//            } else {
//                del_mods(MOD_MASK_SHIFT);
//            }
            break;
        case TD_SINGLE_HOLD:
            raise_active = false;
            layer_off(NAV2);

            // When
//            if (nav_layer_pressed_mask & 1) unregister_code(KC_QUES);
//            if (nav_layer_pressed_mask & 2) unregister_code(KC_DOT);
//            nav_layer_pressed_mask = 0;
//            layer_off(C_NAV);
            break;
        case TD_SINGLE_TAP_THEN_HOLD:
            layer_off(NAV2);
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
    uprintf("process_record_user keycode=%04x pressed=%d\n", keycode, record->event.pressed);

    /*
        // ^C, ^V on long presses (add LT(0, KC_J), LT(0, KC_K) to keymap)
        if (!record->tap.count && record->event.pressed) {
            switch (keycode) {
                case LT(0, KC_J):  // on QWERTY "C"
                    tap_code16(C(KC_C));  // Intercept hold function to send Ctrl-C
                    return false;
                case LT(0, KC_K):  // on QWERTY "V"
                    tap_code16(C(KC_V));  // Intercept hold function to send Ctrl-V
                    return false;
            }
        }
    */

    // Remap certain keys of NAV2 layer, if typed immediately after RAISE:
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
//            uint16_t delay = TIMER_DIFF_16(record->event.time, ql_tap_state.press_timestamp);
//            uprintf("delay=%d\n", delay);
//            if (raise_active && (delay < TAPPING_TERM)) {
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

    if (keycode == TT(S_NAV2)) {
//        uprintf("keycode == TT(S_NAV2), layer_state_is(S_NAV2): %d, pressed: %d\n", layer_state_is(S_NAV2), record->event.pressed);
        // Assume that NAV2 layer is locked.
        if (!layer_state_is(S_NAV2) && !record->event.pressed) {
//            uprintf("S_NAV2 off -> on\n");
            set_lock(LOCK_SHIFT, true);
//            indicate();
        }

        if (layer_state_is(S_NAV2) && record->event.pressed) {
//            uprintf("S_NAV2 on -> off\n");
            set_lock(LOCK_SHIFT, false);
//            indicate();
        }

        return true;
    }
/*

    if (keycode == KC_EXSEL && record->event.pressed) {
        // KC_EXSEL is a dummy keycode, to implement Shift locking
        // Assume that NAV2 layer is locked.
        if (layer_state_is(S_NAV2)) {
            layer_off(S_NAV2);
            if (nav_loc_active) indicate(true, false);
        } else {
            layer_on(S_NAV2);
            if (nav_loc_active) indicate(true, true);
        }
        return false;
    }
*/

    if (keycode == KC_ALT_ERASE) {
        // KC_ALT_ERASE is a dummy keycode, to indicate, that NAV locks must be cancelled
        // Assume that NAV2 layer is locked.
        layer_off(NAV2);
        layer_off(S_NAV2);
        set_lock(LOCK_NAV, false);
        set_lock(LOCK_SHIFT, false);
//        indicate();
        return false;
    }

    // Measure duration of tap dance
    else if (keycode == QK_TAP_DANCE) {
        // In current layout, there is only one tap dance key: TD_RAISE
        if (record->event.pressed) {
            ql_tap_state.press_timestamp = record->event.time;
//            uprintf("process_record_user PRESSED keycode=%04x t=%d\n", keycode, record->event.time);
        } else {
            ql_tap_state.release_timestamp = record->event.time;
//            uprintf("process_record_user RELEASED keycode=%04x t=%d\n", keycode, record->event.time);
        }
    }

    else if (keycode == KC_PEDAL1) {
        register_code(KC_LGUI);
        register_code(KC_SPACE);
        unregister_code(KC_SPACE);
        unregister_code(KC_LGUI);
    }

    //    uprintf("process_record_user\n");
//    uint8_t mod_state = get_mods();
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
/*
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
        break;*/
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
        }
    }

/*
    if (is_turbo_active()) {
        board_led_1_on();
        layer_on(ENGRAM_T);
        if (is_turbo_affected_key(keycode)) {
            uint16_t simple_code = keycode & 0xFF;
            if (record->event.pressed)
                register_code(simple_code);
            else
                unregister_code(simple_code);
            return false;
        }
    } else {
        board_led_1_off();
        layer_off(ENGRAM_T);
    }
*/

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
    return leds ? 0x80 : 0x00;
}

uint8_t caps_byte(void) {
    return caps_byte_for((host_keyboard_leds() & (1U << USB_LED_CAPS_LOCK)));
}


void backlight(void) {
    uint8_t leds = host_keyboard_leds() & (1U << USB_LED_CAPS_LOCK);

    if (new_layer_state != cur_layer_state || leds != cur_leds) {
        uprintf("backlight$0 new_layer_state=%08x cur_layer_state=%08x leds=%02x cur_leds=%02x\n", (unsigned int)new_layer_state, (unsigned int)cur_layer_state, leds, cur_leds);
        switch (get_highest_layer(new_layer_state)) {
            case ENGRAM:
                uprintf("backlight$100\n");
                set_backlight_leds(0x00, 0x00, caps_byte_for(leds));
                break;
            case QWERTY:
                uprintf("backlight$200\n");
                set_backlight_leds(0x80, 0x80, caps_byte_for(leds));
                break;
            case RPE:
                uprintf("backlight$300\n");
                set_backlight_leds(0x80, 0x00, caps_byte_for(leds));
                break;
            case NAV2:
                uprintf("backlight$400\n");
                set_backlight_leds(0x00, 0x80, 0x00);
                break;
            case S_NAV2:
                uprintf("backlight$500\n");
                set_backlight_leds(0x00, 0x80, 0x80);
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
            uprintf("stopwatch$0\n");
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

            uprintf("stopwatch$1 r=%04x g=%04x\n", pattern_r, pattern_g);
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
