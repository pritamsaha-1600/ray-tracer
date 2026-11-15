#ifndef PPM_H
#define PPM_H

#include "color.h"
#include <stddef.h>

struct PPM_Image {
    size_t width, height;
    // store colours in row-major order (ie. for each v (for each u))
    struct Color *data; 
};

struct PPM_Image create_image(size_t width, size_t height);
void write_image(struct PPM_Image image, const char *filename, bool binary_format);

static inline 
void setPixel(struct PPM_Image img, size_t u, size_t v, struct Color color) {
    img.data[v*img.width + u] = color;
}
static inline
struct Color getPixel(struct PPM_Image img, size_t u, size_t v) {
    return img.data[v*img.width + u];
}

#endif