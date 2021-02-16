#include "MathUtil.h"

namespace kawaii
{
    class Vector4D;

    class Vector3D
    {
    public:

        // constructors
        Vector3D() :x(0.0f), y(0.0f), z(0.0f) {}
        Vector3D(float newX, float newY, float newZ) :x(newX), y(newY), z(newZ) {}
        Vector3D(const float* rhs) :x(*rhs), y(*(rhs + 1)), z(*(rhs + 2)) {}
        Vector3D(const Vector3D& rhs) :x(rhs.x), y(rhs.y), z(rhs.z) {}
        Vector3D(const Vector4D& rhs);
        ~Vector3D() = default;

        // Getter
        float getX() const { return x; }
        float getY() const { return y; }
        float getZ() const { return z; }

        // Setter
        void set(float newX, float newY, float newZ) { x = newX; y = newY; z = newZ; }
        void setX(float newX) { x = newX; }
        void setY(float newY) { y = newY; }
        void setZ(float newZ) { z = newZ; }

        // normalization
        void normalize();
        Vector3D getNormalized() const;

        // length caculation
        float getLength() const { return static_cast<float>(sqrt(x * x + y * y + z * z)); }
        float getSquaredLength() const { return x * x + y * y + z * z; }

        // product
        float dotProduct(const Vector3D& rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z; }
        Vector3D crossProduct(const Vector3D& rhs) const
        {
            return Vector3D(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
        }

        // linear interpolation
        Vector3D lerp(const Vector3D& v2, float factor) const { return (*this) * (1.0f - factor) + v2 * factor; }

        // overloaded operators
        Vector3D operator+(const Vector3D& rhs) const { return Vector3D(x + rhs.x, y + rhs.y, z + rhs.z); }
        Vector3D operator-(const Vector3D& rhs) const { return Vector3D(x - rhs.x, y - rhs.y, z - rhs.z); }
        Vector3D operator*(const float rhs) const { return Vector3D(x * rhs, y * rhs, z * rhs); }
        Vector3D operator/(const float rhs) const { return (Equal(rhs, 0.0f)) ? Vector3D(0.0f, 0.0f, 0.0f) : Vector3D(x / rhs, y / rhs, z / rhs); }

        bool operator==(const Vector3D& rhs) const { return (Equal(x, rhs.x) && Equal(y, rhs.y) && Equal(z, rhs.z)); }
        bool operator!=(const Vector3D& rhs) const { return !((*this) == rhs); }

        void operator+=(const Vector3D& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; }
        void operator-=(const Vector3D& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; }
        void operator*=(const float rhs) { x *= rhs; y *= rhs; z *= rhs; }
        void operator/=(const float rhs) { if (!Equal(rhs, 0.0f)) { x /= rhs; y /= rhs; z /= rhs; } }

        Vector3D operator-() const { return Vector3D(-x, -y, -z); }
        Vector3D operator+() const { return *this; }

    public:
        float x, y, z;
    };
    std::ostream& operator<<(std::ostream& out, const Vector3D& v);
}
