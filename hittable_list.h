#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"
#include "utilities.h"

class hittable_list : public hittable {
    public: 
        std::vector<shared_ptr<hittable> > objects; // creating a list of pointers to objects
        hittable_list() {}

        void clear() { objects.clear(); }

        void add(shared_ptr<hittable> object) {
            objects.push_back(object);
        }

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            hit_record temp_rec;
            bool hit_anything = false; // default to hit nothing
            double closest_so_far = ray_t.max;

            for (const auto& object : objects) { // for each object in the list of objects
                if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
                    hit_anything = true;
                    closest_so_far = temp_rec.t;
                    rec = temp_rec;
                }
            }

            return hit_anything;
        }
};

#endif