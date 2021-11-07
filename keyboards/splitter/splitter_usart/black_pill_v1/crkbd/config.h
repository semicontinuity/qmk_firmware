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

#define PRODUCT QMK USART Splitter/BlackPill for crkbd

#define MATRIX_ROWS 8
#define MATRIX_ROWS_PER_SIDE (MATRIX_ROWS / 2)
#define MATRIX_COLS 6

#define DIRECT_PINS {\
    /* L00, L10, ... */                                   \
    /* L01, L11, ... */                                   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    /* R00, R10, ... */                                   \
    /* R01, R11, ... */                                   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN }    \
}
