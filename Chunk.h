#ifndef CLASS_CHUNK_H
#define CLASS_CHUNK_H

#include"Cube.h"

class Chunk
{
public:
	glm::vec2 chunkCoords;

	std::vector<Cube> cubes;
	std::vector<std::vector<std::vector<int>>> occupied;

	Chunk(glm::vec2 chunkCoords, std::vector<int> chunkHeights);

	void Draw(Shader& shader, Camera& camera);
	
	void CalculateFaces(std::vector<std::vector<std::vector<int>>> occupied);
};

#endif