#pragma once

// We default to the right hand being the master.
#undef MASTER_LEFT
#undef EE_HANDS
#define MASTER_RIGHT

#ifdef TRACKBALL_POSITION_LEFT
#define POINTING_DEVICE_ROTATION_270
#endif
#ifdef TRACKBALL_POSITION_RIGHT
#define POINTING_DEVICE_ROTATION_90
#endif
#ifdef TRACKBALL_POSITION_THUMB
#endif

// Common settings to both busywait and interrupt.
#if defined(PS2_DRIVER_BUSYWAIT) || defined(PS2_DRIVER_INTERRUPT)
#define PS2_MOUSE_INVERT_X
#define PS2_MOUSE_INVERT_Y

#define PS2_CLOCK_PIN   D3
#define PS2_DATA_PIN    B4
#endif

#ifdef PS2_DRIVER_BUSYWAIT
#define PS2_MOUSE_USE_REMOTE_MODE
#endif

#ifdef PS2_DRIVER_INTERRUPT
#define PS2_INT_INIT()  do {    \
    EICRA |= ((1<<ISC31) |      \
              (0<<ISC30));      \
} while (0)
#define PS2_INT_ON()  do {      \
    EIMSK |= (1<<INT3);         \
} while (0)
#define PS2_INT_OFF() do {      \
    EIMSK &= ~(1<<INT3);        \
} while (0)
#define PS2_INT_VECT   INT3_vect
#endif
