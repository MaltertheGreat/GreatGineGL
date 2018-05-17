#pragma once

#include "GreatGine.h"
#include "GGVoxel.h"
#include "GGMesh.h"

class GGChunkModel
{
public:
	GGChunkModel();

public:
	void Render();

private:
	GGMesh GenerateMesh();
	void GenerateVoxel(UINT x, UINT y, UINT z, const std::vector<GGVoxel>& voxels, std::vector<GGMesh::GGVertex>& vertices, std::vector<GGMesh::GGIndex>& indices);

private:
	const UINT DIAMETER = 16;
	GGMesh m_mesh;
};
