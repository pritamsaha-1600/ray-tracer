#ifndef UTILITIES_H
#define UTILITIES_H

typedef float double_t;
struct Pos3 {
    double_t x, y, z;
};
inline struct Pos3 scale(struct Pos3 v, double_t t) {
    return (struct Pos3){t * v.x, t * v.y, t * v.z};
}
inline struct Pos3 add(struct Pos3 v1, struct Pos3 v2) {
    return (struct Pos3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}
inline struct Pos3 sub(struct Pos3 v1, struct Pos3 v2) {
    return add(v1, scale(v2, -1));
}

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
        
#define len(arr) sizeof((arr))/sizeof(((arr)[0]))

#endif