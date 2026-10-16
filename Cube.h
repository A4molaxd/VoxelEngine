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

	void Draw(Shader& shader, Camera& camera);

private:
	std::vector<Mesh> meshes;
};