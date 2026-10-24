#pragma once

#include"ChunkManager.h"

using namespace ChunkData;

class World
{
public:
	const unsigned int seed = 134;

	ChunkManager chunkManager;

	void Draw(Shader& shader, Camera& camera);
};