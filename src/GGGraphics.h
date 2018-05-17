#pragma once

#include <memory>

#include "GGOGL.h"
#include "GGShader.h"
#include "GGCamera.h"
#include "GGMesh.h"

#include "GGChunkModel.h"

class GLFWwindow;

class GGGraphics
{
public:
	GGGraphics(GLFWwindow* window, GGInput& input);

public:
	void Update(GLFWwindow* window);
	void Render(GLFWwindow* window);

private:
	static void FramebufferSize(GLFWwindow* window, int width, int height);

private:
	GGOGL m_ogl;
	GGShader m_shader;
	GGCamera m_camera;
	GGMesh m_mesh;
	GGChunkModel m_chunk;
};
