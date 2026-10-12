#include"Chunk.h"

void Chunk::CalculateFaces(std::vector<std::vector<std::vector<int>>> occupied)
{
	int counter = 0;
	for (unsigned int i = 0; i < chunkWidth; i++)
	{
		for (unsigned int j = 0; j < chunkHeight; j++)
		{
			for (unsigned int k = 0; k < chunkLength; k++)
			{
				if (occupied[i][j][k])
				{
					if (i + 1 < chunkWidth) if (occupied[i + 1][j][k]) cubes[counter].ocludedFaces[0] = false;
					if (i - 1 < chunkWidth) if (occupied[i - 1][j][k]) cubes[counter].ocludedFaces[1] = false;
					if (j + 1 < chunkWidth) if (occupied[i][j + 1][k]) cubes[counter].ocludedFaces[2] = false;
					if (j - 1 < chunkWidth) if (occupied[i][j - 1][k]) cubes[counter].ocludedFaces[3] = false;
					if (k + 1 < chunkWidth) if (occupied[i][j][k + 1]) cubes[counter].ocludedFaces[4] = false;
					if (k - 1 < chunkWidth) if (occupied[i][j][k - 1]) cubes[counter].ocludedFaces[5] = false;
					counter++;
				}
			}
		}
	}

}

Chunk::Chunk(glm::vec2 chunkCoords)
{
	Chunk::chunkCoords = chunkCoords;
	std::vector<std::vector<std::vector<int>>> occupied(chunkWidth+1, std::vector<std::vector<int>>(chunkHeight+1, std::vector<int>(chunkLength+1, false)));

	for (unsigned int i = 0; i < chunkWidth; i++)
	{
		for (unsigned int j = 0; j < chunkHeight; j++)
		{
			for (unsigned int k = 0; k < chunkLength; k++)
			{
				if (i == chunkHeight-1 and j == 4 and k == 5) continue;
				BlockTypes type = i == chunkHeight-1 ? BlockTypes::GRASS_BLOCK : BlockTypes::DIRT_BLOCK;
				cubes.push_back(Cube(glm::vec3(chunkCoords.x * chunkLength + j, i, chunkCoords.y * chunkWidth + k), type));
				occupied[i][j][k] = 1;
			}
		}
	}
	CalculateFaces(occupied);
}

void Chunk::Draw(Shader& shader, Camera& camera)
{
	for (Cube cube : cubes)
		cube.Draw(shader, camera);
}