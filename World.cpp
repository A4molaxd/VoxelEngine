#include"World.h"

void World::Draw(Shader& shader, Camera& camera)
{
	for (Chunk chunk : chunkManager.loadedChunks)
		chunk.Draw(shader, camera);

}

Cube World::GetCube(int x, int y, int z)
{

	return Cube(glm::vec3(x, y, z), BlockTypes::AIR);
}