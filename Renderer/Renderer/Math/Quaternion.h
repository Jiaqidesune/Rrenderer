#pragma once
#include "vector3D.h"

namespace kawaii
{
	class Matrix4x4;

	class Quaternion
	{
	public:
		Quaternion();
		Quaternion(float x, float y, float z, float w);
		Quaternion(float yaw, float pitch, float roll);
		~Quaternion() = default;

		void setEulerAngle(float yaw, float pitch, float roll);
		void setRotationAxis(Vector3D axis, double angle);
		void set(float _x, float _y, float _z, float _w);

		Matrix4x4 toMatrix() const;

		Vector3D eulerAngle() const;

		void operator*(float s);
		void operator+(const Quaternion& q);
		void operator-(const Quaternion& q);

		friend Quaternion operator * (const Quaternion& lhs, const Quaternion& rhs);
		friend Vector3D operator *(const Quaternion& rotation, const Vector3D& point);
	public:
		const static Quaternion identity;
		double x, y, z, w;
	};
}