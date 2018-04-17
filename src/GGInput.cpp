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
		for (auto& handler : input->m_keyHandlers)
			handler->KeyPressed(key);
	else if (action == GLFW_RELEASE)
		return;
}

void GGInput::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	std::cerr << "ok!" << std::endl;
	GGInput* input = static_cast<GGInput*>(glfwGetWindowUserPointer(window));

	double  xoffset = xpos - input->m_mouse_x;
	double yoffset = input->m_mouse_y - ypos;

	std::cerr << xoffset << ", " << yoffset << std::endl;

	input->m_mouse_x = xpos;
	input->m_mouse_y = ypos;
}

void GGInput::RegisterKeyHandler(GGKeyHandler* handler)
{
	m_keyHandlers.push_back(handler);
}
