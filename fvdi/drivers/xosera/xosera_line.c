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

#include "xosera.h"

long CDECL c_line_draw(Virtual *UNUSED(vwk), long UNUSED(x1), long UNUSED(y1), long UNUSED(x2), long UNUSED(y2),
                       long UNUSED(pattern), long UNUSED(colour), long UNUSED(mode))
{
    return 0;
}
