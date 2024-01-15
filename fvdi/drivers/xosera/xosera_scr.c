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

#define BOTH	/* Write in both FastRAM and on screen */

#include "fvdi.h"
#include "relocate.h"
#include "xosera.h"
#include <stdint.h>
#include "utility.h"

extern Access *access;

/* destination MFDB (odd address marks table operation)
 * x or table address
 * y or table length (high) and type (0 - coordinates)
 */
long CDECL
c_write_pixel(Virtual *vwk, MFDB *dst, long x, long y, long colour)
{
	Workstation *wk;
	long offset;
        uint16_t col;
	
	if ((long)vwk & 1)
		return 0;

	// TODO

	return 1;
}


long CDECL
c_read_pixel(Virtual *vwk, MFDB *src, long x, long y)
{
	Workstation *wk;
	long offset;
	unsigned long colour;
	// TODO
	colour = 0;
	return colour;
}
