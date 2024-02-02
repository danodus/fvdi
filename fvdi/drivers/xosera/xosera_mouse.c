/*
 * uae_mous.c - Mouse cursor functions
 * This is part of the WinUAE RTG driver for fVDI
 *
 * Copyright (C) 2017 Vincent Riviere
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/*#define ENABLE_KDEBUG*/

#include <stdint.h>
#include "xosera.h"
#include "relocate.h"

uint8_t m_temp[128];

/* External data and functions */
extern Driver *me;

extern Access *access;

static void hide_mouse()
{
	xv_prep();
	xreg_setw(POINTER_H, 0x0000);
	xreg_setw(POINTER_V, 0x0000);
}

static void show_mouse(short x, short y)
{
	xv_prep();
	xreg_setw(POINTER_H, x + 154);
	xreg_setw(POINTER_V, 0xF000 | (y * 2));
}

long CDECL
c_mouse_draw(Workstation *UNUSED(wk), long x, long y, Mouse *mouse)
{
	if ((long)mouse > 7) /* Set new mouse cursor shape */
	{
		// cursor should be updated now, but for now I have only a single hardcoded cursor

		return 0;
	}
	else
	{

		switch ((long)mouse)
		{
		case 0: /* Move visible */
		case 4: /* Move visible forced (wk_mouse_forced) */
			show_mouse((short)x, (short)y);
			break;

		case 1: /* Move hidden */
		case 5: /* Move hidden forced (wk_mouse_forced) */
			// show_mouse(vwk, (short)x, (short)y);
			hide_mouse();
			break;

		case 2: /* Hide */
			hide_mouse();
			break;

		case 3: /* Show */
			show_mouse((short)x, (short)y);
			break;
		}

		return 0;
	}

	return 0;
}
