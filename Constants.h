#pragma once

const unsigned int chunkHeight = 8;
const unsigned int chunkLength = 8;
const unsigned int chunkWidth = 8;

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texUV;
};