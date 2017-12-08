#include "Actor.h"


Actor::Actor(vector<glm::vec3> vertices, vector<vector<int>> faces)
{
	this->vertices = vertices;
	this->faces = faces;
	this->computeNormals();
	printf("Vertices %zu \nTriangles %zu \nPoints %zu \n", vertices.size(), faces.size(), faces.size() * 3);
}

void Actor::render()
{
	// Proper model rendering
	glPolygonMode(GL_FRONT, renderingMode);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glBegin(GL_TRIANGLES);
	glMaterialfv(GL_FRONT, GL_SPECULAR, glm::value_ptr(specularColor));
	glMateriali(GL_FRONT, GL_SHININESS, 96);
	glColor3ubv(color);
	for (auto&& face : faces)
	{	
		for (size_t i = 0; i < face.size(); i++)
		{
			glNormal3fv(glm::value_ptr(normals[face[i] - 1]));
			glVertex3fv(glm::value_ptr(vertices[face[i] - 1]));
		}
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
		glPolygonMode(GL_FRONT, renderingMode);
	}

}

void Actor::computeNormals()
{
	vector<vector<glm::vec3>> verticesNormals(vertices.size()); // Holds the normals of a vertex's faces. Their length is their weight

	// Compute the normals at each vertex
	for (auto&& face : faces)
	{
		glm::vec3 v0 = vertices[face[0] - 1];
		glm::vec3 v1 = vertices[face[1] - 1];
		glm::vec3 v2 = vertices[face[2] - 1];

		glm::vec3 edge1 = glm::vec3(v1 - v0);
		glm::vec3 edge2 = glm::vec3(v2 - v1);
		glm::vec3 normal = glm::cross(edge1, edge2);

		verticesNormals[face[0] - 1].push_back(normal);
		verticesNormals[face[1] - 1].push_back(normal);
		verticesNormals[face[2] - 1].push_back(normal);
	}

	// Average ans save the normals
	normals.clear();
	normals.resize(vertices.size());
	for (size_t i = 0; i < verticesNormals.size(); i++)
	{
		glm::vec3 sum = std::accumulate(verticesNormals[i].begin(), verticesNormals[i].end(), glm::vec3(0.0f));
		normals[i] = glm::normalize(sum);
	}
}
