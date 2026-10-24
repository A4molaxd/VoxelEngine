#include"ChunkData.h"

namespace ChunkData
{
	std::unordered_map<int, std::vector<Cube>> chunks;
	Cube GetCube(int x, int y, int z)
	{
		if (chunks.contains(floor(x / 16) * 100000 + floor(z / 16)))
		{
			return chunks[floor(x / 16) * 100000 + floor(z / 16)][CHUNK_SIZE * CHUNK_SIZE * (x % 16) + CHUNK_SIZE * y + (z % 16)];
		}
		else 
		{
			return Cube(glm::vec3(0, 0, 0), BlockTypes::AIR);
		}
	}
}