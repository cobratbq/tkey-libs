// Copyright (C) 2022 - Tillitis AB
// SPDX-License-Identifier: GPL-2.0-only

#include <lib.h>
#include <tk1_mem.h>
#include <types.h>

void *memset(void *dest, int c, unsigned n)
{
	uint8_t *s = dest;

	for (; n; n--, s++)
		*s = c;

	return dest;
}

__attribute__((used)) void *memcpy(void *dest, const void *src, unsigned n)
{
	uint8_t *src_byte = (uint8_t *)src;
	uint8_t *dest_byte = (uint8_t *)dest;

	for (int i = 0; i < n; i++) {
		dest_byte[i] = src_byte[i];
	}

	return dest;
}

__attribute__((used)) void *wordcpy(void *dest, const void *src, unsigned n)
{
	uint32_t *src_word = (uint32_t *)src;
	uint32_t *dest_word = (uint32_t *)dest;

	for (int i = 0; i < n; i++) {
		dest_word[i] = src_word[i];
	}

	return dest;
}

int blake2s(void *out, unsigned long outlen, const void *key,
	    unsigned long keylen, const void *in, unsigned long inlen,
	    blake2s_ctx *ctx)
{
	int (*fw_blake2s)(void *out, unsigned long outlen, const void *key,
			  unsigned long keylen, const void *in,
			  unsigned long inlen, blake2s_ctx *ctx);

	fw_blake2s =
	    (int (*)(void *, unsigned long, const void *, unsigned long,
		     const void *, unsigned long, blake2s_ctx *)) *
	    (volatile uint32_t *)TK1_MMIO_TK1_BLAKE2S;

	return fw_blake2s(out, outlen, key, keylen, in, inlen, ctx);
}
