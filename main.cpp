#include <iostream>
#include <fstream>
#include "color.h"

const int image_width = 256;
const int image_height = 256;

int render() {
    std::ofstream ofs;
    ofs.open("./out.ppm", std::ios::out | std::ios::binary); // Open in binary mode

    if (!ofs.is_open()) {
        std::cerr << "Error: Could not open the output file." << std::endl;
        return 1;
    }

    ofs << "P6\n" << image_width << " " << image_height << "\n255\n";

    // loop through each row (height) of the image
    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << " " << std::flush;
        // loop through each column (width) of the image.
        for (int i = 0; i < image_width; ++i) {
            // calculate the red, green, blue value based on the pixel location
            double r = double(i) / (image_width - 1);
            double g = double(j) / (image_height - 1);
            double b = 0;

            color pixel_color = color(r, g, b);

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
