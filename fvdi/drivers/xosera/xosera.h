#ifndef INCLUDE_XOSERA_H
#define INCLUDE_XOSERA_H

#define ROSCO_M68K  // needed for rosco_m68k Xosera HW defines

#include "util.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <fvdi.h>

#include "xosera_m68k_api.h"

extern short colours[];

void xosera_palette_register_write(uint8_t palette, uint16_t data);
void xosera_pset(uint16_t dx, uint16_t dy, uint8_t color);
uint8_t xosera_point(uint16_t sx, uint16_t sy);

/* Function prototypes. */
long CDECL c_get_colour(Virtual *vwk, long colour);
void CDECL c_get_colours(Virtual *vwk, long colour, unsigned long *foreground, unsigned long *background);
void CDECL c_set_colours(Virtual *vwk, long start, long entries, unsigned short *requested, Colour palette[]);
long CDECL c_write_pixel(Virtual *vwk, MFDB *mfdb, long x, long y, long colour);
long CDECL c_read_pixel(Virtual *vwk, MFDB *mfdb, long x, long y);
long CDECL c_line_draw(Virtual * vwk, long x1, long y1, long x2, long y2, long pattern, long colour, long mode);
//long CDECL (*expand_area_r)(Virtual *vwk, MFDB *src, long src_x, long src_y, MFDB *dst, long dst_x, long dst_y, long w, long h, long operation, long colour);
long CDECL c_fill_area(Virtual *vwk, long x, long y, long w, long h, short *pattern, long colour, long mode, long interior_style);
//long CDECL (*fill_poly_r)(Virtual *vwk, short points[], long n, short index[], long moves, short *pattern, long colour, long mode, long interior_style);
long CDECL c_blit_area(Virtual *vwk, MFDB *src, long src_x, long src_y, MFDB *dst, long dst_x, long dst_y, long w, long h, long operation);
//long CDECL (*text_area_r)(Virtual *vwk, short *text, long length, long dst_x, long dst_y, short *offsets);
long CDECL c_mouse_draw(Workstation *wk, long x, long y, Mouse *mouse);


#ifdef __GNUC__
#  define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
#else
#  define UNUSED(x) UNUSED_ ## x
#endif

#endif
