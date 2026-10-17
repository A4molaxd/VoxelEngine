#include"World.h"

void World::Draw(Shader& shader, Camera& camera) 
{
	// TODO: render distance and render only visible chunks for the player;
	for (Chunk chunk : chunkManager.loadedChunks)
		chunk.Draw(shader, camera);
}