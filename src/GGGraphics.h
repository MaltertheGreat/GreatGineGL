#pragma once

#include "GGOGL.h"
#include "GGShader.h"

class GLFWwindow;

class GGGraphics
{
public:
	GGGraphics(GLFWwindow* window);

public:
	void Update();
	void Render(GLFWwindow* window);

private:
	static void FramebufferSize(GLFWwindow* window, int width, int height);

private:
	GGOGL m_ogl;
	unsigned m_vao;
	unsigned m_vbo;
	GGShader m_shader;
};
