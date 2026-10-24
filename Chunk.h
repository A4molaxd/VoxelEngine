#pragma once

#include"Cube.h"
#include"ChunkData.h"

class Chunk
{
public:
	glm::vec2 chunkCoords;

	std::vector<Cube> cubes;

	std::vector<std::vector<std::vector<int>>> occupied;

	Chunk(glm::vec2 chunkCoords, std::vector<int> chunkHeights);

	void Draw(Shader& shader, Camera& camera);

	void Update();
	
	void CalculateFaces(std::vector<std::vector<std::vector<int>>> occupied);

	void CalculateMeshes();

	void GreedyMeshing();

private:
	std::vector<Mesh> meshes;
};