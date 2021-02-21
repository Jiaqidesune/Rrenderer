#include "Camera.h"

namespace kawaii
{
	const Vector3D Camera::LocalForward(0.0f, 0.0f, -1.0f);
	const Vector3D Camera::LocalUp(0.0f, 1.0f, 0.0f);
	const Vector3D Camera::LocalRight(1.0f, 0.0f, 0.0f);

	Camera::Camera(const Vector3D pos)
		:m_yaw(0), m_pitch(30.0), m_distance(10.0)
	{
		m_changed = true;
		m_objects.setTranslation(pos);
	}

	Matrix4x4 Camera::getObjectMatrix()
	{
		return m_objects.toMatrix();
	}

	Matrix4x4 Camera::getViewMatrix()
	{
		update();
		return m_viewMatrix;
	}

	void Camera::onKeyPress(char key)
	{
		double speed = 2.0f;
		switch (key)
		{
		case 'W':
			m_changed = true;
			m_objects.translate(-m_objects.forward() * 0.1f);
			break;
		case 'S':
			m_changed = true;
			m_objects.translate(+m_objects.forward() * 0.1f);
			break;
		case 'A':
			m_changed = true;
			m_objects.rotate(m_objects.up(), +speed);
			break;
		case 'D':
			m_changed = true;
			m_objects.rotate(m_objects.up(), -speed);
			break;
		}
	}

	void Camera::onWheelMove(double delta)
	{
		m_changed = true;
		double speed = 0.01;
		m_distance += -speed * delta;
		if (m_distance > 35.0)m_distance = 35.0;
		if (m_distance < 5.00)m_distance = 5.0;
	}

	void Camera::onMouseMove(double deltaX, double deltaY, std::string button)
	{
		double speed = 0.2;
		if (button == "RIGHT")
		{
			m_changed = true;
			m_pitch += speed * deltaY;
			if (m_pitch < 0.0)m_pitch = 0.0;
			if (m_pitch > 89.9)m_pitch = 89.9;
		}
		else if (button == "LEFT")
		{
			m_changed = true;
			m_yaw += -speed * deltaX;
			fmod(m_yaw, 360.0);
		}
	}

	void Camera::update()
	{
		if (m_changed)
		{
			m_changed = false;
			Vector3D target = m_objects.translation();
			float height = m_distance * sin(radians(m_pitch));
			float width = m_distance * cos(radians(m_pitch));
			m_cameraPos.x = target.x + width * sin(radians(m_yaw));
			m_cameraPos.y = target.y + height;
			m_cameraPos.z = target.z + width * cos(radians(m_yaw));
			m_viewMatrix.setLookAt(m_cameraPos, m_objects.translation(), LocalUp);
		}
	}

}