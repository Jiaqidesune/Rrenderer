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
}