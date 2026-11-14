#ifndef PPM_H
#define PPM_H

#include "utilities.h"
#include <stddef.h>

struct PPM_Image {
    size_t width, height;
    struct Color *data;
};

struct PPM_Image create_image(size_t width, size_t height);
void write_image(struct PPM_Image image, const char *filename, bool binary_format);

static inline 
void setPixel(struct PPM_Image img, size_t x, size_t y, struct Color color) {
    img.data[x*img.width + y] = color;
}
static inline
struct Color getPixel(struct PPM_Image img, size_t x, size_t y) {
    return img.data[x*img.width + y];
}

#endif