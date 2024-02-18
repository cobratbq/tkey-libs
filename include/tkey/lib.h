// Copyright (C) 2022 - Tillitis AB
// SPDX-License-Identifier: GPL-2.0-only

#ifndef TKEY_LIB_H
#define TKEY_LIB_H

#include <stddef.h>
#include <stdint.h>

void *memset(void *dest, const int c, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void memcpy_s(void *dest, const size_t destsize, const void *src, size_t n);
void *wordcpy(void *dest, const void *src, size_t n);
void wordcpy_s(void *dest, const size_t destsize, const void *src, size_t n);
int memeq(void *dest, const void *src, size_t n);
void secure_wipe(void *v, size_t n);
#endif
