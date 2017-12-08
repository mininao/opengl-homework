#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include <numeric>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

class Actor
{
public:
	Actor(vector<glm::vec3> vertices, vector<vector<int>> faces);

	void render();
	void computeNormals();
	GLubyte color[3] = { 0xFF, 0x7F, 0x46 };
	glm::vec4 specularColor = glm::vec4(0.8f, 0.8f, 0.8f, 1.0f);
	glm::vec3 maxCoordinates;
	glm::vec3 minCoordinates;
	bool showBoundingBox = false;
	GLenum renderingMode = GL_FILL;
private:
	vector<glm::vec3> vertices;
	vector<glm::vec3> normals;
	vector<vector<int>> faces;
};
