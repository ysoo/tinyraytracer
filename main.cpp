// Saving a file
#include <iostream>
#include <fstream>

const int image_width = 256;
const int image_height = 256;

int render() {
    std::ofstream ofs;
    ofs.open("./out.ppm");

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for(int i = 0; i < image_width; i++) {
        for(int j = 0; j < image_height; j++) {
            double r = double(i) / (image_width - 1);
            double g = double(j) / (image_height - 1);
            double b = 0;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);
            
            std::cout << ir << " " << ig << " " << ib << "\n";
            ofs.put(static_cast<char>(ir));
            ofs.put(static_cast<char>(ig));
            ofs.put(static_cast<char>(ib));
        }
    }

    ofs.close();
    return 0;
}

int main() {
    render();
    return 0;
}