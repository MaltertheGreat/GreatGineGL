#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>

#include "GreatGine.h"

class GGMesh
{
public:
	struct GGVertex
	{
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec3 tangent;
		glm::vec2 texture;
	};
	typedef UINT GGIndex;

public:
	GGMesh();
	GGMesh(const std::vector<GGVertex>& vertices, const std::vector<GGIndex>& indices);

public:
	void Render();

private:
	UINT m_vao;
	UINT m_index_count;
};
