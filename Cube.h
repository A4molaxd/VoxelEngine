#pragma once

#include"Mesh.h"
#include"BlockTypes.h"

class Cube
{
public:
	
	glm::vec3 pos;
	BlockTypes type;

	std::vector<bool> ocludedFaces;

	Cube(glm::vec3 pos, BlockTypes type);

	std::vector<std::vector<Vertex>> vertices;
	std::vector<std::vector<GLuint>> indices;
	std::vector<std::vector<Texture>> textures;

	std::vector<Mesh> GetMeshes();

private:
	std::vector<Mesh> meshes;
};