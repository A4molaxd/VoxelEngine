#include"Cube.h"

Cube::Cube(glm::vec3 pos, BlockTypes type)
{
	Cube::pos = pos;
	Cube::type = type;

	Vertex vertices[] =
	{

		// TOP FACE (+Y)
		Vertex{glm::vec3(-0.5f + pos.x,  0.5f + pos.y,  0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0, 1,0), glm::vec2(0,0)},
		Vertex{glm::vec3(-0.5f + pos.x,  0.5f + pos.y, -0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0, 1,0), glm::vec2(0,1)},
		Vertex{glm::vec3(0.5f + pos.x,  0.5f + pos.y, -0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0, 1,0), glm::vec2(1,1)},
		Vertex{glm::vec3(0.5f + pos.x,  0.5f + pos.y,  0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0, 1,0), glm::vec2(1,0)},

		// BOTTOM FACE (-Y)
		Vertex{glm::vec3(-0.5f + pos.x, -0.5f + pos.y,  0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0,-1,0), glm::vec2(0,0)},
		Vertex{glm::vec3(-0.5f + pos.x, -0.5f + pos.y, -0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0,-1,0), glm::vec2(0,1)},
		Vertex{glm::vec3(0.5f + pos.x, -0.5f + pos.y, -0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0,-1,0), glm::vec2(1,1)},
		Vertex{glm::vec3(0.5f + pos.x, -0.5f + pos.y,  0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0,-1,0), glm::vec2(1,0)},

		// RIGHT FACE (+X)
		Vertex{glm::vec3(0.5f + pos.x, -0.5f + pos.y,  0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(1,0,0), glm::vec2(1,0)},
		Vertex{glm::vec3(0.5f + pos.x, -0.5f + pos.y, -0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(1,0,0), glm::vec2(0,0)},
		Vertex{glm::vec3(0.5f + pos.x,  0.5f + pos.y, -0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(1,0,0), glm::vec2(0,1)},
		Vertex{glm::vec3(0.5f + pos.x,  0.5f + pos.y,  0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(1,0,0), glm::vec2(1,1)},

		// LEFT FACE (-X)
		Vertex{glm::vec3(-0.5f + pos.x, -0.5f + pos.y, -0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(-1,0,0), glm::vec2(1,0)},
		Vertex{glm::vec3(-0.5f + pos.x, -0.5f + pos.y,  0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(-1,0,0), glm::vec2(0,0)},
		Vertex{glm::vec3(-0.5f + pos.x,  0.5f + pos.y,  0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(-1,0,0), glm::vec2(0,1)},
		Vertex{glm::vec3(-0.5f + pos.x,  0.5f + pos.y, -0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(-1,0,0), glm::vec2(1,1)},

		// FRONT FACE (+Z)
		Vertex{glm::vec3(-0.5f + pos.x, -0.5f + pos.y,  0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0,0,1), glm::vec2(1,0)},
		Vertex{glm::vec3(0.5f + pos.x, -0.5f + pos.y,  0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0,0,1), glm::vec2(0,0)},
		Vertex{glm::vec3(0.5f + pos.x,  0.5f + pos.y,  0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0,0,1), glm::vec2(0,1)},
		Vertex{glm::vec3(-0.5f + pos.x,  0.5f + pos.y,  0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0,0,1), glm::vec2(1,1)},

		// BACK FACE (-Z)
		Vertex{glm::vec3(0.5f + pos.x, -0.5f + pos.y, -0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0,0,-1), glm::vec2(1,0)},
		Vertex{glm::vec3(-0.5f + pos.x, -0.5f + pos.y, -0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0,0,-1), glm::vec2(0,0)},
		Vertex{glm::vec3(-0.5f + pos.x,  0.5f + pos.y, -0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0,0,-1), glm::vec2(0,1)},
		Vertex{glm::vec3(0.5f + pos.x,  0.5f + pos.y, -0.5f + pos.z), glm::vec3(1,1,0), glm::vec3(0,0,-1), glm::vec2(1,1)},
	};

	GLuint indices[] =
	{
		// TOP
		0,  2,  1,
		0,  3,  2,

		// BOTTOM
		4,  5,  6,
		4,  6,  7,

		// RIGHT
		8,  9, 10,
		8, 10, 11,

		// LEFT
		12, 13, 14,
		12, 14, 15,

		// FRONT
		16, 17, 18,
		16, 18, 19,

		// BACK
		20, 21, 22,
		20, 22, 23
	};

	

	std::vector <std::vector<GLuint>> ind;
	for (unsigned int i = 0; i < sizeof(indices) / sizeof(GLuint); i)
	{
		ind.push_back({ indices[i++], indices[i++], indices[i++], indices[i++], indices[i++], indices[i++] });
	}
	std::vector <std::vector<Texture>> tex;
	for (unsigned int i = 0; i < BlockType[type].size(); i)
	{
		tex.push_back({ BlockType[type][i++] });
	}

	std::vector <Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));

	
	for (unsigned int i = 0; i < 6; i++)
		meshes.push_back(Mesh(verts, ind[i], tex[i]));
	
}

void Cube::Draw(Shader& shader, Camera& camera) 
{
	for (unsigned int i = 0; i < meshes.size(); i++)
	{
		if (ocludedFaces[i])
			meshes[i].Draw(shader, camera);
	}
}
