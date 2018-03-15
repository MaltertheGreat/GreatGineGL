#pragma once

#include "GGGraphics.h"

class GLFWwindow;

class GGApplication
{
public:
	GGApplication();

public:
	void Run();

private:
	void ProcessInput();
	void Update();
	void Render();

	static GLFWwindow* CreateWindow();

private:
	GLFWwindow* m_window;
	GGGraphics m_graphics;
};
