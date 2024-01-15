/* 
 * A 16 bit graphics fill routine, by Johan Klockars.
 *
 * $Id: 16b_fill.c,v 1.2 2002-07-10 22:13:39 johan Exp $
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



#include "fvdi.h"
#include "xosera.h"
#include "relocate.h"

extern void CDECL c_get_colour(Virtual *vwk, long colour, short *foreground, short *background);
extern long CDECL fallback_fill(Virtual *vwk, long x, long y, long w, long h, short *pattern, long colour, long mode, long interior_style);
extern Access *access;


long CDECL c_fill_area(Virtual *vwk, long x, long y, long w, long h,
                       short *pattern, long colour, long mode, long interior_style)
{
	return 0;
}
