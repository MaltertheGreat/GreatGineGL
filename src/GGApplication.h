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
	GGInput m_input;
	GGGraphics m_graphics;
};
