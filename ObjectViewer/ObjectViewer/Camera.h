#pragma once
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <array>

using namespace std;

// Good read : https://learnopengl.com/#!Getting-started/Camera
class Camera
{
public:
	Camera();
	Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up);

	glm::vec3 position = glm::vec3(0.0f, 0.0f, 20.0f);
	
	glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 right = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), front));
	glm::vec3 up = glm::cross(front, right);

	GLfloat nearDistance = 0.0;
	GLfloat farDistance = 20.0;
	void rotate(GLfloat x, GLfloat y, GLfloat z);
	void translate(GLfloat frontTranslation, GLfloat rightTranslation, GLfloat upTranslation);
	void Camera::applyViewTransforms();
	void Camera::applyProjectionTransforms();
};
