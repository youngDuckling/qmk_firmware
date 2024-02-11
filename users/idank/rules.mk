SERIAL_DRIVER = vendor
# SRC += $(USER_PATH)/idank.c

# Disable things we don't support that take up unnecessary space.
RGBLIGHT_SUPPORTED = no
RGB_MATRIX_SUPPORTED = no

MOUSEKEY_ENABLE = yes

ifeq ($(strip $(POINTING_DEVICE)), trackpoint_trackball)
	OPT_DEFS += -DPOINTING_DEVICE_TRACKPOINT_TRACKBALL

	POINTING_DEVICE_ENABLE = yes
	OPT_DEFS += -DSPLIT_POINTING_ENABLE
	OPT_DEFS += -DPOINTING_DEVICE_COMBINED

	ifeq ($(strip $(SIDE)), left)
		PS2_ENABLE = yes
		PS2_DRIVER = vendor
		POINTING_DEVICE_DRIVER = ps2
	endif
	ifeq ($(strip $(SIDE)), right)
		POINTING_DEVICE_DRIVER = pimoroni_trackball

		ifeq ($(strip $(TRACKBALL_RGB_RAINBOW)), yes)
			SRC += quantum/color.c $(USER_PATH)/trackball_rgb_rainbow.c
		endif
	endif
endif

ifeq ($(strip $(POINTING_DEVICE)), trackball_trackpoint)
	OPT_DEFS += -DPOINTING_DEVICE_TRACKBALL_TRACKPOINT

	POINTING_DEVICE_ENABLE = yes
	OPT_DEFS += -DSPLIT_POINTING_ENABLE
	OPT_DEFS += -DPOINTING_DEVICE_COMBINED

	ifeq ($(strip $(SIDE)), right)
		PS2_ENABLE = yes
		PS2_DRIVER = vendor
		POINTING_DEVICE_DRIVER = ps2
	endif
	ifeq ($(strip $(SIDE)), left)
		POINTING_DEVICE_DRIVER = pimoroni_trackball

		ifeq ($(strip $(TRACKBALL_RGB_RAINBOW)), yes)
			SRC += quantum/color.c $(USER_PATH)/trackball_rgb_rainbow.c
		endif
	endif
endif

ifeq ($(strip $(POINTING_DEVICE)), trackpoint_cirque35)
	OPT_DEFS += -DPOINTING_DEVICE_TRACKPOINT_CIRQUE35

	POINTING_DEVICE_ENABLE = yes
	OPT_DEFS += -DSPLIT_POINTING_ENABLE
	OPT_DEFS += -DPOINTING_DEVICE_COMBINED

	ifeq ($(strip $(SIDE)), left)
		PS2_ENABLE = yes
		PS2_DRIVER = vendor
		POINTING_DEVICE_DRIVER = ps2
	endif
	ifeq ($(strip $(SIDE)), right)
		POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
	endif
endif

ifeq ($(strip $(POINTING_DEVICE)), cirque35_trackpoint)
	OPT_DEFS += -DPOINTING_DEVICE_CIRQUE35_TRACKPOINT

	POINTING_DEVICE_ENABLE = yes
	OPT_DEFS += -DSPLIT_POINTING_ENABLE
	OPT_DEFS += -DPOINTING_DEVICE_COMBINED

	ifeq ($(strip $(SIDE)), right)
		PS2_ENABLE = yes
		PS2_DRIVER = vendor
		POINTING_DEVICE_DRIVER = ps2
	endif
	ifeq ($(strip $(SIDE)), left)
		POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
	endif
endif
