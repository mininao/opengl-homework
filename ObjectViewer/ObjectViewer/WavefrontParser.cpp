#define _CRT_SECURE_NO_WARNINGS

#include "WavefrontParser.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

namespace WavefrontParser
{
	Actor wavefrontToActor(string path)
	{
		/**
		* Code inspired from :
		* https://github.com/joyeecheung/obj-loader/blob/master/src/glm.cpp
		* http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/
		* http://netization.blogspot.in/2014/10/loading-obj-files-in-opengl.html
		*/

		ifstream file(path);

		//TODO: Check file exists

		Actor actor;
		string line;

		printf("begin parseloop \n");
		while (getline(file, line))
		{
			string lineStart = line.substr(0, 2);

			if (lineStart == "v ")
			{
				actor.pushVertex(parseVertexLine(line));
			}
			else if (lineStart == "f ")
			{
				actor.pushFace(parseFaceLine(line));
			}
			else
			{
				// Unrecognized line
			}

		}
		printf("end parseloop \n");

		return actor;
	}

	vector<GLfloat> parseVertexLine(string line)
	{
		// Optimize with standard c char[] ? Approx 15% faster.
		string lineContent = line.substr(2);
		vector<GLfloat> vertex(3);
		istringstream lineStream(lineContent);
		lineStream >> vertex[0] >> vertex[1] >> vertex[2];
		return vertex;
	}

	vector<GLint> parseFaceLine(string line)
	{
		//TODO: add compat for traditional wavefront faces with slashes
		string lineContent = line.substr(2);
		vector<GLint> face(3);
		istringstream lineStream(lineContent);
		lineStream >> face[0] >> face[1] >> face[2];

		return face;
	}
}
