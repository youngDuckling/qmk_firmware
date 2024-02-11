#pragma once

#undef MASTER_LEFT
#undef EE_HANDS
#undef MASTER_RIGHT

#define SERIAL_USART_TX_PIN GP1

#ifdef POINTING_DEVICE_TRACKPOINT_TRACKBALL
    #define MASTER_LEFT
    #define POINTING_DEVICE_ROTATION_90_RIGHT
#endif
#ifdef POINTING_DEVICE_TRACKBALL_TRACKPOINT
    #define MASTER_RIGHT
    #define POINTING_DEVICE_ROTATION_270
#endif

#ifdef POINTING_DEVICE_TRACKPOINT_CIRQUE35
    #define MASTER_LEFT
#endif
#ifdef POINTING_DEVICE_CIRQUE35_TRACKPOINT
    #define MASTER_RIGHT
#endif

#ifdef POINTING_DEVICE_DRIVER_ps2
    // The default streaming mode is flaky and doesn't always work. This setting doesn't seem to affect performance.
    #define PS2_MOUSE_USE_REMOTE_MODE

    // Serial uses PIO0, change PS2 to PIO1.
    #define PS2_PIO_USE_PIO1

    #if !defined(KEYBOARD_lily58_rev1)
    #define PS2_MOUSE_INVERT_X
    #define PS2_MOUSE_INVERT_Y
    #endif

    #define PS2_DATA_PIN    GP2
    #define PS2_CLOCK_PIN   GP3

    // Start faster when keyboard resets.
    #define PS2_MOUSE_INIT_DELAY 500
#endif

#ifdef POINTING_DEVICE_DRIVER_cirque_pinnacle_i2c
#define CIRQUE_PINNACLE_DIAMETER_MM 35
// Tap for left click.
#define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#endif
