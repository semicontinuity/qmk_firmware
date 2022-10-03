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
#define LAYOUT_split_3x5_plus_5x( \
  L04, L03, L02, L01, L00,                       R00, R01, R02, R03, R04, \
  L14, L13, L12, L11, L10,    L16,       R16,    R10, R11, R12, R13, R14, \
  L24, L23, L22, L21, L20,                       R20, R21, R22, R23, R24, \
                                                                          \
                 L05,                                 R05,                \
            L26, L15, L06,                       R06, R15, R26,           \
                 L25,                                 R25                 \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05, L06 }, \
    { L10, L11, L12, L13, L14, L15, L16 }, \
    { L20, L21, L22, L23, L24, L25, L26 }, \
    { R00, R01, R02, R03, R04, R05, R06 }, \
    { R10, R11, R12, R13, R14, R15, R16 }, \
    { R20, R21, R22, R23, R24, R25, R26 }, \
  }
