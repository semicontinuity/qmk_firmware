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

// (initial)

// clang-format off
#define LAYOUT_split_3x5_3_p( \
  L00, L01, L02, L03, L04,                       R00, R01, R02, R03, R04, \
  L10, L11, L12, L13, L14,                       R10, R11, R12, R13, R14, \
  L20, L21, L22, L23, L24,                       R20, R21, R22, R23, R24, \
       LP,       L30, L31, L32, L33,   R30, R31, R32, R33,      RP        \
  ) \
  { \
    { L00, L01, L02, L03, L04 }, \
    { L10, L11, L12, L13, L14 }, \
    { L20, L21, L22, L23, L24 }, \
    { LP,  L30, L31, L32, L33 }, \
    { R04, R03, R02, R01, R00 }, \
    { R14, R13, R12, R11, R10 }, \
    { R24, R23, R22, R21, R20 }, \
    { RP,  R33, R32, R31, R30 } \
  }
