#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class GGShader
{
public:
	GGShader();

	void Set();

	void UpdateModelMatrix(const glm::mat4& model);
	void UpdateViewProjMatrix(const glm::mat4& viewProj);

private:
	unsigned CompileShader(const std::string& fileName, GLenum shaderType);
	std::string LoadShaderFile(const std::string& fileName);

private:
	unsigned m_id;
	unsigned m_modelMatrix;
	unsigned m_viewProjMatrix;;
};
