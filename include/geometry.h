#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <stddef.h>
#include <tgmath.h>

typedef float decimal_t;
union Pos3 {
    struct { decimal_t x,y,z; };
    decimal_t val[3];
};
inline static union Pos3 scale(union Pos3 v, decimal_t c) {
    for (size_t i = 0; i < 3; ++i)
        v.val[i] *= c;
    return v;
}
inline static union Pos3 add(union Pos3 v1, union Pos3 v2) {
    for (size_t i = 0; i < 3; ++i)
        v1.val[i] += v2.val[i];
    return v1;
}
inline static union Pos3 sub(union Pos3 v1, union Pos3 v2) {
    return add(v1, scale(v2, -1));
}
inline static decimal_t dot(union Pos3 v1, union Pos3 v2) {
    decimal_t result = 0;
    for (size_t i = 0; i < 3; ++i)
        result += v1.val[i] * v2.val[i];
    return result;
}
inline static decimal_t norm_squared(union Pos3 v) {
    return dot(v, v);
}
inline static decimal_t norm(union Pos3 v) {
    return sqrt(norm_squared(v));
}

// late inclusion because settings.h includes geometry.h and vice versa
// break circular dependency by defining the things settings.h requires before 
// including it
#include "settings.h"

union Pos3 
transform_img_to_screen_coord(const struct Settings *settings, size_t u, size_t v);

bool is_major_axis(const struct Settings *settings, union Pos3 pos);
bool is_minor_axis(const struct Settings *settings, union Pos3 pos);

#endif