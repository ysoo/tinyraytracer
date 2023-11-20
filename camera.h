#ifndef CAMERA_H
#define CAMERA_H

#include "color.h"
#include "hittable_list.h"
#include "vec3.h"
#include <iostream>
#include <fstream>

class camera {
    public: 
        float aspect_ratio = 4.0/3.0;
        int image_width = 400;
        // const int image_height = 256;
        const float focal_length = 1.0;
        float viewport_height = 2.0;

        camera() {
            initialize();
        }

        void render(const hittable_list& world) {
            std::ofstream ofs;
            ofs.open("./out.ppm", std::ios::out | std::ios::binary); // Open in binary mode

            if (!ofs.is_open()) {
                std::cerr << "Error: Could not open the output file." << std::endl;
            }

            ofs << "P6\n" << image_width << " " << image_height << "\n255\n";
            std::cout << image_height << std::endl;
            // loop through each row (height) of the image
            for (int j = 0; j < image_height; ++j) {
                std::clog << "\rScanlines remaining: " << (image_height - j) << " " << std::flush;
                // loop through each column (width) of the image.
                for (int i = 0; i < image_width; ++i) {
                    vec3 pixel_center = pixel_upper_left + (pixel_delta_u * i) + (pixel_delta_v * j);
                    vec3 ray_direction = pixel_center - camera_center;
                    ray r(camera_center, ray_direction);

                    color pixel_color = ray_color(r, world);
                    write_color(ofs, pixel_color);
                }
            }
            std::clog << "\rDone.                                          \n";

            ofs.close();
        }

    private:
        float image_height;
        vec3 pixel_upper_left;
        vec3 pixel_delta_u;
        vec3 pixel_delta_v;
        point3 camera_center;

        int get_image_height() {
            float image_height = static_cast<int>(image_width / aspect_ratio);
            return (image_height < 1) ? 1 : image_height;
        }

        void initialize() {
            image_height = get_image_height();
            float viewport_width = viewport_height * (static_cast<double>(image_width/image_height));
            point3 camera_center = point3(0, 0, 0);

            vec3 viewport_u = vec3(viewport_width, 0, 0);
            vec3 viewport_v = vec3(0, -viewport_height, 0);

            // Delta vectors from pixel to pixel
            pixel_delta_u = viewport_u / image_width;
            pixel_delta_v = viewport_v / image_height;

            // Finding the location of the upper left pixel
            vec3 viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
            pixel_upper_left = viewport_upper_left + (pixel_delta_u*0.5) + (pixel_delta_v*0.5);
        }

        // linearly blends white and blue depending on the height of the y coordinate after
        // scaling the ray direction to unit length ( -1 < y < 1)
        // when a = 1 we want blue, when a = 0, we want white 
        // A lerp: 
        // blendedValue = (1 - a) * startValue + a * endValue
        color ray_color(const ray& r, const hittable_list& world) const {
            hit_record rec;
            if(world.hit(r, 0, INFINITY, rec)) {
                return 0.5 * (rec.normal + color(1, 1, 1));
            }
            vec3 unit_direction =  unit_vector(r.direction);
            float a = 0.5*(unit_direction.y + 1.0);
            return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
        }
};  

#endif