#include "GGChunkModel.h"
#include "GGChunk.h"

GGChunkModel::GGChunkModel() :
	m_mesh(GenerateMesh())
{}

void GGChunkModel::Render()
{
	m_mesh.Render();
}

GGMesh GGChunkModel::GenerateMesh()
{
	std::vector<GGMesh::GGVertex> vertices;
	std::vector<GGMesh::GGIndex> indices;
	GGChunk chunk = GGChunk::GenetateRandom();

	for(UINT x = 0; x < GGChunk::DIAMETER; ++x)
	{
		for(UINT y = 0; y < GGChunk::DIAMETER; ++y)
		{
			for(UINT z = 0; z < GGChunk::DIAMETER; ++z)
			{
				GenerateVoxel(x, y, z, chunk, vertices, indices);
			}
		}
	}

	return GGMesh(vertices, indices);
}

void GGChunkModel::GenerateVoxel(UINT x, UINT y, UINT z, const GGChunk& chunk, std::vector<GGMesh::GGVertex>& vertices, std::vector<GGMesh::GGIndex>& indices)
{
	glm::uvec3 chunkDiameter = {GGChunk::DIAMETER, GGChunk::DIAMETER, GGChunk::DIAMETER};
	const glm::vec3 diameter =
	{
		1.0f / chunkDiameter.x,
		1.0f / chunkDiameter.y,
		1.0f / chunkDiameter.z,
	};
	//const float radius = diameter / 2.0f;
	const glm::vec3 radius =
	{
		diameter.x / 2.0f,
		diameter.y / 2.0f,
		diameter.z / 2.0f
	};
	//const float offset = -radius * static_cast<float>(biggestDiameter - 1);
	const glm::vec3 offset =
	{
		-radius.x * static_cast<float>(chunkDiameter.x - 1),
		-radius.y * static_cast<float>(chunkDiameter.y - 1),
		-radius.z * static_cast<float>(chunkDiameter.z - 1),
	};

	UINT voxelIndex = x * chunkDiameter.y * chunkDiameter.z + y * chunkDiameter.z + z;
	if( chunk.voxels[voxelIndex].element == 0 )
	{
		return;
	}

	glm::vec3 center = { offset.x + (x*diameter.x), offset.y + (y*diameter.y), offset.z + (z*diameter.z) };
	glm::vec3 color = {0.8f, 0.1f, 0.0f};

	// Right
	if( (x < (chunkDiameter.x - 1u) && (chunk.voxels[voxelIndex + (chunkDiameter.y * chunkDiameter.z)].element == 0)) || (x == (chunkDiameter.x - 1u)) )
	{
		UINT indexCount = static_cast<UINT>(vertices.size());
		vertices.push_back( { { center.x + radius.x, center.y - radius.y, center.z - radius.z }, { 1.0f, 0.0f, 0.0f }, color } );
		vertices.push_back( { { center.x + radius.x, center.y + radius.y, center.z - radius.z }, { 1.0f, 0.0f, 0.0f }, color } );
		vertices.push_back( { { center.x + radius.x, center.y + radius.y, center.z + radius.z }, { 1.0f, 0.0f, 0.0f }, color } );
		vertices.push_back( { { center.x + radius.x, center.y - radius.y, center.z + radius.z }, { 1.0f, 0.0f, 0.0f }, color } );

		indices.push_back( indexCount + 0 );
		indices.push_back( indexCount + 1 );
		indices.push_back( indexCount + 2 );

		indices.push_back( indexCount + 2 );
		indices.push_back( indexCount + 3 );
		indices.push_back( indexCount + 0 );
	}
	// Top
	if( (y < (chunkDiameter.y - 1u) && (chunk.voxels[voxelIndex + (chunkDiameter.z)].element == 0)) || (y == (chunkDiameter.y - 1u)) )
	{
		UINT indexCount = static_cast<UINT>(vertices.size());
		vertices.push_back( { { center.x - radius.x, center.y + radius.y, center.z - radius.z }, { 0.0f, 1.0f, 0.0f }, color } );
		vertices.push_back( { { center.x - radius.x, center.y + radius.y, center.z + radius.z }, { 0.0f, 1.0f, 0.0f }, color } );
		vertices.push_back( { { center.x + radius.x, center.y + radius.y, center.z + radius.z }, { 0.0f, 1.0f, 0.0f }, color } );
		vertices.push_back( { { center.x + radius.x, center.y + radius.y, center.z - radius.z }, { 0.0f, 1.0f, 0.0f }, color } );

		indices.push_back( indexCount + 0 );
		indices.push_back( indexCount + 1 );
		indices.push_back( indexCount + 2 );

		indices.push_back( indexCount + 2 );
		indices.push_back( indexCount + 3 );
		indices.push_back( indexCount + 0 );
	}

	// Back
	if( (z < (chunkDiameter.z - 1u) && (chunk.voxels[voxelIndex + 1].element == 0)) || (z == (chunkDiameter.z - 1u)) )
	{
		UINT indexCount = static_cast<UINT>(vertices.size());
		vertices.push_back( { { center.x + radius.x, center.y - radius.y, center.z + radius.z }, { 0.0f, 0.0f, 1.0f }, color } );
		vertices.push_back( { { center.x + radius.x, center.y + radius.y, center.z + radius.z }, { 0.0f, 0.0f, 1.0f }, color } );
		vertices.push_back( { { center.x - radius.x, center.y + radius.y, center.z + radius.z }, { 0.0f, 0.0f, 1.0f }, color } );
		vertices.push_back( { { center.x - radius.x, center.y - radius.y, center.z + radius.z }, { 0.0f, 0.0f, 1.0f }, color } );

		indices.push_back( indexCount + 0 );
		indices.push_back( indexCount + 1 );
		indices.push_back( indexCount + 2 );

		indices.push_back( indexCount + 2 );
		indices.push_back( indexCount + 3 );
		indices.push_back( indexCount + 0 );
	}

	// Left
	if( (x > 0 && (chunk.voxels[voxelIndex - (chunkDiameter.y * chunkDiameter.z)].element == 0)) || (x == 0) )
	{
		UINT indexCount = static_cast<UINT>(vertices.size());
		vertices.push_back( { { center.x - radius.x, center.y - radius.y, center.z + radius.z }, { -1.0f, 0.0f, 0.0f }, color } );
		vertices.push_back( { { center.x - radius.x, center.y + radius.y, center.z + radius.z }, { -1.0f, 0.0f, 0.0f }, color } );
		vertices.push_back( { { center.x - radius.x, center.y + radius.y, center.z - radius.z }, { -1.0f, 0.0f, 0.0f }, color } );
		vertices.push_back( { { center.x - radius.x, center.y - radius.y, center.z - radius.z }, { -1.0f, 0.0f, 0.0f }, color } );

		indices.push_back( indexCount + 0 );
		indices.push_back( indexCount + 1 );
		indices.push_back( indexCount + 2 );

		indices.push_back( indexCount + 2 );
		indices.push_back( indexCount + 3 );
		indices.push_back( indexCount + 0 );
	}

	// Bottom
	if( (y > 0 && (chunk.voxels[voxelIndex - chunkDiameter.z].element == 0)) || (y == 0) )
	{
		UINT indexCount = static_cast<UINT>(vertices.size());
		vertices.push_back( { { center.x - radius.x, center.y - radius.y, center.z + radius.z }, { 0.0f, -1.0f, 0.0f }, color } );
		vertices.push_back( { { center.x - radius.x, center.y - radius.y, center.z - radius.z }, { 0.0f, -1.0f, 0.0f }, color } );
		vertices.push_back( { { center.x + radius.x, center.y - radius.y, center.z - radius.z }, { 0.0f, -1.0f, 0.0f }, color } );
		vertices.push_back( { { center.x + radius.x, center.y - radius.y, center.z + radius.z }, { 0.0f, -1.0f, 0.0f }, color } );

		indices.push_back( indexCount + 0 );
		indices.push_back( indexCount + 1 );
		indices.push_back( indexCount + 2 );

		indices.push_back( indexCount + 2 );
		indices.push_back( indexCount + 3 );
		indices.push_back( indexCount + 0 );
	}

	// Front
	if( (z > 0 && (chunk.voxels[voxelIndex - 1].element == 0)) || (z == 0) )
	{
		UINT indexCount = static_cast<UINT>(vertices.size());
		vertices.push_back( { { center.x - radius.x, center.y - radius.y, center.z - radius.z }, { 0.0f, 0.0f, -1.0f }, color } );
		vertices.push_back( { { center.x - radius.x, center.y + radius.y, center.z - radius.z }, { 0.0f, 0.0f, -1.0f }, color } );
		vertices.push_back( { { center.x + radius.x, center.y + radius.y, center.z - radius.z }, { 0.0f, 0.0f, -1.0f }, color } );
		vertices.push_back( { { center.x + radius.x, center.y - radius.y, center.z - radius.z }, { 0.0f, 0.0f, -1.0f }, color } );

		indices.push_back( indexCount + 0 );
		indices.push_back( indexCount + 1 );
		indices.push_back( indexCount + 2 );

		indices.push_back( indexCount + 2 );
		indices.push_back( indexCount + 3 );
		indices.push_back( indexCount + 0 );
	}
}
