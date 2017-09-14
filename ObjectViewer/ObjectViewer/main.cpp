#include <stdlib.h>
#include <functional>
#include "GL/freeglut.h"
#include "MainControls.h"
#include "WavefrontParser.h"
#include "Actor.h"
#include "Camera.h"
#include "Renderer.h"

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	Camera camera = Camera();
	Actor mainActor = WavefrontParser::wavefrontToActor("models/cactus.obj");
	Renderer* renderer = new Renderer;
	renderer->actors.push_back(mainActor);
	renderer->camera = camera;
	
	MainControls^ mainControls = gcnew MainControls(renderer);
	mainControls->Show();

	renderer->mainControls = mainControls;

	renderer->start();
}