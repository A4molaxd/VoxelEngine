#ifndef CUBE_CLASS_H
#define CUBE_CLASS_H

#include"Mesh.h"

class Cube
{
public:
	
	glm::vec3 pos;

	Cube(glm::vec3 pos);

	void Draw(Shader& shader, Camera& camera);

private:
	std::vector<Mesh> meshes;
};


#endif