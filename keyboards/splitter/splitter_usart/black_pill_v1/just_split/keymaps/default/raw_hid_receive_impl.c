#include <stdint.h>
#include "raw_hid.h"
#include "splitter_usart.h"
#include "keymap.h"

void raw_hid_receive(uint8_t *data, uint8_t length) {
//    set_lock(LOCK_RUS, data[0] & LOCK_RUS);
//    indicate();
    if (data[0]) layer_on(RPE); else layer_off(RPE);
}


bool led_update_user(led_t led_state) {
//    set_lock(LOCK_SHIFT, led_state.caps_lock);
    backlight();
    return true;
}
