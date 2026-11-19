#include "ppm.h"
#include "color.h"

int main() {
    union Color colors[] = {
        RED, GREEN, BLUE, 
        YELLOW, WHITE, BLACK
    };
    const size_t width = 3, height = 2;
    const struct PPM_Image image = create_image(width, height);

    for (size_t v = 0; v < height; ++v)
        for (size_t u = 0; u < width; ++u) 
            setPixel(image, u, v, colors[v*width+u]);
            
    write_image(image, "test-ascii.ppm", false);
    write_image(image, "test-binary.ppm", true);
}