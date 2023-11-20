/**
 *        t = -1    t = 0     t = 1     t = 2
 *  <-------|---------|---------|---------|---->
 *                    A         b
 * 
 * We need a ray class and a computation of what color is seen along the ray
 * Ray can be thought as a function P(t) = A + t*b
 * P is a 3D position along a line in 3D
 * A is the ray origin and b is the ray direction
*/
#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    public: 
        vec3 origin;
        vec3 direction;

        ray() {}
        ray(const vec3& _origin, const vec3& _direction) : origin(_origin), direction(_direction) {}

        // Calculate a point along the ray at a given parameter t
        vec3 at(double t) const {
            return origin + direction * t;
        }  
};

#endif