#include "ShaderManager.h"

namespace ShaderManager {
	GLuint readFromFile(string path, GLenum shaderType)
	{
		string shaderString;
		GLuint shaderId = glCreateShader(shaderType);

		readShaderFile(path.c_str(), shaderString);

		const GLchar * shaderSource = shaderString.c_str();

		glShaderSource(shaderId, 1, &shaderSource, NULL);

		glCompileShader(shaderId);

		// Check compilation result :
		int  success;
		char infoLog[512];
		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		return shaderId;
	}
	void readShaderFile(const GLchar* shaderPath, string& shaderCode)
	{

		ifstream shaderFile;

		// ensures ifstream objects can throw exceptions:
		shaderFile.exceptions(ifstream::badbit);
		try
		{
			// Open files
			shaderFile.open(shaderPath);
			stringstream shaderStream;

			// Read file's buffer contents into streams
			shaderStream << shaderFile.rdbuf();

			// close file handlers
			shaderFile.close();

			// Convert stream into GLchar array
			shaderCode = shaderStream.str();
		}
		catch (ifstream::failure e)
		{
			cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
		}

	}
	GLuint buildShaderProgram(vector<GLuint> shaders) {
		GLuint programId = glCreateProgram();
		for (auto &shaderId : shaders)
		{
			glAttachShader(programId, shaderId);
		}

		glLinkProgram(programId);

		for (auto &shaderId : shaders) // access by reference to avoid copying
		{
			glDeleteShader(shaderId);
		}
		return programId;
	}
}

