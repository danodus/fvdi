/* 
 * 16 bit pixel set/get routines, by Johan Klockars.
 *
 * This file is an example of how to write an
 * fVDI device driver routine in C.
 *
 * You are encouraged to use this file as a starting point
 * for other accelerated features, or even for supporting
 * other graphics modes. This file is therefore put in the
 * public domain. It's not copyrighted or under any sort
 * of license.
 */

#include "xosera.h"

/* destination MFDB (odd address marks table operation)
 * x or table address
 * y or table length (high) and type (0 - coordinates)
 */
long CDECL
c_write_pixel(Virtual *vwk, MFDB *dst, long x, long y, long colour)
{
	if ((long)vwk & 1)
		return 0;

    // If off screen, offset the Y by 240.
    uint16_t offset = IS_SCREEN(vwk->real_address, dst) ? 0 : 240;
    xv_prep();
    xm_setw(PIXEL_X, x);
    xm_setw(PIXEL_Y, y + offset);
    xm_setw(DATA, expanded_color[colour & 0xF]);
	return 1;
}

long CDECL
c_read_pixel(Virtual *vwk, MFDB *src, long x, long y)
{
    // If off screen, offset the Y by 240.
    uint16_t offset = IS_SCREEN(vwk->real_address, src) ? 0 : 240;
    xv_prep();
    xm_setw(PIXEL_X, x);
    xm_setw(PIXEL_Y, y + offset);
    // Xosera will return the 4 pixel word from X & 3.
    uint16_t word = xm_getw(DATA);
    uint16_t shift = (3 - (x & 3)) << 2;
    return (word >> shift) & 0xF;
}
