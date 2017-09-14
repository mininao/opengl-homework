#pragma once
#include <GL/freeglut.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace std;

class Actor
{
public:
	Actor();
	Actor(vector<vector<GLfloat>> vertices, vector<vector<GLint>> faces);

	void render();
	void pushVertex(vector<GLfloat> vertex);
	void pushFace(vector<GLint> face);

	GLubyte color[3] = { 0xFF, 0x7F, 0x46 };
private:
	vector<vector<GLfloat>> vertices;
	vector<vector<GLint>> faces;
};
