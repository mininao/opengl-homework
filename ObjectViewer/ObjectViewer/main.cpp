#include <stdlib.h>
#include <chrono>
#include "GL/freeglut.h"
#include "WavefrontParser.h"
#include "Actor.h"

Actor mainActor;

static GLfloat theta[] = { 0.0, 0.0, 0.0 };
static GLint axis = 2;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glLoadIdentity();
	mainActor.render();
	glFlush();
	glutSwapBuffers();
}


void idle()
{
	//glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'q' || key == 'Q') exit(0);
}

void handleReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	int widthFactor = w / 1000;
	int heightFactor = h / 1000;
	glOrtho(-2.0, 2.0, -2.0,
		2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char **argv)
{
	mainActor = WavefrontParser::wavefrontToActor("models/simple.obj");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutInitContextFlags(GLUT_COMPATIBILITY_PROFILE);
	glutCreateWindow("Object Viewer");
	glutReshapeFunc(handleReshape);
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}

