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
	void RegisterKeyHandler(std::function<void(int)>);

private:
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

private:
	double m_mouse_x;
	double m_mouse_y;
	std::vector<std::function<void(int)>> m_keyHandlers;
};
