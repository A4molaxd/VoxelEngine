#ifndef WORLD_GEN_CLASS_H
#define WORLD_GEN_CLASS_H

#include"Chunk.h"

class WorldGen
{
public:
	unsigned int seed = 134;

	std::vector<Chunk> chunks;

	std::vector<int> perlin(glm::vec2 coords);
	
	void Generate();

	void Draw(Shader& shader, Camera& camera);
};


#endif