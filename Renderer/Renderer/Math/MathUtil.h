#pragma once

#include <cmath>
#include <iostream>

namespace kawaii
{

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

	const double epsilon = 1e-5f;

	inline bool Equal(float x, float y)
	{
		return fabs(x - y) < epsilon;
	}

	inline double radians(double angle)
	{
		return angle * M_PI / 180.0f;
	}

	inline double angles(double radians)
	{
		return radians * 180.0 / M_PI;
	}
}