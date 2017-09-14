#include "Camera.h"


Camera::Camera()
{
}

Camera::Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up) : Camera()
{
	this->position = position;
	this->front = front;
	this->up = up;
}

void Camera::rotate(GLfloat x, GLfloat y, GLfloat z)
{
	//rotation = { rotation[0] + x, rotation[1] + y, rotation[2] + z };
}

void Camera::translate(GLfloat frontTranslation, GLfloat rightTranslation, GLfloat upTranslation)
{
	position += front*frontTranslation;
	position += right*rightTranslation;
	position += up*upTranslation;
}

void Camera::applyViewTransforms()
{
	glMatrixMode(GL_MODELVIEW);
	glm::mat4 view = glm::lookAt(position, position + front, up);
	glMultMatrixf(glm::value_ptr(view));
//	glm::vec3 target = front + position;
//	gluLookAt(
//		0.0, 0.0, 10.0,
//		0.0, 0.0, 0.0,
//		0.0, 1.0, 0.0
//		);
}

void Camera::applyProjectionTransforms()
{
	glMatrixMode(GL_PROJECTION);
//	glOrtho(-2.0, 2.0, -2.0,
//		2.0, -10.0, 10.0);
	// TODO Support aspect ratio modification by window resizing
	//glm::mat4 perspective = glm::perspective(45.0f, 1.0f, 0.1f, 20.0f);
	//glMultMatrixf(glm::value_ptr(perspective));
	gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}