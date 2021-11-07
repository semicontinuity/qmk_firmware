/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"
#include <stdint.h>
#include <stdbool.h>


inline void board_led_1_on(void) {
    palClearPad(GPIOC, 13);
}

inline void board_led_1_off(void) {
    palSetPad(GPIOC, 13);
}

/*  ---------- LEFT HAND -----------   ---------- RIGHT HAND ---------- */
#define LAYOUT_ergodox_pretty(                                           \
    L00,L01,L02,L03,L04,L05,L06,           R00,R01,R02,R03,R04,R05,R06,  \
    L10,L11,L12,L13,L14,L15,L16,           R10,R11,R12,R13,R14,R15,R16,  \
    L20,L21,L22,L23,L24,L25,                   R21,R22,R23,R24,R25,R26,  \
    L30,L31,L32,L33,L34,L35,L36,           R30,R31,R32,R33,R34,R35,R36,  \
    L40,L41,L42,L43,L44,                           R42,R43,R44,R45,R46,  \
                            L55,L56,   R50,R51,                          \
                                L54,   R52,                              \
                        L53,L52,L51,   R55,R54,R53 )                     \
                                          \
   /* matrix positions */                 \
    {                                     \
    { L00, L10, L20, L30, L40, KC_NO },   \
    { L01, L11, L21, L31, L41, L51 },     \
    { L02, L12, L22, L32, L42, L52 },     \
    { L03, L13, L23, L33, L43, L53 },     \
    { L04, L14, L24, L34, L44, L54 },     \
    { L05, L15, L25, L35, KC_NO, L55 },   \
    { L06, L16, KC_NO, L36, KC_NO, L56 }, \
                                          \
    { R00, R10, KC_NO, R30,KC_NO, R50 },  \
    { R01, R11, R21, R31,KC_NO, R51 },    \
    { R02, R12, R22, R32, R42, R52 },     \
    { R03, R13, R23, R33, R43, R53 },     \
    { R04, R14, R24, R34, R44, R54 },     \
    { R05, R15, R25, R35, R45, R55 },     \
    { R06, R16, R26, R36, R46, KC_NO }    \
    }


/*  ---------- LEFT HAND -----------   ---------- RIGHT HAND ---------- */
#define LAYOUT_ergodox_pretty_pedals(                                    \
    L00,L01,L02,L03,L04,L05,L06,           R00,R01,R02,R03,R04,R05,R06,  \
    L10,L11,L12,L13,L14,L15,L16,           R10,R11,R12,R13,R14,R15,R16,  \
    L20,L21,L22,L23,L24,L25,                   R21,R22,R23,R24,R25,R26,  \
    L30,L31,L32,L33,L34,L35,L36,           R30,R31,R32,R33,R34,R35,R36,  \
    L40,L41,L42,L43,L44,                           R42,R43,R44,R45,R46,  \
                            L55,L56,   R50,R51,                          \
                                L54,   R52,                              \
                        L53,L52,L51,   R55,R54,R53,                      \
                                                                         \
                              P0,P1,   P2,P3)                            \
                                          \
   /* matrix positions */                 \
    {                                     \
    { L00, L10, L20, L30, L40, KC_NO },   \
    { L01, L11, L21, L31, L41, L51 },     \
    { L02, L12, L22, L32, L42, L52 },     \
    { L03, L13, L23, L33, L43, L53 },     \
    { L04, L14, L24, L34, L44, L54 },     \
    { L05, L15, L25, L35,  P0, L55 },     \
    { L06, L16, KC_NO, L36, P1, L56 },    \
                                          \
    { R00, R10, KC_NO, R30, P2, R50 },    \
    { R01, R11, R21, R31, P3, R51 },      \
    { R02, R12, R22, R32, R42, R52 },     \
    { R03, R13, R23, R33, R43, R53 },     \
    { R04, R14, R24, R34, R44, R54 },     \
    { R05, R15, R25, R35, R45, R55 },     \
    { R06, R16, R26, R36, R46, KC_NO }    \
}
