#include"ChunkManager.h"

using namespace ChunkData;

float fade(float t)
{
	return ((6.0f * t - 15.0f) * t + 10.0f) * t * t * t;
}
float lerp(float t, float a1, float a2)
{
	return a1 + t * (a2 - a1);
}
float rand(glm::vec2 pos, unsigned int seed)
{
	float r = (pos.x + 41.1) * std::numbers::pi * 177.277 + (pos.y + 19.5) * std::numbers::e * 157.765 + (seed + 91.5) * std::numbers::phi * 986.422;
	return r - floor(r);
}
float rand2(glm::vec2 pos, unsigned int seed)
{
	float r = (pos.x + 12.3) * std::numbers::phi * 148.184 + (pos.y + 39.1) * std::numbers::pi * 139.361 + (seed + 98.2) * std::numbers::egamma * 158.827;
	return r - floor(r);
}
float clamp(float v, float a, float b)
{
	return std::max(a, std::min(b, v));
}

std::vector<float> perlin(glm::vec2 coords, unsigned int seed)
{
	std::vector<float> values(CHUNK_SIZE * CHUNK_SIZE);
	std::fill(values.begin(), values.end(), 1.0f);
	std::vector<glm::vec2> corners; // TOP LEFT -> TOP RIGHT -> BOTTOM LEFT -> BOTTOM RIGHT
	for (unsigned int i = 0; i < 2; i++)
	{
		for (unsigned int j = 0; j < 2; j++)
		{
			corners.push_back(glm::vec2(((float)rand(coords + glm::vec2(i, j), seed) * 2.0f - 1.0f, ((float)rand2(coords + glm::vec2(i, j), seed) * 2.0f - 1.0f))));
		}
	}
	for (unsigned int i = 0; i < CHUNK_SIZE; i++)
	{
		for (unsigned int k = 0; k < CHUNK_SIZE; k++)
		{
			float xi = (float)i / (float)CHUNK_SIZE;
			float yi = (float)k / (float)CHUNK_SIZE;
			if (i == 0 && k == 0)
			{
				xi = 0.001f;
				yi = 0.001f;
			}
			// Deleting glm::normalize() smooth things out too much
			float value = lerp(fade(xi),
				lerp(fade(yi),
					glm::dot(glm::normalize(glm::vec2(xi, yi)), corners[0]),
					glm::dot(glm::normalize(glm::vec2(xi, 1.0f - yi)), corners[1])),
				lerp(fade(yi),
					glm::dot(glm::normalize(glm::vec2(1.0f - xi, yi)), corners[2]),
					glm::dot(glm::normalize(glm::vec2(1.0f - xi, 1.0f - yi)), corners[3])));
			values[i * CHUNK_SIZE + k] = clamp(value, -1.0f, 1.0f);
		}
	}

	return values; // [-1.0f, 1.0f]
}

std::vector<int> terrainHeight(std::vector<float> perlin)
{
	// Change from [-1.0f, 1.0f] to integer world heights
	std::vector<int> heights(CHUNK_SIZE * CHUNK_SIZE);
	std::fill(heights.begin(), heights.end(), 1);
	for (unsigned int i = 0; i < CHUNK_SIZE * CHUNK_SIZE; i++)
	{
		heights[i] = round(((perlin[i] + 1.0f) * (float)(CHUNK_SIZE - 3) / 2.0f));
	}
	return heights;
}

void ChunkManager::Generate(unsigned int seed)
{
	// TODO: render distance and render only visible chunks for the player;

	loadedChunks.push_back(Chunk(glm::vec2(0.0f, 0.0f), terrainHeight(perlin(glm::vec2(0.0f, 0.0f), seed))));
	loadedChunks.push_back(Chunk(glm::vec2(0.0f, 1.0f), terrainHeight(perlin(glm::vec2(0.0f, 1.0f), seed))));
	loadedChunks.push_back(Chunk(glm::vec2(0.0f, -1.0f), terrainHeight(perlin(glm::vec2(0.0f, -1.0f), seed))));
	loadedChunks.push_back(Chunk(glm::vec2(0.0f, 2.0f), terrainHeight(perlin(glm::vec2(0.0f, 2.0f), seed))));

	loadedChunks.push_back(Chunk(glm::vec2(1.0f, 0.0f), terrainHeight(perlin(glm::vec2(1.0f, 0.0f), seed))));
	loadedChunks.push_back(Chunk(glm::vec2(1.0f, 1.0f), terrainHeight(perlin(glm::vec2(1.0f, 1.0f), seed))));
	loadedChunks.push_back(Chunk(glm::vec2(1.0f, -1.0f), terrainHeight(perlin(glm::vec2(1.0f, -1.0f), seed))));
	loadedChunks.push_back(Chunk(glm::vec2(1.0f, 2.0f), terrainHeight(perlin(glm::vec2(1.0f, 2.0f), seed))));

	loadedChunks.push_back(Chunk(glm::vec2(-1.0f, 1.0f), terrainHeight(perlin(glm::vec2(-1.0f, 1.0f), seed))));
	loadedChunks.push_back(Chunk(glm::vec2(-1.0f, 0.0f), terrainHeight(perlin(glm::vec2(-1.0f, 0.0f), seed))));
	loadedChunks.push_back(Chunk(glm::vec2(-1.0f, -1.0f), terrainHeight(perlin(glm::vec2(-1.0f, -1.0f), seed))));
	loadedChunks.push_back(Chunk(glm::vec2(-1.0f, 2.0f), terrainHeight(perlin(glm::vec2(-1.0f, 2.0f), seed))));

	for (int i = 0; i < loadedChunks.size(); i++)
	{
		//chunks[i] = loadedChunks[i].cubes;
		chunks[(loadedChunks[i].chunkCoords.x * 1000 + loadedChunks[i].chunkCoords.y)] = loadedChunks[i].cubes;
	}
}

void ChunkManager::Update()
{
	for (int i = 0; i < loadedChunks.size(); i++)
	{
		loadedChunks[i].Update();
		//chunks[(int) (loadedChunks[i].chunkCoords.x * 10000 + loadedChunks[i].chunkCoords.y)] = loadedChunks[i].cubes;
	}
}