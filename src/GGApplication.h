#pragma once

#include "GGGraphics.h"
#include "GGInput.h"

class GLFWwindow;

class GGApplication
{
public:
	GGApplication();

public:
	void Run();

private:
	void Update();
	void Render();

	static GLFWwindow* CreateWindow();

private:
	GLFWwindow* m_window;
	GGGraphics m_graphics;
	GGInput m_input;
};
