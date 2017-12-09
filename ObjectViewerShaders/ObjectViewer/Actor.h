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
	Actor(vector<glm::vec3> vertices, vector<vector<int>> faces, vector<int> rawFaces);

	void render();
	void computeNormals();
	glm::vec4 color = glm::vec4(1.0f, 0.5f, 0.3f, 1.0f);
	glm::vec4 specularColor = glm::vec4(0.8f, 0.8f, 0.8f, 1.0f);
	glm::vec3 maxCoordinates;
	glm::vec3 minCoordinates;
	bool showBoundingBox = false;
	GLenum renderingMode = GL_FILL;
	vector<glm::vec3> vertices;
	vector<GLfloat> rawVerticesWithNormals;
	vector<glm::vec3> normals;
	vector<vector<int>> faces;
	vector<int> rawFaces;
};
