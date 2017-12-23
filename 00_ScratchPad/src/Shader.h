#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	// program ID
	unsigned int ID;

	// constructor
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	// activate shader
	void use();

	// SETTERS
	void setMat4(const std::string &name, glm::mat4 value) const
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}
};