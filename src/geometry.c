#include "geometry.h"
#include "settings.h"
#include <tgmath.h>

// TODO: generalise it with `decimal_t matrix[static 4][4]` parameter
// TODO: not tested for non-zero camera position (x,y coord)
struct Pos3 
transform_img_to_screen_coord(const struct Settings *settings, size_t u, size_t v){
    struct Pos3 res = {
        .x = settings->camera_position.x + u - settings->width/(decimal_t)2,
        .y = settings->camera_position.y - v + settings->height/(decimal_t)2,
        .z = settings->camera_position.z + settings->focal_length
    };
    return res;    
}

bool is_major_axis(const struct Settings *settings, struct Pos3 pos) {
    if (fabs(pos.x) < settings->axis_width || 
        fabs(pos.y) < settings->axis_width || 
        fabs(pos.z) < settings->axis_width)
        return true;
    return false;
}

// only if integral and multiple of 50
bool is_minor_axis(const struct Settings *settings, struct Pos3 pos) {
    if ((fabs(pos.x - trunc(pos.x)) < settings->axis_width || 
        fabs(pos.y - trunc(pos.y)) < settings->axis_width || 
        fabs(pos.z - trunc(pos.z)) < settings->axis_width) && 
        (fmod(trunc(pos.x), 50) == 0 || fmod(trunc(pos.y), 50) == 0 || fmod(trunc(pos.z), 50) == 0))
        return true;
    return false;
}

// bool is_minor_axis(const struct Settings *settings, struct Pos3 pos) {
//     auto num = 5;
//     if (fabs(pos.x - settings->axis_width) == num || 
//         fabs(pos.y - settings->axis_width) == num || 
//         fabs(pos.z - settings->axis_width) == num)
//         return true;
//     return false;
// }

// bool isint(decimal_t num) {
//     return isfinite(num) && (trunc(num) == num) && (size_t)num % 500;
// }