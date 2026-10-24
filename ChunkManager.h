#pragma once

#include"Chunk.h"

class ChunkManager
{
public:
	int renderDistance = 2;

	std::vector<Chunk> loadedChunks;

	void Generate(unsigned int seed);

	void Update();
};