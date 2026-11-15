#include "ppm.h"
#include <stdlib.h>
#include <stdio.h>

struct PPM_Image 
create_image(size_t width, size_t height) {
    struct PPM_Image image = {
        .width = width, .height = height,
        .data = malloc(sizeof(struct Color) * width * height)
    };
    if (!image.data) {
        fprintf(stderr, "! memory allocation of size %zu failed\n", sizeof(struct Color) * width * height);
        exit(EXIT_FAILURE);
    }
    return image;
}

void write_image(struct PPM_Image image, const char *filename, bool binary_format) {
    const char *mode = binary_format ? "wb" : "wt";
    FILE *out = fopen(filename, mode);
    const char *format = binary_format ? "P6" : "P3";
    fprintf(out, "%s\n%zu %zu\n255\n", format, image.width, image.height);
    
    if (!binary_format) 
        for (size_t v = 0; v < image.height; ++v) 
            for (size_t u = 0; u < image.width; ++u) {
                auto color = getPixel(image, u,v);
                fprintf(out, "%u %u %u\n", color.r, color.g, color.b);
            }
    else 
        fwrite(image.data, sizeof(image.data[0]), image.width * image.height, out);    
}