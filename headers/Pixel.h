#ifndef PIXEL_H
#define PIXEL_H

#include <cstdint>
#include "Types.h"

struct Pixel {
    u8 red;
    u8 green;
    u8 blue;

    Pixel(u8 r, u8 g, u8 b) : red(r), green(g), blue(b) {}
    Pixel() : red(0), green(0), blue(0) {}
};

#endif
