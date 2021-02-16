#include<iostream>
#include "Math/Vector2D.h"
#include "Math/Vector3D.h"
#include "Math/Vector4D.h"

using namespace kawaii;
int main()
{
	Vector2D v(1.0, 1.0);
	Vector3D v1(1.0, 1.0,1.0);
	Vector3D v3(1.0, 1.0,1.0);
	Vector4D v2(1.0, 1.0,1.0,1.0);

	std::cout << v << "  " << v1 + v3;

	return 0;
}