#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

typedef vec3 color; // creating an alias for vec3

bool print_flag = false;

void write_color(std::ostream &ofs, color pixel_color) {
    // Convert the color components to integer values in the range [0, 255].
    // We use 255.999 to ensure that when we cast the value to the integer, we round down
    int ir = static_cast<int>(255.999 * pixel_color.x);
    int ig = static_cast<int>(255.999 * pixel_color.y);
    int ib = static_cast<int>(255.999 * pixel_color.z);

    // Write the RGB color values to the file as individual bytes (characters).
    ofs.put(static_cast<char>(ir));
    ofs.put(static_cast<char>(ig));
    ofs.put(static_cast<char>(ib));

    if (print_flag) {
        std::cout << ir << " " << ig << " " << ib << std::endl;
    }
}

#endif
