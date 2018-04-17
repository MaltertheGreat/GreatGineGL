#pragma once

#include "GGGraphics.h"
#include "GGInput.h"

class GLFWwindow;

class GGApplication : public GGKeyHandler
{
public:
	GGApplication();

public:
	void Run();

protected:
	virtual void KeyPressed(int key) override;

private:
	void Update();
	void Render();

	static GLFWwindow* CreateWindow();

private:
	GLFWwindow* m_window;
	GGGraphics m_graphics;
	GGInput m_input;
};
