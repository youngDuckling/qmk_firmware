ifeq ($(strip $(TRACKBALL_RGB_RAINBOW)), yes)
    OPT_DEFS += -DTRACKBALL_RGB_RAINBOW
	SRC += quantum/color.c
endif
