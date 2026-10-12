#include"WorldGen.h"

float fade(float t)
{
	return ((6.0f * t - 15.0f) * t + 10.0f) * t * t * t;
}
float lerp(float t, float a1, float a2)
{
	return a1 + t * (a2 - a1);
}

int rand(glm::vec2 pos, unsigned int seed) 
{
	return ((unsigned int)(57127427.4759 + (int)(pos.x * 2587348.1345f) % 153462 + (int)(seed * 39596.5313f) % 136562 + (int)(pos.y * 46551.5777f) % 2456433) % RAND_MAX);
}

std::vector<int> WorldGen::perlin(glm::vec2 coords) 
{
	std::vector<int> heights(chunkLength*chunkWidth);
	std::fill(heights.begin(), heights.end(), 1);
	std::vector<glm::vec2> corners; // TOP LEFT -> TOP RIGHT -> BOTTOM LEFT -> BOTTOM RIGHT
	for (unsigned int i = 0; i < 2; i++) 
	{ 
		for (unsigned int j = 0; j < 2; j++) 
		{
			corners.push_back(glm::normalize(glm::vec2(((float)rand(coords + glm::vec2(i, j), seed) / (float)RAND_MAX) * 2.0f - 1.0f, ((float)rand(coords + glm::vec2(i, j), seed) / (float)RAND_MAX) * 2.0f - 1.0f)));
		}
	}
	for (unsigned int i = 0; i < chunkLength; i++)
	{
		for (unsigned int k = 0; k < chunkWidth; k++)
		{
			float xi = (float)i / (float)chunkLength;
			float yi = (float)k / (float)chunkWidth;
			if (i == 0 and k == 0)
			{
				xi = 0.1f;
				yi = 0.1f;
			}
			float height = lerp(fade(xi), 
				lerp(fade(yi),
					glm::dot(glm::normalize(glm::vec2(xi, yi)), corners[0]),
					glm::dot(glm::normalize(glm::vec2(xi, 1.0f - yi)), corners[1])), 
				lerp(fade(yi),
					glm::dot(glm::normalize(glm::vec2(1.0f - xi, yi)), corners[2]),
					glm::dot(glm::normalize(glm::vec2(1.0f - xi, 1.0f - yi)), corners[3])));
			heights[i * chunkWidth + k] = (int)((1.0f+height)*(float)chunkHeight/2.0f);
		}
	}
	
	return heights;
}

void WorldGen::Generate() 
{
	std::srand(seed);
	chunks.push_back(Chunk(glm::vec2(0.0f, 0.0f), perlin(glm::vec2(0.0f, 0.0f))));
	chunks.push_back(Chunk(glm::vec2(1.0f, 0.0f), perlin(glm::vec2(1.0f, 0.0f))));
	chunks.push_back(Chunk(glm::vec2(0.0f, 1.0f), perlin(glm::vec2(0.0f, 1.0f))));
	chunks.push_back(Chunk(glm::vec2(1.0f, 1.0f), perlin(glm::vec2(1.0f, 1.0f))));
}

void WorldGen::Draw(Shader& shader, Camera& camera) 
{
	for (Chunk chunk : chunks)
		chunk.Draw(shader, camera);
}