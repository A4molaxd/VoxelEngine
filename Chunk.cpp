#include"Chunk.h"

void Chunk::CalculateFaces(std::vector<std::vector<std::vector<int>>> occupied)
{
	int counter = 0;
	for (int i = 0; i < chunkWidth; i++)
	{
		for (int j = 0; j < chunkHeight; j++)
		{
			for (int k = 0; k < chunkLength; k++)
			{
				if (occupied[i][j][k])
				{
					if (i + 1 < chunkLength) if (occupied[i + 1][j][k]) cubes[counter].ocludedFaces[2] = false; 
					if (i - 1 >= 0) if (occupied[i - 1][j][k]) cubes[counter].ocludedFaces[3] = false; 
					if (j + 1 < chunkHeight) if (occupied[i][j + 1][k]) cubes[counter].ocludedFaces[0] = false;
					if (j - 1 >= 0) if (occupied[i][j - 1][k]) cubes[counter].ocludedFaces[1] = false; 
					if (k + 1 < chunkWidth) if (occupied[i][j][k + 1]) cubes[counter].ocludedFaces[4] = false; 
					if (k - 1 >= 0) if (occupied[i][j][k - 1]) cubes[counter].ocludedFaces[5] = false; 
				}
				counter++;
			}
		}
	}
}

void Chunk::CalculateMeshes()
{
	// This implementation does not account for block rotations
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
				// Get every visible mesh (face) in the cube
				std::vector<Mesh> m = cube.GetMeshes();
				for (unsigned int i = 0; i < m.size(); i++)
				{
					// Check where its normal points to classify it
					int t = -1;
					for (unsigned int v = 0; v < vertices.size(); v++)
					{
						if (m[i].vertices[0].normal == vertices[v][0].normal) {
							t = v;
						}
					}
					// If the normal is not already on a sublist, create a new sublist
					if (t == -1) {
						t = vertices.size();
						vertices.push_back(std::vector<Vertex>());
						indices.push_back(std::vector<GLuint>());
						textures.push_back(m[i].textures);
						ind.push_back(0);
					}
					// Add their vertices and indices to the list they belong to
					for (unsigned int j = 0; j < 4; j++)
					{
						vertices[t].push_back(m[i].vertices[j]);
					} 
					// TODO: Change direction of the faces for culling
					indices[t].push_back(0 + ind[t]);
					indices[t].push_back(2 + ind[t]);
					indices[t].push_back(1 + ind[t]);
					indices[t].push_back(0 + ind[t]);
					indices[t].push_back(3 + ind[t]);
					indices[t].push_back(2 + ind[t]);
					ind[t] += 4;
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
	std::vector<std::vector<std::vector<int>>> occupied(chunkWidth+1, std::vector<std::vector<int>>(chunkHeight+1, std::vector<int>(chunkLength+1, false)));

	for (unsigned int i = 0; i < chunkWidth; i++)
	{
		for (unsigned int j = 0; j < chunkHeight; j++)
		{
			for (unsigned int k = 0; k < chunkLength; k++)
			{
				BlockTypes type = BlockTypes::AIR;
				if (j > chunkHeights[i * chunkLength + k])
				{
					occupied[i][j][k] = 0;
				}
				else 
				{
					type = j == chunkHeights[i * chunkLength + k] ? BlockTypes::GRASS_BLOCK : BlockTypes::DIRT_BLOCK;
					occupied[i][j][k] = 1;
				}
					
				cubes.push_back(Cube(glm::vec3(chunkCoords.x * chunkWidth + i, j, chunkCoords.y * chunkLength + k), type));
				
			}
		}
	}
	Chunk::occupied = occupied;
	Update();
}



void Chunk::Draw(Shader& shader, Camera& camera)
{
	// TODO: Greedy meshing and other chunk rendering optimization techniques
	for (Mesh mesh : Chunk::meshes)
		mesh.Draw(shader, camera);
}