#pragma once

#include "GreatGine.h"
#include "GGChunk.h"
#include "GGMesh.h"

class GGChunkModel
{
public:
	GGChunkModel();

public:
	void Render();

private:
	GGMesh GenerateMesh();
	void GenerateVoxel(UINT x, UINT y, UINT z, const GGChunk& chunk, std::vector<GGMesh::GGVertex>& vertices, std::vector<GGMesh::GGIndex>& indices);

private:
	GGMesh m_mesh;
};
