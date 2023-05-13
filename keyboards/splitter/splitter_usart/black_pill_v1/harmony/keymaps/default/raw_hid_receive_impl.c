#include <stdint.h>
#include "raw_hid.h"
#include "splitter_usart.h"
#include "keymap.h"


void raw_hid_receive(uint8_t *data, uint8_t length) {
    if (data[0]) layer_on(RPE); else layer_off(RPE);
}


bool led_update_user(led_t led_state) {
    backlight();
    return true;
}
