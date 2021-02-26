#pragma once
#include <vector>
#include "../Math/Vector3D.h"

namespace kawaii
{
	class Model
	{
	public:
		Model(const char* filename);
		~Model();
		int getVertex();
		int getFaces();
		Vector3D Vertex(int i);
		std::vector<int> Faces(int idx);
	private:
		std::vector<Vector3D> _vertex;
		std::vector<std::vector<int> > faces_;
	};
}