#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <stddef.h>

typedef float decimal_t;
struct Pos3 {
    decimal_t x, y, z;
};
inline struct Pos3 scale(struct Pos3 v, decimal_t t) {
    return (struct Pos3){t * v.x, t * v.y, t * v.z};
}
inline struct Pos3 add(struct Pos3 v1, struct Pos3 v2) {
    return (struct Pos3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}
inline struct Pos3 sub(struct Pos3 v1, struct Pos3 v2) {
    return add(v1, scale(v2, -1));
}
inline decimal_t dot(struct Pos3 v1, struct Pos3 v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// late inclusion because settings.h includes geometry.h and vice versa
// break circular dependency by defining the things settings.h requires before 
// including it
#include "settings.h"

// inline bool isint(decimal_t num);
struct Pos3 
transform_img_to_screen_coord(const struct Settings *settings, size_t u, size_t v);

bool is_major_axis(const struct Settings *settings, struct Pos3 pos);
bool is_minor_axis(const struct Settings *settings, struct Pos3 pos);

#endif