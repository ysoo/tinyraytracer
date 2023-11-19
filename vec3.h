class vec3 {
    public:
        float x, y, z;

        vec3() : x(0.0f), y(0.0f), z(0.0f) {}
        vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

        // Add other vector operations as needed (e.g., addition, subtraction, dot product, cross product)

        // scalar multiplication
        vec3 operator*(const double t) const {
            return vec3(x * t, y * t, z * t);
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
};