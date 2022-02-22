#include <stdint.h>
#include "raw_hid.h"
#include "splitter_usart.h"

void raw_hid_receive(uint8_t *data, uint8_t length) {
//    set_lock(LOCK_RUS, data[0] & LOCK_RUS);
//    indicate();
}


bool led_update_user(led_t led_state) {
//    set_lock(LOCK_SHIFT, led_state.caps_lock);
//    indicate();
    layer_or(layer_state); // just trigger layer_state_set_user
    return true;
}
