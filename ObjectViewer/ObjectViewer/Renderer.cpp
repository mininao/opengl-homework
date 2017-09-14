#include "Renderer.h"

// No idea why, but static class members need to be initialized outside of the class :

Renderer *Renderer::self = 0;


Renderer::Renderer()
{
	setupSelf();
}

Renderer::~Renderer()
{
}

void Renderer::setupSelf()
{
	Renderer::self = this;
}

void Renderer::start()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowHeight, windowWidth);
	glutInitContextFlags(GLUT_COMPATIBILITY_PROFILE);
	glutCreateWindow("Object Viewer");
	glutReshapeFunc(Renderer::handleResize);
	glutDisplayFunc(Renderer::renderFrame);
	glutMouseFunc(Renderer::handleMouseButton);
	glutKeyboardFunc(Renderer::handleKeyboardKeypress);
	glutIdleFunc(Renderer::idle);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}

void Renderer::handleResize(int w, int h)
{
	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	self->camera.applyProjectionTransforms();
}

void Renderer::handleKeyboardKeypress(unsigned char key, int mouseX, int mouseY)
{
	if (key == 'q' || key == 'Q') exit(0);
	if (key == 'z' || key == 'Z') self->camera.translate(0.1,0.0,0.0);
	if (key == 's' || key == 'S') self->camera.translate(-0.1,0.0,0.0);
}

void Renderer::handleMouseButton(int button, int state, int mouseX, int mouseY)
{
}

void Renderer::renderFrame()
{
	// Erase the previous frame's information :
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glFrontFace(self->windingOrder);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	// Reset the ModelView Transformation matrix
	glLoadIdentity();
	self->camera.applyViewTransforms();

	
	for (auto&& actor : self->actors)
	{
		actor.render();
	}
	glFlush();
	glutSwapBuffers();
}

void Renderer::idle()
{
	glutPostRedisplay();
}
