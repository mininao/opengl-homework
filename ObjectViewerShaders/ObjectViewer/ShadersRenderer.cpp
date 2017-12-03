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

void ShadersRenderer::initShaders()
{
	self->shaders.push_back(ShaderManager::readFromFile("shaders/vertexshader.txt", GL_VERTEX_SHADER));
	self->shaders.push_back(ShaderManager::readFromFile("shaders/fragshader.txt", GL_FRAGMENT_SHADER));
	self->programId = ShaderManager::buildShaderProgram(self->shaders);
}

void ShadersRenderer::renderFrame()
{
	if (self->shaders.size() == 0)
	{
		self->initShaders();
	}
	glUseProgram(self->programId);
	GLint projectionMatLocation = glGetUniformLocation(self->programId, "projectionMatrix");
	GLint modeViewMatLocation = glGetUniformLocation(self->programId, "modelViewMatrix");
	glUniformMatrix4fv(projectionMatLocation, 1, GL_FALSE, glm::value_ptr(self->renderer->camera.getProjectionMatrix()));
	glUniformMatrix4fv(modeViewMatLocation, 1, GL_FALSE, glm::value_ptr(self->renderer->camera.getViewMatrix()));

	glValidateProgram(self->programId);
	GLint validate = 0;
	glGetProgramiv(self->programId, GL_VALIDATE_STATUS, &validate);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glBindVertexArray(VAO);
	//glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, 0);
	//glBindVertexArray(0);
	for (auto&& actor : self->renderer->actors)
	{
		actor.render();
	}

	glutSwapBuffers();
	self->renderer->mainControls->getRendererValues();

	//// Erase the previous frame's information :
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glShadeModel(GL_SMOOTH);
	//self->renderer->camera.applyProjectionTransforms();
	//// Setup Culling
	//glFrontFace(self->renderer->windingOrder);
	//glCullFace(GL_BACK);
	//glEnable(GL_CULL_FACE);

	//glLoadIdentity();
	//self->renderer->camera.applyViewTransforms();

	//for (auto&& actor : self->renderer->actors)
	//{
	//	actor.render();
	//}

	//glFlush();
	//glutSwapBuffers();
	//self->renderer->mainControls->getRendererValues();
}
