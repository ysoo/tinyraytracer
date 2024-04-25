#ifndef UTILITIES_H
#define UTILITIES_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

// C++ Std Usings
using std::make_shared;
using std::shared_ptr;
using std::sqrt;

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.14159265;

// Utility Functions
float degrees_to_radians(float degrees) {
    return degrees * (pi / 180);
}

// Common Headers
#include "color.h"
#include "ray.h"
#include "vec3.h"
#include "interval.h"

#endif