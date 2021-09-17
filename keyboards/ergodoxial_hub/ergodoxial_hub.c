//#include "stm32f103xb.h"
//#include "config.h"
//#include "board.h"
//#include "hal_pal.h"

#include "ergodoxial_hub.h"
#include QMK_KEYBOARD_H
#include "matrix.h"
#include "action.h"
#include "timer.h"
#include <hal.h>
#include "print.h"


//uint8_t logical_column_mapping[8] = {3, 4, 5, 6, 0, 1, 2, 7/* out of range*/};
//uint8_t logical_row_mapping[8] = {1, 2, 3, 4, 5, 6/* out of range*/, 7/* out of range*/};
keyevent_t key_event = {.key = (keypos_t){.row = 0, .col = 0}, .pressed = true};


uint8_t logical_column_of(uint8_t event) {
    return (event >> 3U) & 7;
}

uint8_t logical_row_of(uint8_t event) {
    return event & 7;
}

bool is_released(uint8_t event) {
    return (event & 0x40U) != 0;
}


extern SerialDriver SD1;
extern SerialDriver SD3;


uint8_t uart_getchar(SerialDriver *sdp) {
    msg_t res = sdGet(sdp);
    return (uint8_t)res;
}

bool uart_available(SerialDriver *sdp) { return !sdGetWouldBlock(sdp); }


static void process_remote_kbd_events(void) {
    while (uart_available(&SD1)) {
        board_led_1_on();

        uint8_t event = uart_getchar(&SD1);
        if (/*event & 0x80*/1) {
            uprintf("!U1 event: 0x%02x\n", event);
            key_event.time = (timer_read() | 1);
            key_event.pressed = !is_released(event);
            key_event.key.row = logical_column_of(event);
            key_event.key.col = logical_row_of(event);
            uprintf("Key event: row: %d, col: %d, pressed: %d\n", key_event.key.row, key_event.key.col, key_event.pressed);

            action_exec(key_event);
        }
    }

    while (uart_available(&SD3)) {
        board_led_1_on();

        uint8_t event = uart_getchar(&SD3);
        if (/*event & 0x80*/1) {
            uprintf("!U3 event: 0x%02x\n", event);
            key_event.time = (timer_read() | 1);
            key_event.pressed = !is_released(event);
            key_event.key.row = 13 - logical_column_of(event);
            key_event.key.col = logical_row_of(event);
            uprintf("Key event: row: %d, col: %d, pressed: %d\n", key_event.key.row, key_event.key.col, key_event.pressed);
            action_exec(key_event);
        }
    }
}


void matrix_init_kb(void) {
    // Init on-board LED
    palSetPadMode(GPIOC, 13, PAL_MODE_OUTPUT_PUSHPULL);

    matrix_init_user();
//    uprintf("Init");
}


//static SerialConfig serialConfig = {SERIAL_DEFAULT_BITRATE, 0, 0, 0};

void matrix_init_user(void) {
    sdStart(&SD1, NULL);
//    palSetPadMode(GPIOA, 9, PAL_MODE_STM32_ALTERNATE_PUSHPULL);
//    palSetPadMode(GPIOA, 10, PAL_MODE_INPUT_PULLUP | PAL_MODE_STM32_ALTERNATE_PUSHPULL);
//    sdStart(&SD1, &serialConfig);


    sdStart(&SD3, NULL);
//    palSetPadMode(GPIOB, 10,
//                  PAL_STM32_MODE_ALTERNATE | PAL_STM32_OTYPE_PUSHPULL | PAL_STM32_OSPEED_HIGHEST | PAL_STM32_ALTERNATE(7));
//    palSetPadMode(GPIOB, 11,
//                  PAL_STM32_MODE_ALTERNATE | PAL_STM32_PUDR_PULLUP | PAL_STM32_ALTERNATE(7));
//    sdStart(&SD3, &serialConfig);
}

void matrix_scan_user(void) { process_remote_kbd_events(); }

void keyboard_post_init_user(void) {
    debug_enable=true;
//    uprintf("keyboard_post_init_user\n");
}