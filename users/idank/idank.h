#pragma once

#include QMK_KEYBOARD_H

// We default to the right hand being the master.
#undef MASTER_LEFT
#undef EE_HANDS
#define MASTER_RIGHT

// Index finger trackball needs to be rotated 90 degrees.
#ifndef TRACKBALL_THUMB
#define POINTING_DEVICE_ROTATION_90
#endif
