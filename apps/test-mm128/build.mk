# App name
APP=test-mm128

# Object files
OBJ=main.rel

# LIBS (user-defined) if LIBS not defined then ALL libraies will be used.

# External additional TAP file
EXTTAPS=$(LIBSRC)/libmemman/mm128.drv

EXTTAPS_START=0x6000

# CRT0
# CRT0PATH=$(TOP)/libsrc/crt0/$(CRT0)
