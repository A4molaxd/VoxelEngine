#include"Chunk.h"
#include"Constants.h"

Chunk::Chunk(glm::vec2 chunkCoords)
{
	Chunk::chunkCoords = chunkCoords;

	for (unsigned int i = 0; i < chunkHeight; i++) 
	{
		for (unsigned int j = 0; j < chunkWidth; j++)
		{
			for (unsigned int k = 0; k < chunkLength; k++)
			{
				cubes.push_back(Cube(glm::vec3(chunkCoords.x * chunkLength + j, i, chunkCoords.y * chunkWidth + k)));
			}
		}
	}
}

void Chunk::Draw(Shader& shader, Camera& camera)
{
	for (Cube cube : cubes)
		cube.Draw(shader, camera);
}