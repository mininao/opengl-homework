#pragma once
#include "Actor.h"
#include <string>

using namespace std;

namespace WavefrontParser
{
		Actor wavefrontToActor(string path);
		vector<GLfloat> parseVertexLine(string line);
		vector<GLint> parseFaceLine(string line);
}