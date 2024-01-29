/*
 * Copyright (C) 2023 - Tillitis AB
 * SPDX-License-Identifier: GPL-2.0-only
 */

#ifndef TKEY_TOUCH_H
#define TKEY_TOUCH_H

#include <stdint.h>
#include <tkey/tk1_mem.h>

// touchwait() waits for a touch event while blinking color on the
// status LED. timeout_s is the timeout in seconds.
//
// If a touch event occurs it returns true. If the timeout expires it
// returns false.
bool touch_wait(int color, int timeout_s);
#endif
