#include "Actor.h"


Actor::Actor(vector<glm::vec3> vertices, vector<int> faces)
{
	this->vertices = vertices;
	this->faces = faces;
	printf("Vertices %zu \nTriangles %zu \nPoints %zu \n", vertices.size(), faces.size()/ 3, faces.size());
}

void Actor::render()
{
	// Proper model rendering
	glPolygonMode(GL_FRONT, renderingMode);
	glBegin(GL_TRIANGLES);
	glColor3ubv(color);
	for (size_t i = 0; i < faces.size(); i++)
	{	
		glVertex3fv(glm::value_ptr(vertices[faces[i] - 1]));
		//printf("x%f y%f z%f \n", (&vertex[0])[0], (&vertex[0])[1], (&vertex[0])[2]);
	}
	glEnd();

	// Bounding box rendering
	if(showBoundingBox)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3fv(glm::value_ptr(minCoordinates)); //1
		glVertex3f(maxCoordinates.x, minCoordinates.y, minCoordinates.z); //2
		glVertex3f(maxCoordinates.x, maxCoordinates.y, minCoordinates.z); //7
		glVertex3f(minCoordinates.x, maxCoordinates.y, minCoordinates.z); //6
		glVertex3fv(glm::value_ptr(minCoordinates)); //1
		glVertex3f(minCoordinates.x, minCoordinates.y, maxCoordinates.z); //4
		glVertex3f(minCoordinates.x, maxCoordinates.y, maxCoordinates.z); //5
		glVertex3f(minCoordinates.x, maxCoordinates.y, minCoordinates.z); //6
		glVertex3f(maxCoordinates.x, maxCoordinates.y, minCoordinates.z); //7
		glVertex3fv(glm::value_ptr(maxCoordinates)); //8
		glVertex3f(minCoordinates.x, maxCoordinates.y, maxCoordinates.z); //5
		glVertex3f(minCoordinates.x, minCoordinates.y, maxCoordinates.z); //4
		glVertex3f(maxCoordinates.x, minCoordinates.y, maxCoordinates.z); //3
		glVertex3f(maxCoordinates.x, minCoordinates.y, minCoordinates.z); //2
		glVertex3f(maxCoordinates.x, minCoordinates.y, maxCoordinates.z); //3
		glVertex3fv(glm::value_ptr(maxCoordinates)); //8
		glEnd();
	}

}
