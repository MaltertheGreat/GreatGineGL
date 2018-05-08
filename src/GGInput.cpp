#include "GGInput.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

GGInput::GGInput(GLFWwindow* window)
{
	glfwSetWindowUserPointer(window, this);
	glfwSetKeyCallback(window, GGInput::key_callback);
	glfwSetCursorPosCallback(window, GGInput::cursor_position_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwGetCursorPos(window, &m_mouse_x, &m_mouse_y);
}

void GGInput::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	GGInput* input = static_cast<GGInput*>(glfwGetWindowUserPointer(window));

	std::cerr << key << std::endl;
	if (action == GLFW_PRESS)
		for (auto& handler : input->m_key_pressed_handlers)
			handler(key);
	else if (action == GLFW_RELEASE)
		for (auto& handler : input->m_key_released_handlers)
			handler(key);
		return;
}

void GGInput::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	GGInput* input = static_cast<GGInput*>(glfwGetWindowUserPointer(window));

	double xoffset = xpos - input->m_mouse_x;
	double yoffset = input->m_mouse_y - ypos;

	input->m_mouse_x = xpos;
	input->m_mouse_y = ypos;

	for (auto& handler : input->m_mouse_moved_handlers)
		handler(xoffset, yoffset);
}
void GGInput::RegisterKeyPressedHandler(std::function<void(int)> handler)
{
	m_key_pressed_handlers.push_back(handler);
}

void GGInput::RegisterKeyReleasedHandler(std::function<void(int)> handler)
{
	m_key_released_handlers.push_back(handler);
}


void GGInput::RegisterMouseMoveHandler(std::function<void(double, double)> handler)
{
	m_mouse_moved_handlers.push_back(handler);
}
