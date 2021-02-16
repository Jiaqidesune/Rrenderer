#pragma once

#include "MathUtil.h"

namespace kawaii
{
	class Vector2D
	{
	public:
		Vector2D() :x(0.0f), y(0.0f) {}
		Vector2D(float newX, float newY) :x(newX), y(newY) {}
		Vector2D(const float* rhs) :x(*rhs), y((*rhs) + 1) {}
		Vector2D(const Vector2D& rhs) :x(rhs.x), y(rhs.y) {}
		~Vector2D() = default;

		//Getter
		float getX() const { return x; }
		float getY() const { return y; }
		// Setter
		void set(float newX, float newY) { x = newX; y = newY; }
		void setX(float newX) { x = newX; }
		void setY(float newY) { y = newY; }

		// normalized
		void normalize();
		Vector2D getNormalized() const;

		Vector2D lerp(const Vector2D& v2, const float factor) const 
		{ 
			return (*this) * (1.0f - factor) + v2 * factor; 
		}

		//length
		float getLength() const { return static_cast<float>(sqrt(x * x + y * y)); }
		float getSquaredLength()const { return static_cast<float>(x * x + y * y); }

		Vector2D operator+(const Vector2D& rhs) const { return Vector2D(x + rhs.x, y + rhs.y); }
		Vector2D operator-(const Vector2D& rhs) const { return Vector2D(x - rhs.x, y - rhs.y); }
		Vector2D operator*(const float rhs) const { return Vector2D(x * rhs, y * rhs); }
		Vector2D operator/(const float rhs) const { return (rhs == 0) ? Vector2D(0.0f, 0.0f) : Vector2D(x / rhs, y / rhs); }

		bool operator==(const Vector2D& rhs) const { return Equal(x, rhs.x) && Equal(y, rhs.y); }
		bool operator!=(const Vector2D& rhs) const { return !((*this) == rhs); }

		void operator+=(const Vector2D& rhs) { x += rhs.x;	y += rhs.y; }
		void operator-=(const Vector2D& rhs) { x -= rhs.x;	y -= rhs.y; }
		void operator*=(const float rhs) { x *= rhs; y *= rhs; }
		void operator/=(const float rhs) { if (!Equal(rhs, 0.0)) { x /= rhs; y /= rhs; } }

		Vector2D operator-() const { return Vector2D(-x, -y); }
		Vector2D operator+() const { return *this; }

	public:
		float x, y;
	};
	std::ostream& operator<<(std::ostream& out, const Vector2D& v);
}