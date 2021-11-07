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

#pragma once
#include <hal.h>


inline void board_led_1_init(void) {
    palSetPadMode(ONBOARD_LED_PORT, ONBOARD_LED_PAD, PAL_MODE_OUTPUT_PUSHPULL);
}

inline void board_led_1_on(void) {
    palClearPad(ONBOARD_LED_PORT, ONBOARD_LED_PAD);
}

inline void board_led_1_off(void) {
    palSetPad(ONBOARD_LED_PORT, ONBOARD_LED_PAD);
}
