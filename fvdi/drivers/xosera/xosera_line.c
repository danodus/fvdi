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
#include "driver.h" /* For clip_line() */

long CDECL c_line_draw(Virtual *vwk, long x1, long y1, long x2, long y2,
                       long pattern, long colour, long UNUSED(mode))
{
    return 0;
    
    if ((long)vwk & 1) {
        return -1;                      /* Don't know about anything yet */
    }

    if (!clip_line(vwk, &x1, &y1, &x2, &y2))
        return 1;

    /* Only solid patterns for now. */
    if (pattern != -1) return 0;

    uint8_t result = 0;
    uint16_t exp_color = expanded_color[colour & 0xF];
    if (x1 == x2) { /* vertical line */
        xv_prep();
        xm_setw(PIXEL_X, x1);
        if (y1 > y2) {
            long temp = y1;
            y1 = y2;
            y2 = temp;
        }
        for (long y = y1; y <= y2; y++) {
            xm_setw(PIXEL_Y, y);
            xm_setw(DATA, exp_color);
        }
        result = 1;
    } else if (y1 == y2) { /* horizontal line */
        xv_prep();
        xm_setw(PIXEL_Y, y1);
        if (x1 > x2) {
            long temp = x1;
            x1 = x2;
            x2 = temp;
        }
        for (long x = x1; x <= x2; x++) {
            xm_setw(PIXEL_X, x);
            xm_setw(DATA, exp_color);
        }
        result = 1;
    }
    return result;
}
