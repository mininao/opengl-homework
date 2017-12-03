#include "Renderer.h"
#include "MainControls.h"
// No idea why, but static class members need to be initialized outside of the class :

Renderer *Renderer::self = 0;

Renderer::Renderer()
{
	setupSelf();
	srenderer = new ShadersRenderer;
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
	printf("renderer begin");
	srenderer->renderer = self;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowHeight, windowWidth);
	glutInitContextFlags(GLUT_COMPATIBILITY_PROFILE);

	windowId = glutCreateWindow("Object Viewer");
	glutReshapeFunc(Renderer::handleResize);
	glutDisplayFunc(Renderer::renderFrame);
	glutMouseFunc(Renderer::handleMouseButton);
	glutKeyboardFunc(Renderer::handleKeyboardKeypress);

	srenderer->windowId = glutCreateWindow("Object Viewer (Shaders mode)");
	glutReshapeFunc(Renderer::handleResize);
	glutDisplayFunc(ShadersRenderer::renderFrame);
	glutMouseFunc(Renderer::handleMouseButton);
	glutKeyboardFunc(Renderer::handleKeyboardKeypress);

	glutIdleFunc(Renderer::idle);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}

void Renderer::handleResize(int w, int h)
{
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	self->camera.applyProjectionTransforms();
}

void Renderer::handleKeyboardKeypress(unsigned char key, int mouseX, int mouseY)
{
	if (key == 'a' || key == 'A') exit(0);

	if (key == 'z' || key == 'Z') self->camera.translate(0.1f,0.0f,0.0f);
	if (key == 's' || key == 'S') self->camera.translate(-0.1f,0.0f,0.0f);
	if (key == 'q' || key == 'Q') self->camera.translate(0.0f,0.1f,0.0f);
	if (key == 'd' || key == 'D') self->camera.translate(0.0f,-0.1f,0.0f);
	if (key == 'w' || key == 'W') self->camera.translate(0.0f,0.0f,0.1f);
	if (key == 'x' || key == 'X') self->camera.translate(0.0f,0.0f,-0.1f);

	if (key == 'y' || key == 'Y') self->camera.rotate(0.0f,-0.01f,0.0f);
	if (key == 'h' || key == 'H') self->camera.rotate(0.0f,0.01f,0.0f);
	if (key == 'g' || key == 'G') self->camera.rotate(0.01f,0.0f,0.0f);
	if (key == 'j' || key == 'J') self->camera.rotate(-0.01f,0.0f,0.0f);
	if (key == 'b' || key == 'B') self->camera.rotate(0.0f, 0.0f, 0.1f);
	if (key == 'n' || key == 'N') self->camera.rotate(0.0f, 0.0f, -0.1f);
}

void Renderer::handleMouseButton(int button, int state, int mouseX, int mouseY)
{
}

void Renderer::renderFrame()
{
	// Erase the previous frame's information :
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	self->camera.applyProjectionTransforms();
	// Setup Culling
	glFrontFace(self->windingOrder);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glLoadIdentity();
	self->camera.applyViewTransforms();
	
	for (auto&& actor : self->actors)
	{
		actor.render();
	}

	glFlush();
	glutSwapBuffers();
	self->mainControls->getRendererValues();
}

void Renderer::idle()
{
	glutSetWindow(self->windowId);
	glutPostRedisplay();
	glutSetWindow(self->srenderer->windowId);
	glutPostRedisplay();
}
