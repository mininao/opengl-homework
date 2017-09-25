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

void Camera::fitActor(Actor actor)
{
	// Give enough recoil to see object (fit 80% of frame)
	GLfloat actorMaxWidth = actor.maxCoordinates.x - actor.minCoordinates.x;
	GLfloat actorMaxHeight = actor.maxCoordinates.y - actor.minCoordinates.y;
	GLfloat actorMaxDimension = max(actorMaxHeight, actorMaxWidth);
	GLfloat requiredRecoil = (actorMaxDimension) / tan(fov / 2.0f);
	reset();
	printf("x%f y%f z%f \n", position.x, position.y, position.z);
	position.z = requiredRecoil + actor.maxCoordinates.z;
	printf("x%f y%f z%f \n", position.x, position.y, position.z);
	// Center camera on X and Y
	position.x = actor.minCoordinates.x + (actorMaxWidth / 2);
	position.y = actor.minCoordinates.y + (actorMaxHeight / 2);
	printf("x%f y%f z%f \n", position.x, position.y, position.z);
	printf("maxZactor %f \n", actor.maxCoordinates.z);
}

void Camera::reset()
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
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
	gluPerspective(fov, 1.0f, nearDistance, farDistance);
	glMatrixMode(GL_MODELVIEW);
}