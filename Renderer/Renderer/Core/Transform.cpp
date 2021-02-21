#include "Transform.h"

namespace kawaii
{
	const Vector3D Transform::LocalUp(0.0f, 1.0f, 0.0f);
	const Vector3D Transform::LocalForward(0.0f, 0.0f, 1.0f);
	const Vector3D Transform::LocalRight(1.0f, 0.0f, 0.0f);

	Transform::Transform()
		:m_changed(true), m_scale(1.0f,1.0f,1.0f)
	{
		m_world.loadIdentity();
	}

	Matrix4x4 Transform::toMatrix()
	{
		if (m_changed)
		{
			m_changed = false;
			m_world = m_rotation.toMatrix();
			Matrix4x4 scale, translation;
			scale.setScale(m_scale);
			translation.setTranslation(m_translation);
			m_world = translation * scale * m_world;
		}
		return m_world;
	}

	void Transform::scale(const Vector3D& ds)
	{
		m_changed = true;
		m_scale.x *= ds.x;
		m_scale.y *= ds.y;
		m_scale.z *= ds.z;
	}

	void Transform::translate(const Vector3D& dt)
	{
		m_changed = true;
		m_translation += dt;
	}

	void Transform::rotate(const Vector3D& axis, float angle)
	{
		m_changed = true;
		Quaternion newRot;
		newRot.setRotationAxis(axis, angle);
		m_rotation = newRot * m_rotation;
	}

	void Transform::setScale(const Vector3D& s)
	{
		m_changed = true;
		m_scale = s;
	}

	void Transform::setRotation(const Quaternion& r)
	{
		m_changed = true;
		m_rotation = r;
	}

	void Transform::setTranslation(const Vector3D& t)
	{
		m_changed = true;
		m_translation = t;
	}

	Vector3D Transform::forward() const
	{
		return m_rotation * LocalForward;
	}

	Vector3D Transform::up() const
	{
		return m_rotation * LocalUp;
	}

	Vector3D Transform::right() const
	{
		return m_rotation * LocalRight;
	}
}