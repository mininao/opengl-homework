#pragma once
#include "Actor.h"
#include <glm\glm.hpp>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

namespace WavefrontParser
{
		Actor wavefrontToActor(string path);
		glm::vec3 parseVertexLine(string line);
		vector<int> parseFaceLine(string line);
}