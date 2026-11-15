#ifndef SETTINGS_H
#define SETTINGS_H

#include "color.h"
#include "geometry.h"
#include <stddef.h>

struct Settings {
    // image settings
    const char *filename;
    size_t width, height;
    bool binary_format;
    struct Color background_color;
    decimal_t axis_width;

    // camera settings
    struct Pos3 camera_position;
    decimal_t focal_length;  // distance of screen from camera lens position
};

#endif