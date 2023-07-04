// Copyright (C) - Tillitis AB
// SPDX-License-Identifier: GPL-2.0-only

#include <lib.h>
#include <qemu_debug.h>
#include <tk1_mem.h>
#include <types.h>

#ifndef NODEBUG
static volatile uint8_t *debugtx = (volatile uint8_t *)TK1_MMIO_QEMU_DEBUG;

int qemu_putchar(uint8_t ch)
{
	*debugtx = ch;

	return ch;
}

void qemu_lf()
{
	qemu_putchar('\n');
}

static char hexnibble(uint8_t ch)
{
	switch (ch) {
	case 0x0:
		return '0';
	case 0x1:
		return '1';
	case 0x2:
		return '2';
	case 0x3:
		return '3';
	case 0x4:
		return '4';
	case 0x5:
		return '5';
	case 0x6:
		return '6';
	case 0x7:
		return '7';
	case 0x8:
		return '8';
	case 0x9:
		return '9';
	case 0xa:
		return 'a';
	case 0xb:
		return 'b';
	case 0xc:
		return 'c';
	case 0xd:
		return 'd';
	case 0xe:
		return 'e';
	case 0xf:
		return 'f';
	}

	return '0';
}

void qemu_puthex(uint8_t ch)
{
	qemu_putchar(hexnibble(ch >> 4 & 0x0f));
	qemu_putchar(hexnibble(ch & 0x0f));
}

void qemu_putinthex(const uint32_t n)
{
	uint8_t buf[4];

	memcpy(buf, &n, 4);
	qemu_puts("0x");
	for (int i = 3; i > -1; i--) {
		qemu_puthex(buf[i]);
	}
}

void qemu_puts(const char *s)
{
	while (*s)
		qemu_putchar(*s++);
}

void qemu_hexdump(uint8_t *buf, int len)
{
	uint8_t *byte_buf = (uint8_t *)buf;

	for (int i = 0; i < len; i++) {
		qemu_puthex(byte_buf[i]);
		if (i % 2 == 1) {
			(void)qemu_putchar(' ');
		}

		if (i != 1 && i % 16 == 1) {
			qemu_lf();
		}
	}

	qemu_lf();
}
#endif
