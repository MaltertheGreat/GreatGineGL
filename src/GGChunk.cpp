#include "GGChunk.h"

#include <random>

GGChunk GGChunk::GenetateRandom()
{
	std::random_device dev;
	std::bernoulli_distribution dist(0.35);

	GGChunk chunk;
	for (auto& voxel : chunk.voxels)
	{
		if (dist(dev))
			voxel.element = 1;
	}

	return chunk;
}
GGChunk GGChunk::GenetateFull()
{
	GGChunk chunk;
	for (auto& voxel : chunk.voxels)
	{
		voxel.element = 1;
	}

	return chunk;
}
