#ifndef CUBE_CLASS_H
#define CUBE_CLASS_H

#include"Mesh.h"
#include"BlockTypes.h"

class Cube
{
public:
	
	glm::vec3 pos;
	BlockTypes type;

	Cube(glm::vec3 pos, BlockTypes type);

	void Draw(Shader& shader, Camera& camera);

private:
	std::vector<Mesh> meshes;
};


#endif