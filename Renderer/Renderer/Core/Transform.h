#pragma once

#include "../Math/Quaternion.h"
#include "../Math/Matrix4x4.h"

namespace kawaii
{
	class Transform
	{
	public:
		Transform();
		~Transform() = default;

		static const Vector3D LocalUp;
		static const Vector3D LocalRight;
		static const Vector3D LocalForward;

		void scale(const Vector3D& ds);
		void translate(const Vector3D& dt);
		void rotate(const Vector3D& axis, float angle);
		void setScale(const Vector3D& s);
		void setRotation(const Quaternion& r);
		void setTranslation(const Vector3D& t);

		Vector3D forward() const;
		Vector3D up() const;
		Vector3D right() const;

		Matrix4x4 toMatrix();

		//Getter
		Vector3D translation() const { return m_translation; }
		Quaternion rotation() const { return m_rotation; }
		Vector3D scale() const { return m_scale; }

	private:
		Vector3D m_translation;
		Vector3D m_scale;
		Quaternion m_rotation;
		Matrix4x4 m_world;

		mutable bool m_changed;
	};
}