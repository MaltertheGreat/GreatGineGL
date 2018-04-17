#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

class GGCamera
{
public:
	glm::mat4 GetViewProj() const;

	void UpdateView(glm::vec3 position, glm::vec3 target);
	void UpdateProj(float fov, float aspect, float near, float far);

private:
	glm::mat4 m_view;
	glm::mat4 m_proj;
};
