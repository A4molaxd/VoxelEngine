#pragma once

#include<glm/glm.hpp>
#include<glad/gl.h>

#include"Shader.h"

class Light
{
public:

	glm::vec3 position;
	glm::vec4 color;


	Light(glm::vec3 position, glm::vec4 color);

	void Activate(Shader shader);
};