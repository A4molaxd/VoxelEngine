#include"Cube.h"

Cube::Cube(glm::vec3 pos, BlockTypes type)
{
	Cube::pos = pos;
	Cube::type = type;
	if (type != BlockTypes::AIR) {
		for (unsigned int i = 0; i < 6; i++)
			ocludedFaces.push_back(true);

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

		GLuint indices[] =
		{
			// TOP
			0,  2,  1,
			0,  3,  2,

			// BOTTOM
			4 - 4,  6 - 4,  5 - 4,
			4 - 4,  7 - 4,  6 - 4,

			// RIGHT
			8 - 8, 10 - 8, 9 - 8,
			8 - 8, 11 - 8, 10 - 8,

			// LEFT
			12 - 12, 14 - 12, 13 - 12,
			12 - 12, 15 - 12, 14 - 12,

			// FRONT
			16 - 16, 18 - 16, 17 - 16,
			16 - 16, 19 - 16, 18 - 16,

			// BACK
			20 - 20, 22 - 20, 21 - 20,
			20 - 20, 23 - 20, 22 - 20
		};

		std::vector <std::vector<Vertex>> verts;
		for (unsigned int i = 0; i < sizeof(indices) / sizeof(GLuint); i)
		{
			verts.push_back({ vertices[i++], vertices[i++], vertices[i++], vertices[i++] });
		}
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

		for (unsigned int i = 0; i < ind.size(); i++)
			meshes.push_back(Mesh(verts[i], ind[i], tex[i]));
	}
}

std::vector<Mesh> Cube::GetMeshes() 
{
	std::vector<Mesh> _meshes;
	for (unsigned int i = 0; i < meshes.size(); i++)
	{
		if (ocludedFaces[i])
			_meshes.push_back(meshes[i]);
	}
	return _meshes;
}
