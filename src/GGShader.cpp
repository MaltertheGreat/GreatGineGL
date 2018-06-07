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

	m_modelMatrix = glGetUniformLocation(m_id, "model_matrix");
	m_viewProjMatrix = glGetUniformLocation(m_id, "view_proj_matrix");
	m_normal_matrix = glGetUniformLocation(m_id, "normal_matrix");
	m_light_pos = glGetUniformLocation(m_id, "light_pos");
	m_camera_pos = glGetUniformLocation(m_id, "camera_pos");
	glUseProgram(m_id);
	glUniform1i(glGetUniformLocation(m_id, "texture1"), 0);
	glUniform1i(glGetUniformLocation(m_id, "normal_map"), 1);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void GGShader::Set()
{
	glUseProgram(m_id);
}

void GGShader::UpdateTexture(GLint texture, GLint normal)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, normal);
}

void GGShader::UpdateModelMatrix(const glm::mat4& model)
{
	glUniformMatrix4fv(m_modelMatrix, 1, GL_FALSE, glm::value_ptr(model));

	glm::mat3 normal_matrix = glm::mat3(glm::transpose(glm::inverse(model)));
	glUniformMatrix3fv(m_normal_matrix, 1, GL_FALSE, glm::value_ptr(normal_matrix));
}

void GGShader::UpdateViewProjMatrix(const glm::mat4& viewProj)
{
	glUniformMatrix4fv(m_viewProjMatrix, 1, GL_FALSE, glm::value_ptr(viewProj));
}

void GGShader::UpdateLight(const glm::vec3& camera_pos, const glm::vec3& light_pos)
{
	glUniform3fv(m_camera_pos, 1, glm::value_ptr(camera_pos));
	glUniform3fv(m_light_pos, 1, glm::value_ptr(light_pos));
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
