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

#define PRODUCT USART Splitter/BlackPill for JustSplit

#define MATRIX_ROWS 8
#define MATRIX_ROWS_PER_SIDE (MATRIX_ROWS / 2)
#define MATRIX_COLS 5

#define FLIP_COLS

// "A1" works, "A0" does not (no pull-up voltage)
// Not sure: perhaps A0 must be in the first line?
#define DIRECT_PINS {\
{ NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
{ NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
{ NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
{ A0,     NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
{ NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
{ NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
{ NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
{ A1,     NO_PIN, NO_PIN, NO_PIN, NO_PIN }    \
}
