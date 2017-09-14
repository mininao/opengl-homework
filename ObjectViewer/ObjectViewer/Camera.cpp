#include "Camera.h"


Camera::Camera()
{
}

Camera::Camera(array<GLfloat, 3> position, array<GLfloat, 3> rotation) : Camera()
{
	this->position = position;
	this->rotation = rotation;
}

void Camera::rotate(GLfloat x, GLfloat y, GLfloat z)
{
	rotation = { rotation[0] + x, rotation[1] + y, rotation[2] + z };
}

void Camera::translate(GLfloat x, GLfloat y, GLfloat z)
{
	position = { position[0] + x, position[1] + y, position[2] + z };
}

void Camera::applyProjectionMatrix()
{
	glFrustum(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
}