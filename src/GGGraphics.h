#pragma once

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
	unsigned m_vao;
	unsigned m_vbo;
	unsigned m_shaderProgram;
};
