#ifndef VEC3_H
#define VEC3_H

#include <cmath>

class vec3 {
    public:
        float x, y, z;

        vec3() : x(0.0f), y(0.0f), z(0.0f) {}
        vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

        // Add other vector operations as needed (e.g., addition, subtraction, dot product, cross product)

        // scalar multiplication
        vec3 operator*(const double scalar) const {
            return vec3(x * scalar, y * scalar, z * scalar);
        }

        // scalar division
        vec3 operator/(const double scalar) const {
            return vec3(x / scalar, y / scalar, z / scalar);
        }

        // multiplication
        vec3 operator*(const vec3& other) const {
            return vec3(x * other.x, y * other.y, z * other.z);
        }

        // addition operation
        vec3 operator+(const vec3& other) const {
            return vec3(x + other.x, y + other.y, z + other.z);
        }

        // subtraction operation
        vec3 operator-(const vec3& other) const {
            return vec3(x - other.x, y - other.y, z - other.z);
        }

        float length() const {
            float length_squared = (x*x) + (y*y) + (z*z);
            return sqrt(length_squared);
        }
};

typedef vec3 point3; 

inline vec3 operator*(double scaler, const vec3 &vector) {
    return vector*scaler;
}

inline vec3 unit_vector(vec3 vector) {
    return vector/vector.length();
}

inline double dot(vec3 vector_1, vec3 vector_2) {
    return (vector_1.x * vector_2.x) + (vector_1.y * vector_2.y) + (vector_1.z * vector_2.z);
}

#endif