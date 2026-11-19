#include "geometry.h"
#include "settings.h"
#include <stddef.h>
#include <tgmath.h>

// TODO: generalise it with `decimal_t matrix[static 4][4]` parameter
// TODO: not tested for non-zero camera position (x,y coord)
union Pos3 
transform_img_to_screen_coord(const struct Settings *settings, size_t u, size_t v){
    union Pos3 res = {
        .x = settings->camera_position.x + u - settings->width/(decimal_t)2,
        .y = settings->camera_position.y - v + settings->height/(decimal_t)2,
        .z = settings->camera_position.z + settings->focal_length
    };
    return res;    
}

bool is_major_axis(const struct Settings *settings, union Pos3 pos) {
    // any
    for (size_t i = 0; i < 3; ++i)
        if (fabs(pos.val[i]) < settings->axis_width)
            return true;
    return false;
}

bool is_minor_axis(const struct Settings *settings, union Pos3 pos) {
    // scale pos to around zero axes
    for (size_t i = 0; i < 3; ++i) 
        pos.val[i] = remainder(pos.val[i], settings->unit);
    return is_major_axis(settings, pos);
}