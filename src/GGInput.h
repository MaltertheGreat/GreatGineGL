#pragma once

#include <vector>
#include <functional>

#include "GGInputHandler.h"

class GLFWwindow;

class GGInput
{
public:
	GGInput(GLFWwindow* window);

public:
	void RegisterKeyPressedHandler(std::function<void(int)>);
	void RegisterKeyReleasedHandler(std::function<void(int)>);
	void RegisterMouseMoveHandler(std::function<void(double, double)>);

private:
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

private:
	double m_mouse_x;
	double m_mouse_y;
	std::vector<std::function<void(int)>> m_key_pressed_handlers;
	std::vector<std::function<void(int)>> m_key_released_handlers;;
	std::vector<std::function<void(double, double)>> m_mouse_moved_handlers;
};
