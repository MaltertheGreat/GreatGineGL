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
	};

public:
	GGMesh();
	//GGMesh(std::vector<GGVertex> vertices, std::vector<UINT> indices);

public:
	void Render();

private:
	UINT m_vao;
	UINT m_index_count;
};
