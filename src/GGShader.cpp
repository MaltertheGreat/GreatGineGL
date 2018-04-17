#include "GGShader.h"
#include <glm/gtc/type_ptr.hpp>

GGShader::GGShader()
{
	int success;
	char infoLog[512];

	auto vertexShader = CompileShader("basic.vs", GL_VERTEX_SHADER);
	auto fragmentShader = CompileShader("basic.fs", GL_FRAGMENT_SHADER);

	m_id = glCreateProgram();
	glAttachShader(m_id, vertexShader);
	glAttachShader(m_id, fragmentShader);
	glLinkProgram(m_id);

	glGetProgramiv(m_id, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cerr << "Error linking the shader program!" << std::endl;
		std::cerr << infoLog << std::endl;

		throw std::runtime_error("GGShader");
	}

	m_modelMatrix = glGetUniformLocation(m_id, "model");
	m_viewProjMatrix = glGetUniformLocation(m_id, "viewProj");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void GGShader::Set()
{
	glUseProgram(m_id);
}

void GGShader::UpdateModelMatrix(const glm::mat4& model)
{
	glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(model));
}

void GGShader::UpdateViewProjMatrix(const glm::mat4& viewProj)
{
	glUniformMatrix4fv(m_viewProjMatrix, 1, GL_FALSE, glm::value_ptr(viewProj));
}

unsigned GGShader::CompileShader(const std::string& fileName, GLenum shaderType)
{
	auto shaderCode = LoadShaderFile(fileName);

	int success;
	char infoLog[512];

	auto shaderCodeString = shaderCode.c_str();
	unsigned shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderCodeString, NULL);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cerr << "Error compiling the shader!" << std::endl;
		std::cerr << infoLog << std::endl;

		throw std::runtime_error("GGShader");
	};

	return shader;
}

std::string GGShader::LoadShaderFile(const std::string& fileName)
{
	try
	{
		std::ifstream shaderFile;
		shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		std::stringstream shaderStream;

		shaderFile.open(fileName);
		shaderStream << shaderFile.rdbuf();

		return shaderStream.str();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error reading shader file:" << std::endl;
		std::cerr << e.what() << std::endl;

		throw std::runtime_error("GGShader");
	}
}