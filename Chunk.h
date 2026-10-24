#pragma once

#include"Cube.h"
#include"ChunkData.h"

class Chunk
{
public:
	glm::vec2 chunkCoords;

	std::vector<Cube> cubes;

	Chunk(glm::vec2 chunkCoords, std::vector<int> chunkHeights);

	void Draw(Shader& shader, Camera& camera);

	void Update();
	
	void CalculateFaces();

	void CalculateMeshes();

private:
	std::vector<Mesh> meshes;
};