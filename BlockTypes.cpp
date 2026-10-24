#include "BlockTypes.h"

std::vector<Texture> BlockType[BlockTypes::COUNT];

void InitBlockTypes()
{
    BlockType[AIR] = {

    };

    BlockType[GRASS_BLOCK] = {
        Texture("grassBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("dirtBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("grassBlockSide.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("grassBlockSide.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("grassBlockSide.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("grassBlockSide.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE)
    };

    BlockType[DIRT_BLOCK] = {
        Texture("dirtBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("dirtBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("dirtBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("dirtBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("dirtBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("dirtBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE)
    };

    BlockType[SAND_BLOCK] = {
        Texture("sandBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("sandBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("sandBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("sandBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("sandBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("sandBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE)
    };

    BlockType[STONE_BLOCK] = {
        Texture("stoneBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("stoneBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("stoneBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("stoneBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("stoneBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
        Texture("stoneBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE)
    };
}