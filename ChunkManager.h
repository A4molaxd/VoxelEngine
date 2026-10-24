#pragma once

#include"Chunk.h"

class ChunkManager
{
public:
	int renderDistance = 4;

	std::vector<Chunk> loadedChunks;

	void Generate(unsigned int seed);

	void Update();
};