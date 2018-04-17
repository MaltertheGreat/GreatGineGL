#pragma once

#include <vector>

#include "GGInputHandler.h"

class GLFWwindow;

class GGInput
{
public:
	GGInput(GLFWwindow* window);

public:
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

public:
	void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void RegisterKeyHandler(GGKeyHandler* handler);

private:
	double m_mouse_x;
	double m_mouse_y;
	std::vector<GGKeyHandler*> m_keyHandlers;
};
