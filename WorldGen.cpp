#include"WorldGen.h"

float fade(float t)
{
	return ((6.0f * t - 15.0f) * t + 10.0f) * t * t * t;
}
float lerp(float t, float a1, float a2)
{
	return a1 + t * (a2 - a1);
}

std::vector<int> WorldGen::perlin(glm::vec2 coords) 
{
	std::vector<int> heights(chunkLength*chunkWidth);
	std::fill(heights.begin(), heights.end(), 1);
	std::vector<glm::vec2> corners;
	for (unsigned int i = 0; i < 4; i++) // TOP LEFT -> TOP RIGHT -> BOTTOM LEFT -> BOTTOM RIGHT
		corners.push_back(glm::normalize(glm::vec2(((float)std::rand() / (float)RAND_MAX) * 2.0f - 1.0f, ((float)std::rand() / (float)RAND_MAX) * 2.0f - 1.0f)));
	
	for (unsigned int i = 0; i < chunkLength; i++)
	{
		for (unsigned int k = 0; k < chunkWidth; k++)
		{
			float xi = (float)i / (float)chunkLength;
			float yi = (float)k / (float)chunkWidth;
			if (i == 0 and k == 0)
			{
				yi = 0.00000001f;
				xi = 0.00000001f;
			}
			float height = lerp(fade(xi), 
				lerp(fade(yi),
					glm::dot(glm::normalize(glm::vec2(xi, yi)), corners[2]),
					glm::dot(glm::normalize(glm::vec2(xi, 1.0f - yi)), corners[0])), 
				lerp(fade(yi),
					glm::dot(glm::normalize(glm::vec2(1.0f - xi, yi)), corners[3]),
					glm::dot(glm::normalize(glm::vec2(1.0f - xi, 1.0f - yi)), corners[1])));
			heights[i * chunkWidth + k] = (int)((1.0f+height)*(float)chunkHeight/2.0f);
		}
	}
	
	return heights;
}

void WorldGen::Generate() 
{
	std::srand(seed);
	chunks.push_back(Chunk(glm::vec2(0.0f, 0.0f), perlin(glm::vec2(0.0f, 0.0f))));
}

void WorldGen::Draw(Shader& shader, Camera& camera) 
{
	for (Chunk chunk : chunks)
		chunk.Draw(shader, camera);
}