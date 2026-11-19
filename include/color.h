#ifndef COLOR_H
#define COLOR_H

union Color {
    struct { unsigned char r,g,b; };
    unsigned char val[3];
};
static const union Color 
    WHITE = {.r = 255, .g = 255, .b = 255},
    BLACK = {},
    RED = {.r = 255},
    GREEN = {.g = 255},
    BLUE = {.b = 255},
    YELLOW = {.r = 255, .g = 255};

#endif