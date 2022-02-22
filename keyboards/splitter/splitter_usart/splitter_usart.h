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

#include "quantum.h"
#include <stdint.h>
#include <stdbool.h>


void send_led_state(uint8_t state);

void kb_half_send_byte(bool right_half, uint8_t value);

void set_backlight_leds(uint8_t r, uint8_t g, uint8_t b);

#define LOCK_NAV 0x01
#define LOCK_SHIFT 0x02
#define LOCK_NUM 0x04
#define LOCK_RUS 0x08

void set_lock(uint8_t lock, bool on);



void kb_half_set_led_bar(bool right_half, uint16_t r, uint16_t g);
void set_led_bars(uint16_t r, uint16_t g);
