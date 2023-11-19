#include <iostream>
#include <fstream>
#include "color.h"
#include "ray.h"

const auto aspect_ratio = 16.0/9.0;
const int image_width = 400;
// const int image_height = 256;
const auto focal_length = 1.0;
auto viewport_height = 2.0;

// linearly blends white and blue depending on the height of the y coordinate after
// scaling the ray direction to unit length ( -1 < y < 1)
// when a = 1 we want blue, when a = 0, we want white 
// A lerp: 
// blendedValue = (1 - a) * startValue + a * endValue
color ray_color(const ray& r) {
    vec3 unit_direction =  unit_vector(r.direction);
    auto a = 0.5*(unit_direction.y + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int get_image_height() {
    int image_height = static_cast<int>(image_width / aspect_ratio);
    return (image_height < 1) ? 1 : image_height;
}

int render() {
    std::ofstream ofs;
    ofs.open("./out.ppm", std::ios::out | std::ios::binary); // Open in binary mode

    if (!ofs.is_open()) {
        std::cerr << "Error: Could not open the output file." << std::endl;
        return 1;
    }

    int image_height = get_image_height();
    auto viewport_width = viewport_height * (static_cast<double>(image_width/image_height));
    auto camera_center = point3(0, 0, 0);

    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // Delta vectors from pixel to pixel
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Finding the location of the upper left pixel
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    auto pixel_upper_left = viewport_upper_left + (pixel_delta_u*0.5) + (pixel_delta_v*0.5);

    ofs << "P6\n" << image_width << " " << image_height << "\n255\n";

    // loop through each row (height) of the image
    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << " " << std::flush;
        // loop through each column (width) of the image.
        for (int i = 0; i < image_width; ++i) {
            // calculate the red, green, blue value based on the pixel location
            // double r = double(i) / (image_width - 1);
            // double g = double(j) / (image_height - 1);
            // double b = 0;

            auto pixel_center = pixel_upper_left + (pixel_delta_u * i) + (pixel_delta_v * j);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(ofs, pixel_color);
        }
    }
    std::clog << "\rDone.                                          \n";

    ofs.close();
    return 0;
}

int main() {
    render();
    return 0;
}
