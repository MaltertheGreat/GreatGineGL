#include "GGGraphics.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <stdexcept>

static int m_window_width = 800;
static int m_window_height = 600;

GGGraphics::GGGraphics(GLFWwindow* window, GGInput& input) :
	m_camera(input, {0.0f, 0.0f, -4.0f}),
	m_texture("texture1.png"),
	m_normal_map("texture.png")
{
	glfwSetFramebufferSizeCallback(window, FramebufferSize);
	glEnable(GL_FRAMEBUFFER_SRGB);
}

void GGGraphics::Update(GLFWwindow* window)
{
	m_camera.Update();
	m_camera.UpdateProj(45.0f, m_window_width/static_cast<float>(m_window_height), 0.1f, 100.0f);

	m_shader.Set();
	static float delta = 0.0f;
	delta += 0.01f;
	//m_shader.UpdateModelMatrix(glm::translate(glm::mat4(1.0f), {0.0f, 0.0f, distance}));
	auto world_matrix = glm::mat4(1.0f);;
	world_matrix = glm::scale(world_matrix, {16.0f, 16.0f, 16.0f});
	//world_matrix = glm::rotate(world_matrix, delta, {0.0f, 1.0f, 0.0f});
	m_shader.UpdateModelMatrix(world_matrix);
	m_shader.UpdateViewProjMatrix(m_camera.GetViewProj());

	//m_shader.UpdateLight(m_camera.GetPosition(), {0.5f*sin(delta), 0.5f*cos(delta), -0.1f});
	m_shader.UpdateLight(m_camera.GetPosition(), m_camera.GetPosition());
	m_shader.UpdateTexture(m_texture.GetID(), m_normal_map.GetID());
}

void GGGraphics::Render(GLFWwindow* window)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_DEPTH_BUFFER_BIT);
	glFrontFace(GL_CW);
	glDisable(GL_CULL_FACE);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	m_shader.Set();
	m_chunk.Render();

	glfwSwapBuffers(window);
}

void GGGraphics::FramebufferSize(GLFWwindow* window, int width, int height)
{
	m_window_width = width;
	m_window_height = height;
	glViewport(0, 0, width, height);
}
