/*
Copyright 2021 semicontinuity

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//#include "stm32f103xb.h"  // for editing in IDE
//#include "board.h"        // for editing in IDE
//#include "hal_pal.h"      // for editing in IDE
//#include "config.h"       // for editing in IDE

#include "splitter_usart.h"

#include QMK_KEYBOARD_H
#include "matrix.h"
#include "action.h"
#include "timer.h"
#include <hal.h>
#include <stdio.h>
#include <config.h>
#include "print.h"


extern matrix_row_t matrix[MATRIX_ROWS];


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


extern SerialDriver SD_LEFT;
extern SerialDriver SD_RIGHT;


uint8_t uart_getchar(SerialDriver *sdp) {
    msg_t res = sdGet(sdp);
    return (uint8_t)res;
}

bool uart_available(SerialDriver *sdp) { return !sdGetWouldBlock(sdp); }


static void process_remote_kbd_events(SerialDriver *sdp, uint8_t row_offset) {
    while (uart_available( sdp)) {
        uint8_t event = uart_getchar(sdp);
        // Can modify the protocol to always set bit 7 (and check it here), so have more protection against received 'glitch' events
        key_event.time = (timer_read() | 1);
        key_event.pressed = !is_released(event);
        key_event.key.row = row_offset + logical_column_of(event);
        key_event.key.col = logical_row_of(event);

        if (key_event.pressed) {
            matrix[key_event.key.row] |= 1U << key_event.key.col;
        } else {
            matrix[key_event.key.row] &= ~(1U << key_event.key.col);
        }
        // If no debouncing (pedals) is needed, and no two-copies protocol is used, then can simply call action_exec(key_event);
    }
}


void matrix_init_kb(void) {
    matrix_init_user();
}


void matrix_init_user(void) {
    // Ideally, configure UART pads with pull-ups, for disconnected not to register false data (unconnected pad reads 0)
#if defined(SD_LEFT_TX_PORT) && defined(SD_LEFT_TX_PAD) && defined(SD_LEFT_RX_PORT) && defined(SD_LEFT_RX_PAD)
    palSetPadMode(SD_LEFT_TX_PORT, SD_LEFT_TX_PAD, PAL_MODE_ALTERNATE(7));
    palSetPadMode(SD_LEFT_RX_PORT, SD_LEFT_RX_PAD, PAL_MODE_ALTERNATE(7));
#endif
    sdStart(&SD_LEFT, NULL);

#if defined(SD_RIGHT_TX_PORT) && defined(SD_RIGHT_TX_PAD) && defined(SD_RIGHT_RX_PORT) && defined(SD_RIGHT_RX_PAD)
    palSetPadMode(SD_RIGHT_TX_PORT, SD_RIGHT_TX_PAD, PAL_MODE_ALTERNATE(7));
    palSetPadMode(SD_RIGHT_RX_PORT, SD_RIGHT_RX_PAD, PAL_MODE_ALTERNATE(7));
#endif
    sdStart(&SD_RIGHT, NULL);
}


void matrix_scan_user(void) {
    process_remote_kbd_events(&SD_LEFT, 0);
    process_remote_kbd_events(&SD_RIGHT, MATRIX_ROWS/2);
}
