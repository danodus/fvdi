/* 
 * A 16 bit graphics line routine, by Johan Klockars.
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

extern void CDECL c_get_colours(Virtual *vwk, long colour, short *foreground, short *background);

extern long CDECL clip_line(Virtual *vwk, long *x1, long *y1, long *x2, long *y2);


long CDECL c_line_draw(Virtual *vwk, long x1, long y1, long x2, long y2,
                       long pattern, long colour, long mode)
{
	return 0;
}
