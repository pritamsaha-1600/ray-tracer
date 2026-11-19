#include "geometry.h"
#include "settings.h"
#include "utilities.h"
#include <stdio.h>

int main() {
    const struct Settings settings = {
        .filename = "test-binary.ppm",
        .width = 200, .height = 100,
        // .width = 848, .height = 480, 
        // .width = 1920, .height = 1080,
        .binary_format = true,
        .background_color = WHITE, 
        .axis_width = 0.2, .unit = 50,
        .camera_position = {{0,0,1}},
        .focal_length = 0.5
    };

    const size_t image_positions[][2] = {
        {0,0}, {0, settings.height/2}, {0, settings.height},
        {settings.width/2, 0}, {settings.width/2, settings.height/2}, {settings.width/2, settings.height},
        {settings.width, 0}, {settings.width, settings.height/2}, {settings.width, settings.height}
    };
    for (size_t i = 0; i < len(image_positions); ++i) {
        size_t u = image_positions[i][0], v = image_positions[i][1];
        union Pos3 pixel_pos = transform_img_to_screen_coord(&settings, u, v); 
        printf("(%zu, %zu) -> \t (%f, %f, %f)\n", 
            u, v, pixel_pos.val[0], pixel_pos.val[1], pixel_pos.val[2]);
    }
}