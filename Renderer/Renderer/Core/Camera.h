#pragma once

#include "../Math/Matrix4x4.h"
#include "Transform.h"

namespace kawaii
{
	class Camera
	{
	public:
		Camera(const Vector3D pos);
		~Camera() = default;

		Matrix4x4 getObjectMatrix();
		Matrix4x4 getViewMatrix();
		Vector3D getCameraPos() { update(); return m_cameraPos; }

		static const Vector3D LocalForward;
		static const Vector3D LocalUp;
		static const Vector3D LocalRight;

		void onKeyPress(char key);
		void onWheelMove(double delta);
		void onMouseMove(double deltaX, double deltaY, std::string button);

	private:
		void update();
	private:
		mutable bool m_changed;
		Vector3D m_cameraPos;
		Transform m_objects;
		Matrix4x4 m_viewMatrix;
		double m_yaw, m_pitch, m_distance;
	};
}