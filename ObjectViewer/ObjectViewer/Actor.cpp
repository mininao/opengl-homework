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
	glColor3ubv(color);
	//printf("size %i \n", faces.size());
	for (auto&& face : faces)
	{
		for (auto&& vertexId : face)
		{
			vector<GLfloat> vertex = vertices[vertexId - 1];
			glVertex3fv(&vertex[0]);
			//printf("x%f y%f z%f \n", (&vertex[0])[0], (&vertex[0])[1], (&vertex[0])[2]);

		}
	}
//	glVertex3f(0.0, 0.0, 0.0);
//	glVertex3f(0.0, 1.0, 1.0);
//	glVertex3f(1.0, 0.0, 0.0);
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
