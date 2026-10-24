#include"Chunk.h"

using namespace ChunkData;

void Chunk::CalculateFaces(std::vector<std::vector<std::vector<int>>> occupied)
{
	for (int i = 0; i < CHUNK_SIZE; i++)
	{
		for (int j = 0; j < CHUNK_SIZE; j++)
		{
			for (int k = 0; k < CHUNK_SIZE; k++)
			{
				if (cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].type != BlockTypes::AIR)
				{
					if (cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[2] != false)
					{
						if (i + 1 < CHUNK_SIZE)
						{
							if (cubes[CHUNK_SIZE * CHUNK_SIZE * (i + 1) + CHUNK_SIZE * j + k].type != BlockTypes::AIR)
							{
								cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[2] = false;
								cubes[CHUNK_SIZE * CHUNK_SIZE * (i + 1) + CHUNK_SIZE * j + k].ocludedFaces[3] = false;
							}
						}
						else
						{
							if (chunks.contains((chunkCoords.x + 1) * 1000 + chunkCoords.y))
							{
								if (chunks.at((chunkCoords.x + 1) * 1000 + chunkCoords.y)[CHUNK_SIZE * j + k].type != BlockTypes::AIR)
								{
									cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[2] = false;
									chunks.at((chunkCoords.x + 1) * 1000 + chunkCoords.y)[CHUNK_SIZE * j + k].ocludedFaces[3] = false;
								}
							}
						}
					}
					if (cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[3] != false)
					{
						if (i - 1 >= 0)
						{
							if (cubes[CHUNK_SIZE * CHUNK_SIZE * (i - 1) + CHUNK_SIZE * j + k].type != BlockTypes::AIR)
							{
								cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[3] = false;
								cubes[CHUNK_SIZE * CHUNK_SIZE * (i - 1) + CHUNK_SIZE * j + k].ocludedFaces[2] = false;
							}
						}
						else
						{
							if (chunks.contains((chunkCoords.x - 1) * 1000 + chunkCoords.y))
							{
								if (chunks.at((chunkCoords.x - 1) * 1000 + chunkCoords.y)[CHUNK_SIZE * CHUNK_SIZE * (CHUNK_SIZE - 1) + CHUNK_SIZE * j + k].type != BlockTypes::AIR)
								{
									cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[3] = false;
									chunks.at((chunkCoords.x - 1) * 1000 + chunkCoords.y)[CHUNK_SIZE * CHUNK_SIZE * (CHUNK_SIZE - 1) + CHUNK_SIZE * j + k].ocludedFaces[2] = false;
								}
							}
						}
					}
					if (cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[0] != false)
					{
						if (j + 1 < CHUNK_SIZE)
						{
							if (cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * (j + 1) + k].type != BlockTypes::AIR)
							{
								cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[0] = false;
								cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * (j + 1) + k].ocludedFaces[1] = false;
							}
						}
					}
					if (cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[1] != false)
					{
						if (j - 1 >= 0)
						{
							if (cubes[i + CHUNK_SIZE * (j - 1) + CHUNK_SIZE * CHUNK_SIZE * k].type != BlockTypes::AIR)
							{
								cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[1] = false;
								cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * (j - 1) +k].ocludedFaces[0] = false;
							}
						}
					}
					if (cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[4] != false)
					{
						if (k + 1 < CHUNK_SIZE)
						{
							if (cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + (k + 1)].type != BlockTypes::AIR)
							{
								cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[4] = false;
								cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + (k + 1)].ocludedFaces[5] = false;
							}
						}
						else
						{
							if (chunks.contains(chunkCoords.x * 1000 + (chunkCoords.y + 1)))
							{
								if (chunks.at(chunkCoords.x * 1000 + (chunkCoords.y + 1))[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j].type != BlockTypes::AIR)
								{
									cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[4] = false;
									chunks.at(chunkCoords.x * 1000 + (chunkCoords.y + 1))[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j].ocludedFaces[5] = false;
								}
							}
						}
					}
					if (cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[5] != false)
					{
						if (k - 1 >= 0)
						{
							if (cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + (k - 1)].type != BlockTypes::AIR)
							{
								cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[5] = false;
								cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + (k - 1)].ocludedFaces[4] = false;
							}
						}
						else
						{
							if (chunks.contains(chunkCoords.x * 1000 + (chunkCoords.y - 1)))
							{
								if (chunks.at(chunkCoords.x * 1000 + (chunkCoords.y - 1))[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + (CHUNK_SIZE - 1)].type != BlockTypes::AIR)
								{
									cubes[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + k].ocludedFaces[5] = false;
									chunks.at(chunkCoords.x * 1000 + (chunkCoords.y - 1))[CHUNK_SIZE * CHUNK_SIZE * i + CHUNK_SIZE * j + (CHUNK_SIZE - 1)].ocludedFaces[4] = false;
								}
							}
						}
					}
				}
			}
		}
	}
}

