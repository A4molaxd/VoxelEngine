#include"World.h"

void World::Draw(Shader& shader, Camera& camera)
{
	for (Chunk chunk : chunkManager.loadedChunks)
		chunk.Draw(shader, camera);

}

Cube World::GetCube(int x, int y, int z)
{
	return chunks[floor(x/16) * 1000 + floor(z/16)][CHUNK_SIZE * CHUNK_SIZE * (x%16) + CHUNK_SIZE * y + (z%16)];
}