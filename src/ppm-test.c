#include "ppm.h"

int main() {
    struct Color colors[] = {
        RED, GREEN, BLUE, 
        YELLOW, WHITE, BLACK
    };
    const size_t width = 3, height = 2;
    const struct PPM_Image image = create_image(width, height);

    for (size_t i = 0; i < height; ++i) 
        for (size_t j = 0; j < width; ++j)
            setPixel(image, i, j, colors[i*width+j]);
            
    write_image(image, "test-ascii.ppm", false);
    write_image(image, "test-binary.ppm", true);
}