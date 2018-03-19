#include "GGGraphics.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

GGGraphics::GGGraphics(GLFWwindow* window)
{
	glfwSetFramebufferSizeCallback(window, FramebufferSize);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		throw std::runtime_error("Failed to initialize GLAD");
	}

	// Vertex array
	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);
	glBindVertexArray(m_vao);

	// Triangle vertex buffer
	float vertices[] =
	{
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void GGGraphics::Update()
{
}

void GGGraphics::Render(GLFWwindow* window)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	m_shader.Set();
	glBindVertexArray(m_vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glfwSwapBuffers(window);
}

void GGGraphics::FramebufferSize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
