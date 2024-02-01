/*
 * A 16 bit graphics blit routine, by Johan Klockars.
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
#include <stdint.h>
#include "xosera.h"

long CDECL
c_blit_area(Virtual *UNUSED(vwk), MFDB *UNUSED(src), long UNUSED(src_x), long UNUSED(src_y),
            MFDB *UNUSED(dst), long UNUSED(dst_x), long UNUSED(dst_y),
            long UNUSED(w), long UNUSED(h), long UNUSED(operation))
{
    // TODO
    return 0;
}

