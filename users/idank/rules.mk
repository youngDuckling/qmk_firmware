POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pimoroni_trackball

SRC += $(USER_PATH)/idank.c

ifeq ($(strip $(TRACKBALL_RGB_RAINBOW)), yes)
	SRC += quantum/color.c $(USER_PATH)/trackball_rgb_rainbow.c
endif

# Set this when the trackball is on the thumb.
ifeq ($(strip $(TRACKBALL_THUMB)), yes)
	OPT_DEFS += -DTRACKBALL_THUMB
endif
