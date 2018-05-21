#pragma once

#include <GGVoxel.h>

#include <array>

struct GGChunk
{
	static const UINT DIAMETER = 16;
	static const UINT VOLUME = DIAMETER * DIAMETER * DIAMETER;
	static GGChunk GenetateRandom();
	std::array<GGVoxel, VOLUME> voxels;
};
