#pragma once
#include <GL/freeglut.h>
#include <vector>

using namespace std;

class Actor
{
public:
	Actor();
	Actor(vector<vector<GLfloat>> vertices, vector<vector<GLint>> faces);

	void render();
	void pushVertex(vector<GLfloat> vertex);
	void pushFace(vector<GLint> face);

private:
	vector<vector<GLfloat>> vertices;
	vector<vector<GLint>> faces;
};
