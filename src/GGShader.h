#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "GGTexture.h"

class GGShader
{
public:
	GGShader();

	void Set();

	void UpdateModelMatrix(const glm::mat4& model);
	void UpdateViewProjMatrix(const glm::mat4& viewProj);
	void UpdateLight(const glm::vec3& camera_pos, const glm::vec3& light_pos);

private:
	unsigned CompileShader(const std::string& fileName, GLenum shaderType);
	std::string LoadShaderFile(const std::string& fileName);

private:
	unsigned m_id;
	unsigned m_modelMatrix;
	unsigned m_viewProjMatrix;
	GLint m_normal_matrix;
	unsigned m_light_pos;
	GLint m_camera_pos;
};
