#include "Setting.h"

namespace kawaii
{
	Setting::Setting()
	{
		m_camera = new Camera(Vector3D(-0.0f, 5.0f, 14.0f));
	}

	void Setting::receiveKeyEvent(char key)
	{
		m_camera->onKeyPress(key);
	}

	void Setting::receiveMouseWheelEvent(double delta)
	{
		m_camera->onWheelMove(delta);
	}

	void Setting::receiveMouseEvent(double deltaX, double deltaY, std::string button)
	{
		m_camera->onMouseMove(deltaX, deltaY, button);
	}
}