#include "GGCamera.h"

#include <glm/gtc/matrix_transform.hpp>

glm::mat4 GGCamera::GetViewProj() const
{
	return m_proj * m_view;
}

void GGCamera::UpdateView(glm::vec3 position, glm::vec3 rotation)
{
	m_view = glm::translate(glm::mat4(), position);

	glm::vec3 front = {
		sin(rotation.y)*cos(rotation.x),
		sin(rotation.x),
		cos(rotation.y)*cos(rotation.x)};
	front = glm::normalize(front);

	m_view = glm::lookAtLH(position, position + front, {0.0f, 1.0f, 0.0f});
}

void GGCamera::UpdateProj(float fov, float aspect, float near, float far)
{
	m_proj = glm::perspectiveLH(glm::radians(fov), aspect, near, far);
}
