#pragma once
#include <GL/freeglut.h>
#include <array>

using namespace std;

class Camera
{
public:
	Camera();
	Camera(array<GLfloat, 3> position, array<GLfloat, 3> rotation);

	array<GLfloat, 3> position = { 0.0, 0.0, 0.0 };
	array<GLfloat, 3> rotation = { 0.0, 0.0, 0.0 };
	void rotate(GLfloat x, GLfloat y, GLfloat z);
	void translate(GLfloat x, GLfloat y, GLfloat z);
};
