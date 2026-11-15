#ifndef COLOR_H
#define COLOR_H

struct Color {
    unsigned char r,g,b;
};
static const struct Color 
    WHITE = {.r = 255, .g = 255, .b = 255},
    BLACK = {},
    RED = {.r = 255},
    GREEN = {.g = 255},
    BLUE = {.b = 255},
    YELLOW = {.r = 255, .g = 255};

#endif