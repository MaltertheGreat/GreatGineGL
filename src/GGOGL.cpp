#include "GGOGL.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

GGOGL::GGOGL()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		throw std::runtime_error("Failed to initialize GLAD");
	}
}
