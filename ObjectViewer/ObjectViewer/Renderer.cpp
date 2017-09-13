#include "Renderer.h"

Renderer::Renderer()
{
	//setupSelf();
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
	setupSelf();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowHeight, windowWidth);
	glutInitContextFlags(GLUT_COMPATIBILITY_PROFILE);
	glutCreateWindow("Object Viewer");
	glutReshapeFunc(Renderer::handleResize);
	glutDisplayFunc(Renderer::renderFrame);
	glutMouseFunc(Renderer::handleMouseButton);
	glutKeyboardFunc(Renderer::handleKeyboardKeypress);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}

void Renderer::handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0,
		2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void Renderer::handleKeyboardKeypress(unsigned char key, int mouseX, int mouseY)
{
	if (key == 'q' || key == 'Q') exit(0);
}

void Renderer::handleMouseButton(int button, int state, int mouseX, int mouseY)
{
}

void Renderer::renderFrame()
{
	// Erase the previous frame's information :
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glLoadIdentity();
	for (auto&& actor : Renderer::self->actors)
	{
		actor.render();
	}
	glFlush();
	glutSwapBuffers();
}
