
#include "utilities.h"
#include "sphere.h"
#include "hittable_list.h"
#include "camera.h"

int main() {
    // Creating the world
    hittable_list world;
    sphere* s = new sphere(point3(0, 0, -1), 0.5);
    sphere* w = new sphere(point3(0,-100.5,-1), 100);
    std::shared_ptr<sphere> shared_ptr_s(s);
    std::shared_ptr<sphere> shared_ptr_w(w);
    world.add(shared_ptr_s);
    world.add(shared_ptr_w);

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;

    cam.render(world);
    return 0;
}
