# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration

# "MOUSEKEY_ENABLE = yes and EXTRAKEY_ENABLE = yes must both be set to yes in order for console to be enabled."
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output

LAYOUTS = split_3x6_3

# MCU name
#MCU = STM32F103
MCU = STM32F401

# Bootloader selection
#BOOTLOADER = stm32duino
BOOTLOADER = stm32-dfu

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE -DHALVES_HAVE_DISTINCT_SCAN_CODES=TRUE

QUANTUM_LIB_SRC += uart.c

TAP_DANCE_ENABLE = yes
