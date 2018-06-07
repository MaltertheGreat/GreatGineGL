#pragma once

#include <memory>

#include "GGOGL.h"
#include "GGShader.h"
#include "GGCamera.h"
#include "GGMesh.h"
#include "GGTexture.h"

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
	GGTexture m_texture;
	GGTexture m_normal_map;
	GGChunkModel m_chunk;
	GGMesh m_test_mesh;
};
