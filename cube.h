#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"
#include <cmath>

class cube : public hittable {
    public:
        point3 center;
        double length_of_side;

        cube(point3 _center, double _length_of_side) : center(_center), length_of_side(_length_of_side) {}
        
        bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
            // for each face of the cube {
            //     Compute the intersection point between the ray and the face.
            //     Check if the intersection point is within the bounds of the face.
            //     Check if the intersection point is within the valid range [t_min, t_max].
            //     If the intersection is valid and the closest so far, update hit information.
            // }

            
            return true;
        }   
};

#endif