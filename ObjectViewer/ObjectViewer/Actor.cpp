#include "Actor.h"


Actor::Actor()
{
	vertices = {};
	faces = {};
}

Actor::Actor(vector<vector<GLfloat>> vertices, vector<vector<GLint>> faces) : Actor()
{
	this->vertices = vertices;
	this->faces = faces;
}

void Actor::render()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.5, 0.3);
	for (auto&& face : faces)
	{
		for (auto&& vertexId : face)
		{
			vector<GLfloat> vertex = vertices[vertexId - 1];
			glVertex3fv(&vertex[0]);
		}
	}
	glEnd();

}

void Actor::pushVertex(vector<GLfloat> vertex)
{
	this->vertices.push_back(vertex);
}

void Actor::pushFace(vector<GLint> face)
{
	this->faces.push_back(face);
}
