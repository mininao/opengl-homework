#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream> 
#include <sstream>
#include <vector>

using namespace std;

namespace ShaderManager
{
	GLuint readFromFile(string path, GLenum shaderType);
	GLuint buildShaderProgram(vector<GLuint> shaders);
	void readShaderFile(const GLchar* shaderPath, string& shaderCode);
}
