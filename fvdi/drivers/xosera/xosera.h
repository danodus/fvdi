#ifndef INCLUDE_XOSERA_H
#define INCLUDE_XOSERA_H

#define ROSCO_M68K          // needed for rosco_m68k Xosera HW defines

#include "util.h"
// #include <machine.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "xosera_m68k_api.h"

short colours[];

void xosera_pset(uint16_t dx, uint16_t dy, uint8_t color);
uint8_t xosera_point(uint16_t sx, uint16_t sy);

#endif
