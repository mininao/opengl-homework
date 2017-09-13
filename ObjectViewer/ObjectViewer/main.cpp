#include <stdlib.h>
#include <chrono>
#include "GL/freeglut.h"
#include "MainControls.h"
#include "WavefrontParser.h"
#include "Actor.h"
#include "Camera.h"
#include "Renderer.h"

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	MainControls^ mainControls = gcnew MainControls;
	mainControls->Show();

	Camera camera = Camera();
	Actor mainActor = WavefrontParser::wavefrontToActor("models/simple.obj");
	Renderer* renderer = new Renderer;
	renderer->actors.push_back(mainActor);
	renderer->camera = camera;

	renderer->start();
}

