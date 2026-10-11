#ifndef BLOCK_TYPES_H
#define BLOCK_TYPES_H

#include"Mesh.h"

enum BlockTypes
{
	GRASS_BLOCK,
	DIRT_BLOCK,
	COUNT
};

extern std::vector<Texture> BlockType[BlockTypes::COUNT];

void InitBlockTypes();

#endif