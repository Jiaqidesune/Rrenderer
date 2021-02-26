#include "Model.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

namespace kawaii
{
	Model::Model(const char* filename)
	{
        std::ifstream in;
        in.open(filename, std::ifstream::in);
        if (in.fail()) return;
        std::string line;
        while (!in.eof()) {
            std::getline(in, line);
            std::istringstream iss(line.c_str());
            char trash;
            if (!line.compare(0, 2, "v ")) {
                iss >> trash;
                Vector3D v;
                for (int i = 0; i < 3; i++)
                {
                    iss >> v.x;
                    iss >> v.y;
                    iss >> v.z;
                }
                _vertex.push_back(v);
            }
            else if (!line.compare(0, 2, "f ")) {
                std::vector<int> f;
                int itrash, idx;
                iss >> trash;
                while (iss >> idx >> trash >> itrash >> trash >> itrash) {
                    idx--; // in wavefront obj all indices start at 1, not zero
                    f.push_back(idx);
                }
                faces_.push_back(f);
            }
        }
        std::cerr << "# v# " << _vertex.size() << " f# " << faces_.size() << std::endl;
	}

	Model::~Model() {}

	int Model::getVertex()
	{
        return _vertex.size();
	}

	int Model::getFaces()
	{
		return faces_.size();
	}

	Vector3D Model::Vertex(int i)
	{
        return _vertex[i];
	}

	std::vector<int> Model::Faces(int idx)
	{
        return faces_[idx];
	}
}