#pragma once

#define PRODUCT QMK USART Splitter/BluePill for Ergodoxial

#define MATRIX_ROWS 14
#define MATRIX_ROWS_PER_SIDE (MATRIX_ROWS / 2)
#define MATRIX_COLS 6

#define DIRECT_PINS {\
    /* L00, L10, ... */                                   \
    /* L01, L11, ... */                                   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, A0,     NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, A1,     NO_PIN },   \
    /* R00, R10, ... */                                   \
    /* R01, R11, ... */                                   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, B8,     NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, B9,     NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN },   \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN }    \
}
