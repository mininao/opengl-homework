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

	self->projectionMatLocation = glGetUniformLocation(self->programId, "projectionMatrix");
	self->modeViewMatLocation = glGetUniformLocation(self->programId, "modelViewMatrix");
	self->cameraPosLocation = glGetUniformLocation(self->programId, "cameraPos");
	self->lightPosLocation = glGetUniformLocation(self->programId, "lightPos");
	self->lightAmbientColorLocation = glGetUniformLocation(self->programId, "lightAmbientColor");
	self->lightDiffuseColorLocation = glGetUniformLocation(self->programId, "lightDiffuseColor");
	self->lightSpecularColorLocation = glGetUniformLocation(self->programId, "lightSpecularColor");
	self->globalAmbientColorLocation = glGetUniformLocation(self->programId, "globalAmbientColor");
	self->objectColorLocation = glGetUniformLocation(self->programId, "objectColor");
	self->specularObjectColorLocation = glGetUniformLocation(self->programId, "specularObjectColor");
	self->lightEnabledLocation = glGetUniformLocation(self->programId, "lightEnabled");
	self->flatShadingLocation = glGetUniformLocation(self->programId, "flatShading");
	glValidateProgram(self->programId);
	GLint validate = 0;
	glGetProgramiv(self->programId, GL_VALIDATE_STATUS, &validate);

	glGenVertexArrays(1, &self->VAO);
	glGenBuffers(1, &self->VBO);
	glGenBuffers(1, &self->EBO);

	glBindVertexArray(self->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, self->VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, self->EBO);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// normal attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void ShadersRenderer::renderFrame()
{
	if (self->shaders.size() == 0)
	{
		self->initShaders();
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT, self->renderer->actors[0].renderingMode);
	// draw our first triangle
	glUseProgram(self->programId);
	glUniformMatrix4fv(self->projectionMatLocation, 1, GL_FALSE, glm::value_ptr(self->renderer->camera.getProjectionMatrix()));
	glUniformMatrix4fv(self->modeViewMatLocation, 1, GL_FALSE, glm::value_ptr(self->renderer->camera.getViewMatrix()));
	glUniform4fv(self->cameraPosLocation, 1, glm::value_ptr(self->renderer->camera.position));
	glUniform4fv(self->lightPosLocation, 1, glm::value_ptr(self->renderer->light.position));
	glUniform4fv(self->lightAmbientColorLocation, 1, glm::value_ptr(self->renderer->light.ambientColor));
	glUniform4fv(self->lightDiffuseColorLocation, 1, glm::value_ptr(self->renderer->light.diffuseColor));
	glUniform4fv(self->lightSpecularColorLocation, 1, glm::value_ptr(self->renderer->light.specularColor));
	glUniform4fv(self->globalAmbientColorLocation, 1, glm::value_ptr(self->renderer->ambientColor));
	glUniform4fv(self->objectColorLocation, 1, glm::value_ptr(self->renderer->actors[0].color));
	glUniform4fv(self->specularObjectColorLocation, 1, glm::value_ptr(self->renderer->actors[0].specularColor));
	glUniform1i(self->lightEnabledLocation, self->renderer->light.enabled);
	glUniform1i(self->flatShadingLocation, self->renderer->shadingModel == GL_FLAT);
	glBindVertexArray(self->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, self->VBO);
	unsigned int verticesSize = self->renderer->actors[0].rawVerticesWithNormals.size() * sizeof(float);
	glBufferData(GL_ARRAY_BUFFER, verticesSize, self->renderer->actors[0].rawVerticesWithNormals.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, self->EBO);
	unsigned int facesSize = self->renderer->actors[0].rawFaces.size() * sizeof(int);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, facesSize, self->renderer->actors[0].rawFaces.data(), GL_STATIC_DRAW);
	glDrawElements(GL_TRIANGLES, self->renderer->actors[0].rawFaces.size(), GL_UNSIGNED_INT, 0);

	// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
	// -------------------------------------------------------------------------------
	glutSwapBuffers();
}
