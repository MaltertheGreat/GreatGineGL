#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class GGShader
{
public:
	GGShader();

	void Set();

private:
	unsigned CompileShader(const std::string& fileName, GLenum shaderType);
	std::string LoadShaderFile(const std::string& fileName);

private:
	unsigned m_id;
};
