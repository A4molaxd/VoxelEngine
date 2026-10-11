#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include<glm/glm.hpp>
#include<glad/gl.h>
#include<vector>
#include"Constants.h"

class VBO
{
public:
	GLuint ID;
	VBO(std::vector <Vertex>& vertices);

	void Bind();
	void Unbind();
	void Delete();
};

#endif