#pragma once

#include <memory>

#include "GGOGL.h"
#include "GGShader.h"
#include "GGCamera.h"
#include "GGMesh.h"

class GLFWwindow;

class GGGraphics
{
public:
	GGGraphics(GLFWwindow* window);

public:
	void Update(GLFWwindow* window);
	void Render(GLFWwindow* window);

private:
	void UpdateCameraPos(GLFWwindow* window);

	static void FramebufferSize(GLFWwindow* window, int width, int height);

private:
	glm::vec3 m_camera_pos;
	glm::vec3 m_camera_rot;
	GGOGL m_ogl;
	GGShader m_shader;
	GGCamera m_camera;
	GGMesh m_mesh;
};
