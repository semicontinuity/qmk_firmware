KEYBOARD_SHARED_EP  = yes

VERBOSE             = yes

#Firmware reduction options
MOUSEKEY_ENABLE     = no
STENO_ENABLE        = yes
EXTRAKEY_ENABLE    = yes
#CONSOLE_ENABLE     = yes
CONSOLE_ENABLE      = no
COMMAND_ENABLE      = no
NKRO_ENABLE         = yes

NO_TAPPING          = yes          # 2000 bytes
NO_PRINT            = yes

EXTRAFLAGS += -flto
SRC += sten.c
