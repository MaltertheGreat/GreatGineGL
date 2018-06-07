#include <GGMesh.h>

GGMesh::GGMesh()
{
	// Vertex buffer
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	UINT vbo;
	glGenBuffers(1, &vbo);
	UINT ebo;
	glGenBuffers(1, &ebo);

	std::vector<GGVertex> vertices = {
		{{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, -1.0f}, {-1.0f, 0.0f, 0.0f}, {1.0f, 1.0f}}, // top right
		{{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, -1.0f}, {-1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}}, // bottom right
		{{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, -1.0f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}}, // bottom left
		{{-0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, -1.0f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}} // top left
	};

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GGVertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

	std::vector<UINT> indices = {
		0, 1, 3, // first triangle
		1, 2, 3 // second triangle
	};

	m_index_count = indices.size();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(UINT) * indices.size(), indices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GGVertex), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GGVertex), reinterpret_cast<void*>(sizeof(glm::vec3)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(GGVertex), reinterpret_cast<void*>(2 * sizeof(glm::vec3)));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(GGVertex), reinterpret_cast<void*>(3 * sizeof(glm::vec3)));
	glEnableVertexAttribArray(3);
}

GGMesh::GGMesh(const std::vector<GGVertex>& vertices, const std::vector<GGIndex>& indices)
{
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);
	UINT vbo;
	glGenBuffers(1, &vbo);
	UINT ebo;
	glGenBuffers(1, &ebo);

	// Vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GGVertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

	// Index buffer
	m_index_count = indices.size();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GGIndex) * indices.size(), indices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GGVertex), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GGVertex), reinterpret_cast<void*>(sizeof(glm::vec3)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(GGVertex), reinterpret_cast<void*>(2 * sizeof(glm::vec3)));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(GGVertex), reinterpret_cast<void*>(3 * sizeof(glm::vec3)));
	glEnableVertexAttribArray(3);
}

void GGMesh::Render()
{
	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, m_index_count, GL_UNSIGNED_INT, 0);
}
