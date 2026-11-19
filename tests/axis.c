#include "color.h"
#include "geometry.h"
#include "ppm.h"
#include "settings.h"
#include <stdio.h>

int main() {
    const struct Settings settings = {
        .filename = "test-binary.ppm",
        // .viewport_width = , .viewport_height = ,
        // .image_width = 848, .image_height = 480, 
        // .image_width = 1920, .image_height = 1080,
        .width = 848, .height = 480, 
        .binary_format = true,
        .background_color = WHITE, 
        .axis_width = 3, .unit = 50,
        .camera_position = {{0,0,1}},
        .focal_length = 0.5
    };
    
    // print stats
    const union Pos3 top_left = transform_img_to_screen_coord(&settings, 0, 0),
        bottom_right = transform_img_to_screen_coord(&settings, settings.width, settings.height);
    printf("top-left: (%zu,%zu) -> (%g,%g,%g)\n"
           "bottom-right: (%zu,%zu) -> (%g,%g,%g)\n", 
           (size_t)0, (size_t)0, top_left.val[0], top_left.val[1], top_left.val[2],
           settings.width, settings.height, bottom_right.val[0], bottom_right.val[1], bottom_right.val[2]);

    const struct PPM_Image image = create_image(settings.width, settings.height);

    // v - top down, u - left right
    for (size_t u = 0; u < settings.width; ++u) 
        for (size_t v = 0; v < settings.height; ++v) {
            union Pos3 pixel_pos = transform_img_to_screen_coord(&settings, u, v);
            
            union Color color = settings.background_color;

            if (is_major_axis(&settings, pixel_pos))
                color = BLACK;
            else if (is_minor_axis(&settings, pixel_pos))
                color = BLUE;
            setPixel(image, u, v, color);
        }
            
    write_image(image, settings.filename, settings.binary_format);
}