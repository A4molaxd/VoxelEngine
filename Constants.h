#pragma once

const unsigned int CHUNK_SIZE = 16;

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texUV;
};