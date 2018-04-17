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
		{{0.5f, 0.5f, 0.5f}}, // top right
		{{0.5f, -0.5f, 0.0f}}, // bottom right
		{{-0.5f, -0.5f, 0.0f}}, // bottom left
		{{-0.5f, 0.5f, -0.5f}} // top left
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void GGMesh::Render()
{
	glBindVertexArray(m_vao);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, m_index_count, GL_UNSIGNED_INT, 0);
}
