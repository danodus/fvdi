#include "xosera.h"

void xosera_palette_register_write(uint8_t palette, uint16_t data)
{
    xv_prep();
    xm_setw(WR_XADDR, XR_COLOR_ADDR | palette);
    xm_setw(XDATA, data);
}

// A lookup table to take a color in 4 bits and expand it to sixteen, e.g A => 0xAAAA
uint16_t expanded_color[16] = {
        0x0000, 0x1111, 0x2222, 0x3333, 0x4444, 0x5555, 0x6666, 0x7777,
        0x8888, 0x9999, 0xAAAA, 0xBBBB, 0xCCCC, 0xDDDD, 0xEEEE, 0xFFFF
};
