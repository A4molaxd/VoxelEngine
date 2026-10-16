#ifndef WORLD_GEN_CLASS_H
#define WORLD_GEN_CLASS_H

#include"Chunk.h"
#include<numbers>

class WorldGen
{
public:
	const unsigned int seed = 134;

	std::vector<Chunk> chunks;
	
	void Generate();

	void Draw(Shader& shader, Camera& camera);
};


#endif