#include"Cube.h"

Cube::Cube(glm::vec3 pos, BlockTypes type)
{
	Cube::pos = pos;
	Cube::type = type;

	for (unsigned int i = 0; i < 6; i++)
		ocludedFaces.push_back(true);

	if (type != BlockTypes::AIR)
	{
		Vertex vertices[] =
		{

			// TOP FACE (+Y)
			Vertex{glm::vec3(-0.5f + pos.x,  0.5f + pos.y,  0.5f + pos.z), glm::vec3(0, 1,0), glm::vec2(0,0)},
			Vertex{glm::vec3(-0.5f + pos.x,  0.5f + pos.y, -0.5f + pos.z), glm::vec3(0, 1,0), glm::vec2(0,1)},
			Vertex{glm::vec3(0.5f + pos.x,  0.5f + pos.y, -0.5f + pos.z), glm::vec3(0, 1,0), glm::vec2(1,1)},
			Vertex{glm::vec3(0.5f + pos.x,  0.5f + pos.y,  0.5f + pos.z), glm::vec3(0, 1,0), glm::vec2(1,0)},

			// BOTTOM FACE (-Y)
			Vertex{glm::vec3(-0.5f + pos.x, -0.5f + pos.y,  0.5f + pos.z), glm::vec3(0,-1,0), glm::vec2(0,0)},
			Vertex{glm::vec3(-0.5f + pos.x, -0.5f + pos.y, -0.5f + pos.z), glm::vec3(0,-1,0), glm::vec2(0,1)},
			Vertex{glm::vec3(0.5f + pos.x, -0.5f + pos.y, -0.5f + pos.z), glm::vec3(0,-1,0), glm::vec2(1,1)},
			Vertex{glm::vec3(0.5f + pos.x, -0.5f + pos.y,  0.5f + pos.z), glm::vec3(0,-1,0), glm::vec2(1,0)},

			// RIGHT FACE (+X)
			Vertex{glm::vec3(0.5f + pos.x, -0.5f + pos.y,  0.5f + pos.z), glm::vec3(1,0,0), glm::vec2(1,0)},
			Vertex{glm::vec3(0.5f + pos.x, -0.5f + pos.y, -0.5f + pos.z), glm::vec3(1,0,0), glm::vec2(0,0)},
			Vertex{glm::vec3(0.5f + pos.x,  0.5f + pos.y, -0.5f + pos.z), glm::vec3(1,0,0), glm::vec2(0,1)},
			Vertex{glm::vec3(0.5f + pos.x,  0.5f + pos.y,  0.5f + pos.z), glm::vec3(1,0,0), glm::vec2(1,1)},

			// LEFT FACE (-X)
			Vertex{glm::vec3(-0.5f + pos.x, -0.5f + pos.y, -0.5f + pos.z), glm::vec3(-1,0,0), glm::vec2(1,0)},
			Vertex{glm::vec3(-0.5f + pos.x, -0.5f + pos.y,  0.5f + pos.z), glm::vec3(-1,0,0), glm::vec2(0,0)},
			Vertex{glm::vec3(-0.5f + pos.x,  0.5f + pos.y,  0.5f + pos.z), glm::vec3(-1,0,0), glm::vec2(0,1)},
			Vertex{glm::vec3(-0.5f + pos.x,  0.5f + pos.y, -0.5f + pos.z), glm::vec3(-1,0,0), glm::vec2(1,1)},

			// FRONT FACE (+Z)
			Vertex{glm::vec3(-0.5f + pos.x, -0.5f + pos.y,  0.5f + pos.z), glm::vec3(0,0,1), glm::vec2(1,0)},
			Vertex{glm::vec3(0.5f + pos.x, -0.5f + pos.y,  0.5f + pos.z), glm::vec3(0,0,1), glm::vec2(0,0)},
			Vertex{glm::vec3(0.5f + pos.x,  0.5f + pos.y,  0.5f + pos.z), glm::vec3(0,0,1), glm::vec2(0,1)},
			Vertex{glm::vec3(-0.5f + pos.x,  0.5f + pos.y,  0.5f + pos.z), glm::vec3(0,0,1), glm::vec2(1,1)},

			// BACK FACE (-Z)
			Vertex{glm::vec3(0.5f + pos.x, -0.5f + pos.y, -0.5f + pos.z), glm::vec3(0,0,-1), glm::vec2(1,0)},
			Vertex{glm::vec3(-0.5f + pos.x, -0.5f + pos.y, -0.5f + pos.z), glm::vec3(0,0,-1), glm::vec2(0,0)},
			Vertex{glm::vec3(-0.5f + pos.x,  0.5f + pos.y, -0.5f + pos.z), glm::vec3(0,0,-1), glm::vec2(0,1)},
			Vertex{glm::vec3(0.5f + pos.x,  0.5f + pos.y, -0.5f + pos.z), glm::vec3(0,0,-1), glm::vec2(1,1)},
		};

		for (unsigned int i = 0; i < 36; i)
			Cube::vertices.push_back({ vertices[i++], vertices[i++], vertices[i++], vertices[i++] });

		for (unsigned int i = 0; i < BlockType[type].size(); i)
			Cube::textures.push_back({ BlockType[type][i++] });
	}
}
