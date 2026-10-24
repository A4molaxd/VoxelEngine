#pragma once

#include"ChunkManager.h"

class World
{
public:
	const unsigned int seed = 134;

	ChunkManager chunkManager;

	void Draw(Shader& shader, Camera& camera);

	Cube GetCube(int x, int y, int z);
};