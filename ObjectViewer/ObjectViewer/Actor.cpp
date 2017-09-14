#include "Actor.h"


Actor::Actor(vector<glm::vec3> vertices, vector<int> faces)
{
	this->vertices = vertices;
	this->faces = faces;
	printf("Vertices %zu \nTriangles %zu \nPoints %zu \n", vertices.size(), faces.size()/ 3, faces.size());
}

void Actor::render()
{
	glPolygonMode(GL_FRONT, renderingMode);
	glBegin(GL_TRIANGLES);
	glColor3ubv(color);
	for (size_t i = 0; i < faces.size(); i++)
	{	

		glVertex3fv(glm::value_ptr(vertices[faces[i] - 1]));
		//printf("x%f y%f z%f \n", (&vertex[0])[0], (&vertex[0])[1], (&vertex[0])[2]);
	}
	glEnd();

}
