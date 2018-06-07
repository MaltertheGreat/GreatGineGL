#include "GGCamera.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

GGCamera::GGCamera(GGInput& input, glm::vec3 pos) :
	m_pos(pos)
{
	float speed = 0.02f;
	auto key_pressed_handler = [this, speed](int key) {
		m_vel = {0.0f, 0.0f, 0.0f};
		if (key == GLFW_KEY_W)
			m_vel.z = speed;
		else if (key == GLFW_KEY_S)
			m_vel.z = -speed;

		if (key == GLFW_KEY_D)
			m_vel.x = speed;
		else if (key == GLFW_KEY_A)
			m_vel.x = -speed;

		if (key == GLFW_KEY_LEFT_CONTROL)
			m_vel.y = speed;
		else if (key == GLFW_KEY_LEFT_SHIFT)
			m_vel.y = -speed;
	};

	auto key_released_handler = [this](int key) {
		m_vel = {0.0f, 0.0f, 0.0f};
		if (key == GLFW_KEY_W)
			m_vel.z = 0.0f;
		else if (key == GLFW_KEY_S)
			m_vel.z = 0.0f;

		if (key == GLFW_KEY_D)
			m_vel.x = 0.0f;
		else if (key == GLFW_KEY_A)
			m_vel.x = 0.0f;

		if (key == GLFW_KEY_LEFT_CONTROL)
			m_vel.y = 0.0f;
		else if (key == GLFW_KEY_LEFT_SHIFT)
			m_vel.y = 0.0f;
	};

	auto mouse_moved_handler = [this](double x, double y)
	{
		double scale = 0.001;
		m_rot.y += x * scale;
		if (m_rot.y >  2.0f * glm::pi<float>())
			m_rot.y -= (2.0f * glm::pi<float>());
		if (m_rot.y < 0.0f)
			m_rot.y = (2.0f * glm::pi<float>()) + m_rot.y;
		m_rot.x += y * scale;
		if (m_rot.x > (0.5f * glm::pi<float>()))
			m_rot.x = (0.5f * glm::pi<float>());
		if (m_rot.x < -(0.5f * glm::pi<float>()))
			m_rot.x = -(0.5f * glm::pi<float>());
	};

	input.RegisterKeyPressedHandler(key_pressed_handler);
	input.RegisterKeyReleasedHandler(key_released_handler);
	input.RegisterMouseMoveHandler(mouse_moved_handler);
}

glm::vec3 GGCamera::GetPosition() const
{
	return m_pos;
}

glm::mat4 GGCamera::GetViewProj() const
{
	return m_proj * m_view;
}

void GGCamera::Update()
{
	glm::vec3 front = {
		cos(m_rot.x)*sin(m_rot.y),
		sin(m_rot.x),
		cos(m_rot.x)*cos(m_rot.y)};
	front = glm::normalize(front);
	glm::vec3 up = {
		-sin(m_rot.x)*sin(m_rot.y),
		cos(m_rot.x),
		-sin(m_rot.x)*cos(m_rot.y)};
	up = glm::normalize(up);
	glm::vec3 right = glm::cross(up, front);
	right = glm::normalize(right);

	m_pos += m_vel.x*right;
	m_pos += m_vel.y*up;
	m_pos += m_vel.z*front;

	/*front.x *= cos(m_rot.x);
	front.y = sin(m_rot.x);
	front.z *= cos(m_rot.x);
	front = glm::normalize(front);*/

	m_view = glm::lookAtLH(m_pos, m_pos + front, up);
}

void GGCamera::UpdateProj(float fov, float aspect, float near, float far)
{
	m_proj = glm::perspectiveLH(glm::radians(fov), aspect, near, far);
}
