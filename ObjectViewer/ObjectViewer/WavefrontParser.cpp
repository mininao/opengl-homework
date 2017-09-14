#define _CRT_SECURE_NO_WARNINGS

#include "WavefrontParser.h"

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

		
		string line;
		vector<glm::vec3> vertices;
		vector<int> faces;

		printf("begin parseloop \n");
		while (getline(file, line))
		{
			string lineStart = line.substr(0, 2);

			if (lineStart == "v ")
			{
				vertices.push_back(parseVertexLine(line));
			}
			else if (lineStart == "f ")
			{
				vector<int> face = parseFaceLine(line);
				faces.insert(faces.end(), face.begin(), face.end());
			}
			else
			{
				// Unrecognized line
			}

		}
		printf("end parseloop \n");

		return Actor(vertices,faces);
	}

	glm::vec3 parseVertexLine(string line)
	{
		// Optimize with standard c char[] ? Approx 15% faster.
		string lineContent = line.substr(2);
		istringstream lineStream(lineContent);

		glm::vec3 vertex;
		lineStream >> vertex[0] >> vertex[1] >> vertex[2];
		return vertex;
	}

	vector<int> parseFaceLine(string line)
	{
		//TODO: add compat for traditional wavefront faces with slashes
		string lineContent = line.substr(2);
		istringstream lineStream(lineContent);

		vector<int> face(3);
		lineStream >> face[0] >> face[1] >> face[2];
		return face;
	}
}
