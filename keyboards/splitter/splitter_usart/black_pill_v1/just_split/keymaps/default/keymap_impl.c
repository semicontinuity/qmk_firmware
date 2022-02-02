#include "keymap.h"

bool raise_active = false;
uint16_t raise_activation_time16 = 0;
uint32_t raise_activation_time = 0;
uint32_t nav_layer_pressed_mask = 0;


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
//            send_led_state(LED_STATE_NAV_LOCK);
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
    [TD_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, TAPPING_TERM)
};


/**
 * If returns true QMK will process the keycodes as usual.
 * If returns false QMK will skip the normal key handling, and it will be up to you to send any key up or down events that are required.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    uprintf("process_record_user keycode=%04x %s\n", keycode, record->event.pressed ? "PRESSED" : "RELEASED");

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
        if (record->event.key.col == 3) {
            nav_layer_remapped_key = KC_COMMA;
            nav_layer_mask         = 1;
        }
        if (record->event.key.col == 2) {
            nav_layer_remapped_key = KC_DOT;
            nav_layer_mask         = 1;
        }
        if (record->event.key.col == 1) {
            nav_layer_remapped_key = KC_QUES;
            nav_layer_mask         = 1;
        }
    }

    if (nav_layer_remapped_key) {
        if (record->event.pressed) {
            uint16_t delay = TIMER_DIFF_16(record->event.time, ql_tap_state.press_timestamp);
//            uprintf("delay=%d\n", delay);
            if (raise_active && (delay < TAPPING_TERM)) {
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


    if (keycode == KC_ALT_ERASE) {
        // KC_ALT_ERASE is a dummy keycode, to indicate, that NAV locks must be cancelled
        // Assume that NAV2 layer is locked.
        layer_off(NAV2);
        layer_off(S_NAV2);
//        send_led_state(0);
        return false;
    }

    // Measure duration of tap dance
    if (keycode == QK_TAP_DANCE) {
        // In current layout, there is only one tap dance key: TD_RAISE
        if (record->event.pressed) {
            ql_tap_state.press_timestamp = record->event.time;
//            uprintf("process_record_user PRESSED keycode=%04x t=%d\n", keycode, record->event.time);
        } else {
            ql_tap_state.release_timestamp = record->event.time;
//            uprintf("process_record_user RELEASED keycode=%04x t=%d\n", keycode, record->event.time);
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
