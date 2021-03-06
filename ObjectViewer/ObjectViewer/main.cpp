#include <stdlib.h>
#include <functional>
#include "GL/freeglut.h"
#include "MainControls.h"
#include "WavefrontParser.h"
#include "Actor.h"
#include "Camera.h"
#include "Renderer.h"

// STAThread is a .NET/CLR shenanigan needed for the file open dialog (https://goo.gl/X8Jemw)
[System::STAThread] int main(int argc, char **argv)
{
	#ifndef _DEBUG
		FreeConsole(); // Hide the console in release builds
	#endif	
	
	glutInit(&argc, argv);
	
	Camera camera = Camera();
	Actor mainActor = WavefrontParser::wavefrontToActor("models/simple.obj");
	Renderer* renderer = new Renderer;
	renderer->actors.push_back(mainActor);
	camera.fitActor(mainActor);
	renderer->camera = camera;

	MainControls^ mainControls = gcnew MainControls(renderer);
	mainControls->Show();

	renderer->mainControls = mainControls;
	renderer->start();
}