void Chunk::CalculateMeshes()
{
	// This implementation does not support block rotations
	std::vector<std::vector<Vertex>> vertices;
	std::vector<std::vector<GLuint>> indices;
	std::vector<std::vector<Texture>> textures;
	std::vector<int> ind;
	for (unsigned int type = 1; type < BlockTypes::COUNT; type++)
	{
		vertices.clear();
		indices.clear();
		textures.clear();
		ind.clear();
		for (Cube cube : cubes)
		{
			if (cube.type == type)
			{
				// Get every visible face in the cube
				for (unsigned int i = 0; i < cube.textures.size(); i++)
				{
					if (cube.ocludedFaces[i]) {
						// Check where its normal points to classify it
						int t = -1;
						for (unsigned int v = 0; v < vertices.size(); v++)
						{
							if (cube.vertices[i][0].normal == vertices[v][0].normal) {
								t = v;
							}
						}
						// If the normal is not already on a sublist, create a new sublist
						if (t == -1) {
							t = (int)vertices.size();
							vertices.push_back(std::vector<Vertex>());
							indices.push_back(std::vector<GLuint>());
							textures.push_back(cube.textures[i]);
							ind.push_back(0);
						}
						// Add their vertices and indices to the list they belong to
						for (unsigned int j = 0; j < 4; j++)
						{
							vertices[t].push_back(cube.vertices[i][j]);
						}
						// Checks if it is the top face and changes the rotation of the indices for the face culling
						if (cube.vertices[i][0].normal == glm::vec3(0.0f, 1.0f, 0.0f))
						{
							indices[t].push_back(0 + ind[t]);
							indices[t].push_back(2 + ind[t]);
							indices[t].push_back(1 + ind[t]);
							indices[t].push_back(0 + ind[t]);
							indices[t].push_back(3 + ind[t]);
							indices[t].push_back(2 + ind[t]);
						}
						else
						{
							indices[t].push_back(0 + ind[t]);
							indices[t].push_back(1 + ind[t]);
							indices[t].push_back(2 + ind[t]);
							indices[t].push_back(0 + ind[t]);
							indices[t].push_back(2 + ind[t]);
							indices[t].push_back(3 + ind[t]);
						}
						ind[t] += 4;
					}
				}
			}
		}
		for (unsigned int tex = 0; tex < textures.size(); tex++)
		{
			Chunk::meshes.push_back(Mesh(vertices[tex], indices[tex], textures[tex]));
		}
	}
}

void Chunk::Update()
{
	CalculateFaces(occupied);
	CalculateMeshes();
}

Chunk::Chunk(glm::vec2 chunkCoords, std::vector<int> chunkHeights)
{
	Chunk::chunkCoords = chunkCoords;
	std::vector<std::vector<std::vector<int>>> occupied(CHUNK_SIZE +1, std::vector<std::vector<int>>(CHUNK_SIZE +1, std::vector<int>(CHUNK_SIZE +1, false)));

	for (unsigned int i = 0; i < CHUNK_SIZE; i++)
	{
		for (unsigned int j = 0; j < CHUNK_SIZE; j++)
		{
			for (unsigned int k = 0; k < CHUNK_SIZE; k++)
			{
				BlockTypes type = BlockTypes::AIR;
				if (j > (unsigned) chunkHeights[i * CHUNK_SIZE + k])
				{
					occupied[i][j][k] = 0;
				}
				else 
				{
					type = j == chunkHeights[i * CHUNK_SIZE + k] ? BlockTypes::GRASS_BLOCK : BlockTypes::DIRT_BLOCK;
					occupied[i][j][k] = 1;
				}
					
				cubes.push_back(Cube(glm::vec3(chunkCoords.x * CHUNK_SIZE + i, j, chunkCoords.y * CHUNK_SIZE + k), type));
				
			}
		}
	}
	Chunk::occupied = occupied;
}



void Chunk::Draw(Shader& shader, Camera& camera)
{
	for (Mesh mesh : Chunk::meshes)
		mesh.Draw(shader, camera);
}