#include "Camera.h"
#include "glm\gtx\string_cast.hpp"
#include <iostream>

Camera::Camera()
{
}

Camera::Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up) : Camera()
{
	this->position = position;
	this->front = front;
	this->up = up;
}

void Camera::rotate(GLfloat yaw, GLfloat pitch, GLfloat roll)
{
	// Yaw rotates around up
	// Pitch rotates around right
	// Roll rotates around front (seldom used)
	
	glm::mat4 yawTransform = glm::rotate(yaw, up);
	glm::mat4 pitchTransform = glm::rotate(pitch, right);
	glm::mat4 rollTransform = glm::rotate(roll, front);
	front = yawTransform * pitchTransform * rollTransform * glm::vec4(front, 0.0f);
	up = yawTransform * pitchTransform * rollTransform * glm::vec4(up, 0.0f);
	right = yawTransform * pitchTransform * rollTransform * glm::vec4(right, 0.0f);
}

void Camera::translate(GLfloat frontTranslation, GLfloat rightTranslation, GLfloat upTranslation)
{
	position += front*frontTranslation;
	position += right*rightTranslation;
	position += up*upTranslation;
}

void Camera::reset()
{
	position = glm::vec3(0.0f, 0.0f, 20.0f);

	front = glm::vec3(0.0f, 0.0f, -1.0f);
	right = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), front));
	up = glm::cross(front, right);

	nearDistance = 0.1f;
	farDistance = 100.0f;
}

void Camera::applyViewTransforms()
{
	glMatrixMode(GL_MODELVIEW);
	glm::mat4 view = glm::lookAt(position, position + front, up);
	glMultMatrixf(glm::value_ptr(view));
}

void Camera::applyProjectionTransforms()
{
	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);
	// Reset Matrix
	glLoadIdentity();
	// TODO Support aspect ratio modification by window resizing
	gluPerspective(45.0f, 1.0f, nearDistance, farDistance);
	glMatrixMode(GL_MODELVIEW);
}