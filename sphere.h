#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"
#include <cmath>

class sphere : public hittable {
    public:
        point3 center;
        double radius;

        sphere(point3 _center, double _radius) : center(_center), radius(_radius) {}

        // To calculate whether or not we hit a sphere, we take the roots of 
        // x^2 + y^2 + z^2 = r^2
        // and we determine if it's > or < than 0
        bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
            vec3 oc = r.origin - center;
            float a = dot(r.direction, r.direction);
            float b = 2.0 * dot(r.direction, oc);
            float c = dot(oc, oc) - radius*radius;
            float discriminant = b*b - 4*a*c; // b squared - 4ac

            if (discriminant < 0) {
                return false; // outside the sphere 
            } 

            float root = (-b - sqrt(discriminant) ) / (2.0*a); // returning t
            if (root <= ray_tmin || ray_tmax <= root) {
                root = (-b + sqrt(discriminant) ) / (2.0*a);
                if (root <= ray_tmin || ray_tmax <= root)
                    return false;
            }
        
            rec.t = root;
            rec.p = r.at(rec.t);
            rec.normal = (rec.p - center) / radius;

            return true;
        }   
};

#endif