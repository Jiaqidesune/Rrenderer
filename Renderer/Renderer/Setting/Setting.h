#pragma once

#include "../Core/Camera.h"

namespace kawaii
{
	class Setting
	{
	public:
		Setting();
		~Setting() = default;

		void receiveKeyEvent(char key);
		void receiveMouseWheelEvent(double delta);
		void receiveMouseEvent(double deltaX, double deltaY, std::string button);
	public:
		Camera* m_camera;
	};
}