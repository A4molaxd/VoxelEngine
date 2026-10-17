#pragma once

#include"Chunk.h"

class ChunkManager
{
public:
	
	std::vector<Chunk> loadedChunks;

	void Generate(unsigned int seed);
};