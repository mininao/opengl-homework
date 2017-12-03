#pragma once
#include <GL/freeglut.h>
#include <vector>
#include <vcclr.h>
#include "Camera.h"
#include "Actor.h"

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
	// These have to be static in order to be passed as function callbacks
	// We use the static member "self" to refer to the instance in these functions.
	// This is mostly ok because there's only on renderer at a time.
	// See https://stackoverflow.com/questions/3589422/using-opengl-glutdisplayfunc-within-class
	// (Adopted the 1st approach in the 1st answer)
	void setupSelf();
};

