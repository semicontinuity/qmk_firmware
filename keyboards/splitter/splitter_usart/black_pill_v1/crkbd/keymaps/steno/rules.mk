KEYBOARD_SHARED_EP  = yes

MOUSEKEY_ENABLE     = no
STENO_ENABLE        = yes
EXTRAKEY_ENABLE    = yes
#CONSOLE_ENABLE     = yes
CONSOLE_ENABLE      = no
COMMAND_ENABLE      = no
NKRO_ENABLE        = yes

EXTRAFLAGS += -flto
SRC += sten.c
