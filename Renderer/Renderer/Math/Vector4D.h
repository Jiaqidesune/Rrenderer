#pragma once

#include "MathUtil.h"

namespace kawaii
{
    class Vector4D
    {
    public:

        // constructors
        Vector4D() :x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
        Vector4D(float newX, float newY, float newZ, float newW) :x(newX), y(newY), z(newZ), w(newW) {}
        Vector4D(const float* rhs) :x(*rhs), y(*(rhs + 1)), z(*(rhs + 2)), w(*(rhs + 3)) {}
        Vector4D(const Vector4D& rhs) :x(rhs.x), y(rhs.y), z(rhs.z), w(rhs.w) {}
        Vector4D(const Vector3D& rhs) : x(rhs.x), y(rhs.y), z(rhs.z), w(1.0f) {}
        ~Vector4D() = default;

        // Getter
        float getX() const { return x; }
        float getY() const { return y; }
        float getZ() const { return z; }
        float getW() const { return w; }

        // Setter
        void set(float newX, float newY, float newZ, float newW) { x = newX; y = newY; z = newZ; w = newW; }
        void setX(float newX) { x = newX; }
        void setY(float newY) { y = newY; }
        void setZ(float newZ) { z = newZ; }
        void setW(float newW) { w = newW; }

        // product
        float dotProduct(const Vector4D& rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w; }

        // linear interpolation
        Vector4D lerp(const Vector4D& v2, float factor) const { return (*this) * (1.0f - factor) + v2 * factor; }

        // overloaded operators
        Vector4D operator+(const Vector4D& rhs) const { return Vector4D(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w); }
        Vector4D operator-(const Vector4D& rhs) const { return Vector4D(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w); }
        Vector4D operator*(const float rhs) const { return Vector4D(x * rhs, y * rhs, z * rhs, w * rhs); }
        Vector4D operator/(const float rhs) const
        {
            return (Equal(rhs, 0.0f)) ? Vector4D(0.0f, 0.0f, 0.0f, 0.0f) : Vector4D(x / rhs, y / rhs, z / rhs, w / rhs);
        }

        bool operator==(const Vector4D& rhs) const { return (Equal(x, rhs.x) && Equal(y, rhs.y) && Equal(z, rhs.z) && Equal(w, rhs.w)); }
        bool operator!=(const Vector4D& rhs) const { return !((*this) == rhs); }

        void operator+=(const Vector4D& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; w += rhs.w; }
        void operator-=(const Vector4D& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; w -= rhs.w; }
        void operator*=(const float rhs) { x *= rhs; y *= rhs; z *= rhs; w *= rhs; }
        void operator/=(const float rhs) { if (!Equal(rhs, 0.0f)) { x /= rhs; y /= rhs; z /= rhs; w /= rhs; } }

        Vector4D operator-() const { return Vector4D(-x, -y, -z, -w); }
        Vector4D operator+() const { return *this; }

    public:
        float x, y, z, w;
    };
}