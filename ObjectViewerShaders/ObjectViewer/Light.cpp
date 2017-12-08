#include "Light.h"


Light::Light()
{

}

void Light::declareFixedPipeline()
{
	//printf("coucou");
	if (this->enabled) {
		glEnable(this->id);
		glLightfv(this->id, GL_AMBIENT, glm::value_ptr(this->ambientColor));
		glLightfv(this->id, GL_DIFFUSE, glm::value_ptr(this->diffuseColor));
		glLightfv(this->id, GL_SPECULAR, glm::value_ptr(this->specularColor));
		glLightfv(this->id, GL_POSITION, glm::value_ptr(this->position));
	}
	else {
		glDisable(this->id);
	}
	if (this->enableDraw) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		if (this->enabled) glColor3fv(glm::value_ptr(this->specularColor));
		else glColor3fv(glm::value_ptr(this->ambientColor));
		glTranslatef(this->position.x, this->position.y, this->position.z);
		glutSolidSphere(0.05, 50, 50);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
	if (this->enableTestSpheres) this->drawTestSpheres();
}

void Light::drawTestSpheres()
{
	// test
	glPushMatrix();
	glColor3d(1, 1, 1);
	glTranslatef(-1.0f, -1.0f, -1.0f);
	glutSolidSphere(0.1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1, 1, 1);
	glTranslatef(-1.0f, -1.0f, 1.0f);
	glutSolidSphere(0.1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1, 1, 1);
	glTranslatef(-1.0f, 1.0f, -1.0f);
	glutSolidSphere(0.1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1, 1, 1);
	glTranslatef(-1.0f, 1.0f, 1.0f);
	glutSolidSphere(0.1, 50, 50);
	glPopMatrix();
	//
	glPushMatrix();
	glColor3d(1, 1, 1);
	glTranslatef(1.0f, -1.0f, -1.0f);
	glutSolidSphere(0.1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1, 1, 1);
	glTranslatef(1.0f, -1.0f, 1.0f);
	glutSolidSphere(0.1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1, 1, 1);
	glTranslatef(1.0f, 1.0f, -1.0f);
	glutSolidSphere(0.1, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1, 1, 1);
	glTranslatef(1.0f, 1.0f, 1.0f);
	glutSolidSphere(0.1, 50, 50);
	glPopMatrix();
}
