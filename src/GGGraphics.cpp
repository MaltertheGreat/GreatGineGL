#include "GGGraphics.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <stdexcept>

static int m_window_width = 800;
static int m_window_height = 600;

GGGraphics::GGGraphics(GLFWwindow* window)
{
	glfwSetFramebufferSizeCallback(window, FramebufferSize);
}

void GGGraphics::Update(GLFWwindow* window)
{
	UpdateCameraPos(window);

	m_camera.UpdateView(m_camera_pos, m_camera_rot);
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

void GGGraphics::UpdateCameraPos(GLFWwindow* window)
{
	glm::vec3 front = {
		sin(m_camera_rot.y)*cos(m_camera_rot.x),
		sin(m_camera_rot.x),
		cos(m_camera_rot.y)*cos(m_camera_rot.x)};
	front = glm::normalize(front);
	glm::vec3 up = {0.0f, 1.0f, 0.0f};

	float camera_speed = 0.01f;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		m_camera_pos += camera_speed*front;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		m_camera_pos -= camera_speed*front;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		m_camera_pos += glm::normalize(glm::cross(front, up))*camera_speed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		m_camera_pos -= glm::normalize(glm::cross(front, up))*camera_speed;
}

void GGGraphics::FramebufferSize(GLFWwindow* window, int width, int height)
{
	m_window_width = width;
	m_window_height = height;
	glViewport(0, 0, width, height);
}
