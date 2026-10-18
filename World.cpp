#include"World.h"

void World::Draw(Shader& shader, Camera& camera) 
{
	for (Chunk chunk : chunkManager.loadedChunks)
		chunk.Draw(shader, camera);
}