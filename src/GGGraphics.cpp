#include "GGGraphics.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <stdexcept>

static int m_window_width = 800;
static int m_window_height = 600;

GGGraphics::GGGraphics(GLFWwindow* window, GGInput& input) :
	m_camera(input)
{
	glfwSetFramebufferSizeCallback(window, FramebufferSize);
}

void GGGraphics::Update(GLFWwindow* window)
{
	m_camera.Update();
	m_camera.UpdateProj(45.0f, m_window_width/static_cast<float>(m_window_height), 0.1f, 100.0f);

	m_shader.UpdateModelMatrix(glm::translate(glm::mat4(), {0.0f, 0.0f, 0.0f}));
	m_shader.UpdateViewProjMatrix(m_camera.GetViewProj());
}

void GGGraphics::Render(GLFWwindow* window)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	m_shader.Set();
	m_mesh.Render();

	glfwSwapBuffers(window);
}

void GGGraphics::FramebufferSize(GLFWwindow* window, int width, int height)
{
	m_window_width = width;
	m_window_height = height;
	glViewport(0, 0, width, height);
}
