#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class hit_record {
    public:
        point3 p;
        vec3 normal;
        double t;
        bool front_face;

    void set_face_normal(const ray& r, const vec3& outward_normal) {
        // Sets the hit record normal vector
        // Choosing to have normals always point outward from the surface/point against the incident ray
        // Determined by whether we want to determine the side of the surface at the time of geometry intersection
        // or time of coloring
        front_face = dot(r.direction, outward_normal) < 0;
        normal = front_face ? outward_normal : vec3(0,0,0) - outward_normal;
    }
};

class hittable {
    public:
        virtual ~hittable() = default;

        virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif