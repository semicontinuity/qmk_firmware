#include <stdint.h>
#include "raw_hid.h"
#include "splitter_usart.h"

void raw_hid_receive(uint8_t *data, uint8_t length) {
    send_led_state(data[0]);
}
