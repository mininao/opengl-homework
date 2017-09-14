#pragma once
#include <GL/freeglut.h>
#include <vector>
#include "Camera.h"
#include "Actor.h"



class Renderer
{
public:
	Renderer();
	~Renderer();
	void start();
	Camera camera;
	vector<Actor> actors;
	static Renderer* self;
	GLenum windingOrder = GL_CCW;
private:
	// These have to be static in order to be passed as function callbacks
	// We use the static member "self" to refer to the instance in these functions.
	// This is mostly ok because there's only on renderer at a time.
	// See https://stackoverflow.com/questions/3589422/using-opengl-glutdisplayfunc-within-class
	// (Adopted the 1st approach in the 1st answer)
	void setupSelf();
	static void handleResize(int w, int h);
	static void handleKeyboardKeypress(unsigned char key, int mouseX, int mouseY);
	static void handleMouseButton(int button, int state, int mouseX, int mouseY);
	static void renderFrame();
	static void idle();
	int windowHeight = 1000;
	int windowWidth = 1000;
};

