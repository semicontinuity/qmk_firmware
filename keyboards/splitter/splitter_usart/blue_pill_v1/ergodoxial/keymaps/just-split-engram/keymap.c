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
    ENGRAM,
    QWERTY,
    RPE,      // russian phonetic engram; switched on left keyboard half: Win+Space
    RPE_EXT,  // russian phonetic engram extra characters (perhaps, delete)
    LOWER,
    R_LOWER,  // lower layer (special chars), invoked from russian layout + extra russian characters
    MULTI,
    QMULTI,
    MOUSE,
    FUNC,
    NUM,
    QNUM,     // Numbers (invoked from QWERTY)
    //  NAV,
    NAV2,
    //  C_NAV,
    //  S_NAV,
    S_NAV2,
    //  CS_NAV
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
    KC_SET
};

#define C_S(kc) (QK_LCTL | QK_LSFT| (kc))
#define A_S(kc) (QK_LALT | QK_LSFT| (kc))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [ENGRAM] = LAYOUT_ergodox_pretty(
    KC_ESC,         KC_LBRC,        KC_2,           KC_3,           KC_4,             KC_5,           KC_LPRN,                                                KC_RPRN,        KC_6,           KC_7,             KC_8,           KC_9,           KC_RBRC,        KC_PSCR,        //
    KC_TAB,         KC_1,           KC_Y,           KC_O,           KC_U,             KC_Q,           KC_PGUP,                                                KC_UP,          KC_Z,           KC_L,             KC_D,           KC_W,           KC_0,           KC_INSERT,      //
    KC_BSPC,        KC_B,           LALT_T(KC_I),   LCTL_T(KC_E),   LSFT_T(KC_A),     KC_COMMA,                                                                               KC_DOT,         LSFT_T(KC_H),     RCTL_T(KC_T),   LALT_T(KC_S),   KC_V,           KC_DELETE,      //
    KC_LSFT,        LGUI_T(KC_C),   RALT_T(KC_X),   KC_J,           KC_K,             KC_UNDS,        KC_PGDOWN,                                              KC_DOWN,        KC_QUES,        KC_R,             KC_M,           RALT_T(KC_F),   RGUI_T(KC_N),   KC_RSFT,        //
    KC_LCTL,        KC_G,           KC_LALT,        KC_COMMA,       LT(MULTI, KC_TAB),                                                                                                        LT(NUM, KC_BSPC), KC_DOT,         KC_RALT,        KC_P,           KC_RCTL,        //
                                                                                                      KC_HOME,        KC_END,               KC_LEFT,          KC_RIGHT,                                                                                                         //
                                                                                                                      KC_LGUI,              KC_APP,                                                                                                                             //
                                                                                      KC_SPACE,       TD(TD_RAISE),   LT(MOUSE, KC_ESC),    LT(FUNC, KC_DEL), KC_ENTER,       OSL(LOWER)                                                                                        //
  ),
};


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

            if (elapsed > 100) {
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

/*

void ql_each(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t t = timer_read();
    uprintf("EACH sc=%d st=%d t=%d\n", state->count, state->timer, t);
    ql_tap_state.press_timestamp = t;

    //    if (state->count == 1) {
//        uint16_t elapsed = timer_elapsed(state->timer);
//        uprintf("elapsed %d\n", elapsed);
//        ql_tap_state.press_timestamp = elapsed;
//    }
}
*/


void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            // Ideally, implement it so that when single tapped, caps lock lights up (how?)
            if (layer_state_is(QWERTY)) {
                add_oneshot_mods(MOD_MASK_SHIFT);
            } else {
                add_oneshot_mods(MOD_MASK_SHIFT);
            }
            break;
        case TD_SINGLE_HOLD:
        case TD_SINGLE_LONG_TAP:
            layer_on(NAV2);
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
            if (layer_state_is(QWERTY)) {
                del_mods(MOD_MASK_SHIFT);
            } else {
                del_mods(MOD_MASK_SHIFT);
            }
            break;
        case TD_SINGLE_HOLD:
            layer_off(NAV2);
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
    [TD_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 250)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == QK_TAP_DANCE) {
        if (record->event.pressed) {
            ql_tap_state.press_timestamp = record->event.time;
            uprintf("process_record_user PRESSED keycode=%04x t=%d\n", keycode, record->event.time);
        } else {
            ql_tap_state.release_timestamp = record->event.time;
            uprintf("process_record_user RELEASED keycode=%04x t=%d\n", keycode, record->event.time);
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
