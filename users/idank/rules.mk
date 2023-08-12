# SRC += $(USER_PATH)/idank.c

# Disable things we don't support that take up unnecessary space.
RGBLIGHT_SUPPORTED = no
RGB_MATRIX_SUPPORTED = no

ifeq ($(strip $(POINTING_DEVICE)), trackball)
	POINTING_DEVICE_ENABLE = yes
	POINTING_DEVICE_DRIVER = pimoroni_trackball

	ifeq ($(strip $(TRACKBALL_RGB_RAINBOW)), yes)
		SRC += quantum/color.c $(USER_PATH)/trackball_rgb_rainbow.c
	endif

	ifeq ($(strip $(TRACKBALL_POSITION)), left)
		OPT_DEFS += -DTRACKBALL_POSITION_LEFT
	else ifeq ($(strip $(TRACKBALL_POSITION)), thumb)
		OPT_DEFS += -DTRACKBALL_POSITION_THUMB
	else ifeq ($(strip $(TRACKBALL_POSITION)), middle)
		OPT_DEFS += -DTRACKBALL_POSITION_MIDDLE
	else
		OPT_DEFS += -DTRACKBALL_POSITION_RIGHT
	endif
endif

ifeq ($(strip $(POINTING_DEVICE)), trackpoint)
	PS2_MOUSE_ENABLE = yes
	PS2_ENABLE = yes
	# PS2_DRIVER = busywait
	PS2_DRIVER = interrupt
endif

MOUSEKEY_ENABLE = yes
