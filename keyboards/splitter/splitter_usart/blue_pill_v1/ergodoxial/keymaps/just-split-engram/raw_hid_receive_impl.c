#include <stdint.h>
#include "raw_hid.h"
#include "splitter_usart.h"
#include "keymap.h"

void raw_hid_receive(uint8_t *data, uint8_t length) {
    send_led_state(data[0]);
}

bool led_update_user(led_t led_state) {
    //    set_lock(LOCK_SHIFT, led_state.caps_lock);
    update_status_leds();
    return true;
}
