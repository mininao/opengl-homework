#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

class Light
{
public:
	Light();

	void declareFixedPipeline();

	glm::vec4 ambientColor = glm::vec4(0.15f, 0.15f, 0.3f, 1.0f);
	glm::vec4 diffuseColor = glm::vec4(0.45f, 0.45f, 0.0f, 1.0f);
	glm::vec4 specularColor = glm::vec4(0.7f, 0.7f, 0.7f, 1.0f);
	glm::vec4 position = glm::vec4(0.0f, 0.5f, 4.0f, 1.0f);
	GLenum id = GL_LIGHT0;
	bool enabled = true;
	bool enableDraw = true;
	bool enableTestSpheres = true;
	bool animateRotation = false;
private:
	void drawTestSpheres();
};