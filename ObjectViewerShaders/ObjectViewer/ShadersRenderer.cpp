#include "ShadersRenderer.h"
#include "MainControls.h"
// No idea why, but static class members need to be initialized outside of the class :

ShadersRenderer *ShadersRenderer::self = 0;

ShadersRenderer::ShadersRenderer()
{
	setupSelf();
}

ShadersRenderer::~ShadersRenderer()
{
}

void ShadersRenderer::setupSelf()
{
	ShadersRenderer::self = this;
}

void ShadersRenderer::renderFrame()
{
	// Erase the previous frame's information :
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	self->renderer->camera.applyProjectionTransforms();
	// Setup Culling
	glFrontFace(self->renderer->windingOrder);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glLoadIdentity();
	self->renderer->camera.applyViewTransforms();

	for (auto&& actor : self->renderer->actors)
	{
		actor.render();
	}

	glFlush();
	glutSwapBuffers();
	self->renderer->mainControls->getRendererValues();
}
