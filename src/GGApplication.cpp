#include "GGApplication.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

GGApplication::GGApplication() :
	m_window(CreateWindow()),
	m_graphics(m_window)
{
}

void GGApplication::Run()
{
	while(!glfwWindowShouldClose(m_window))
	{
		ProcessInput();
		Update();
		Render();

		glfwPollEvents();
	}

	glfwTerminate();
}

void GGApplication::Update()
{
	m_graphics.Update();
}

void GGApplication::Render()
{
	m_graphics.Render(m_window);
}

GLFWwindow* GGApplication::CreateWindow()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (!window)
	{
		throw std::runtime_error("Failed to create GLFW window");
	}

	glfwMakeContextCurrent(window);

	return window;
}

void GGApplication::ProcessInput()
{
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_window, true);
}
