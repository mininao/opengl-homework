#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include <vcclr.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"
#include "Actor.h"
#include "ShaderManager.h"


// Forward declaration of MainControls to avoid circular dependency
ref class MainControls;

class Renderer;

class ShadersRenderer
{
public:
	ShadersRenderer();
	~ShadersRenderer();
	static ShadersRenderer* self;
	Renderer* renderer;
	static void renderFrame();
	int windowId = 0;
private:
	vector<GLuint> shaders;
	GLuint programId;
	void setupSelf();
	void initShaders();
};

