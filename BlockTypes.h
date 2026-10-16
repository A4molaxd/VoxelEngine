#pragma once

#include"Mesh.h"

enum BlockTypes
{
	AIR,
	GRASS_BLOCK,
	DIRT_BLOCK,
	COUNT
};

extern std::vector<Texture> BlockType[BlockTypes::COUNT];

void InitBlockTypes();