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

#include "xosera.h"

static void xosera_simple_fill_no_blitter(long x0, long y0, long w, long h, uint16_t exp_color, short *pattern)
{
    xv_prep();
    uint16_t width_in_words = w >> 2;
    uint16_t pattern_index = y0 & 0xF;
    xm_setw(PIXEL_X, x0);
    for (long line = y0; line <= y0 + h; line++) {
        // Set the VRAM address for the start of this line
        xm_setw(PIXEL_Y, line);
        uint16_t pattern_word = pattern[pattern_index++];
        if (pattern_index == 16) pattern_index = 0;
        if (pattern_word == 0xFFFF) { /* Handle common fill case. */
            xm_setbl(SYS_CTRL, 0xF);
            for (long word = 0; word < width_in_words; word++) {
                xm_setw(DATA, exp_color);
            }
        } else { /* Slower pattern case. */
            for (long word = 0; word < width_in_words; word++) {
                /* Determine the mask for this word worth of four pixels */
                uint16_t pattern_shift = (3 - (word & 3)) << 2;
                uint16_t word_mask = (pattern_word >> pattern_shift) & 0xF;
                xm_setbl(SYS_CTRL, word_mask);
                xm_setw(DATA, exp_color);
            }
        }
    }
}

long CDECL c_fill_area(Virtual *UNUSED(vwk), long x0, long y0, long w, long h,
                       short *pattern, long colour, long UNUSED(mode), long UNUSED(interior_style))
{
    // If the width AND starting x0 are both an even multiple of four pixels (one word), we can handle that.
    // Otherwise, tell fVDI to use its fallback.
    int width_ok = (w  & 3) == 0;
    int x0_ok    = (x0 & 3) == 0;

    if (width_ok && x0_ok) {
        xosera_simple_fill_no_blitter(x0, y0, w, h, expanded_color[colour], pattern);
        return 1;
    }
    return 0;
}
