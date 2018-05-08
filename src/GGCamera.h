#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "GGInput.h"

class GGCamera
{
public:
	GGCamera(GGInput& m_input);

public:
	glm::mat4 GetViewProj() const;

	void Update();
	void UpdateProj(float fov, float aspect, float near, float far);

private:
	glm::vec3 m_pos;
	glm::vec3 m_rot;
	glm::vec3 m_vel;
	glm::mat4 m_view;
	glm::mat4 m_proj;
};
