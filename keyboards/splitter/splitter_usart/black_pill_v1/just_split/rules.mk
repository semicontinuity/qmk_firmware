# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration

# "MOUSEKEY_ENABLE = yes and EXTRAKEY_ENABLE = yes must both be set to yes in order for console to be enabled."
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control

#CONSOLE_ENABLE = yes        # Console for debug
CONSOLE_ENABLE = no

#COMMAND_ENABLE = yes         # Commands for debug and configuration
COMMAND_ENABLE = no         # Commands for debug and configuration

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE -DHALVES_HAVE_DISTINCT_SCAN_CODES=TRUE

STENO_ENABLE = no
MIDI_ENABLE = no
TERMINAL_ENABLE = no
