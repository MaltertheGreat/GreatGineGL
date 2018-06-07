#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "GGInput.h"

class GGCamera
{
public:
	GGCamera(GGInput& m_input, glm::vec3 pos = {0.0f, 0.0f, 0.0f});

public:
	glm::mat4 GetViewProj() const;
	glm::vec3 GetPosition() const;

	void Update();
	void UpdateProj(float fov, float aspect, float near, float far);

private:
	glm::vec3 m_pos = {0.0f, 0.0f, 0.0f};
	glm::vec3 m_rot = {0.0f, 0.0f, 0.0f};
	glm::vec3 m_vel = {0.0f, 0.0f, 0.0f};
	glm::mat4 m_view;
	glm::mat4 m_proj;
};
