# SRC += $(USER_PATH)/idank.c

ifeq ($(strip $(POINTING_DEVICE)), trackball)
	POINTING_DEVICE_ENABLE = yes
	POINTING_DEVICE_DRIVER = pimoroni_trackball

	ifeq ($(strip $(TRACKBALL_RGB_RAINBOW)), yes)
		SRC += quantum/color.c $(USER_PATH)/trackball_rgb_rainbow.c
	endif

	# Set this when the trackball is on the thumb.
	ifeq ($(strip $(TRACKBALL_THUMB)), yes)
		OPT_DEFS += -DTRACKBALL_THUMB
	endif
endif

ifeq ($(strip $(POINTING_DEVICE)), trackpoint)
	PS2_MOUSE_ENABLE = yes
	PS2_ENABLE = yes
	PS2_DRIVER = interrupt
endif
