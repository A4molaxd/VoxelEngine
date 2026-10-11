#include"Cube.h"

Cube::Cube(glm::vec3 pos)
{
	Cube::pos = pos;

	Vertex vertices[] =
	{
		// BOTTOM FACE (-Y)
		Vertex{glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec3(1,1,0), glm::vec3(0,-1,0), glm::vec2(0,0)},
		Vertex{glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(1,1,0), glm::vec3(0,-1,0), glm::vec2(0,1)},
		Vertex{glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(1,1,0), glm::vec3(0,-1,0), glm::vec2(1,1)},
		Vertex{glm::vec3(1.0f, -1.0f,  1.0f), glm::vec3(1,1,0), glm::vec3(0,-1,0), glm::vec2(1,0)},

		// TOP FACE (+Y)
		Vertex{glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec3(1,1,0), glm::vec3(0, 1,0), glm::vec2(0,0)},
		Vertex{glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec3(1,1,0), glm::vec3(0, 1,0), glm::vec2(0,1)},
		Vertex{glm::vec3(1.0f,  1.0f, -1.0f), glm::vec3(1,1,0), glm::vec3(0, 1,0), glm::vec2(1,1)},
		Vertex{glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1,1,0), glm::vec3(0, 1,0), glm::vec2(1,0)},

		// RIGHT FACE (+X)
		Vertex{glm::vec3(1.0f, -1.0f,  1.0f), glm::vec3(1,1,0), glm::vec3(1,0,0), glm::vec2(0,0)},
		Vertex{glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(1,1,0), glm::vec3(1,0,0), glm::vec2(0,1)},
		Vertex{glm::vec3(1.0f,  1.0f, -1.0f), glm::vec3(1,1,0), glm::vec3(1,0,0), glm::vec2(1,1)},
		Vertex{glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1,1,0), glm::vec3(1,0,0), glm::vec2(1,0)},

		// LEFT FACE (-X)
		Vertex{glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(1,1,0), glm::vec3(-1,0,0), glm::vec2(0,0)},
		Vertex{glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec3(1,1,0), glm::vec3(-1,0,0), glm::vec2(0,1)},
		Vertex{glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec3(1,1,0), glm::vec3(-1,0,0), glm::vec2(1,1)},
		Vertex{glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec3(1,1,0), glm::vec3(-1,0,0), glm::vec2(1,0)},

		// FRONT FACE (+Z)
		Vertex{glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec3(1,1,0), glm::vec3(0,0,1), glm::vec2(0,0)},
		Vertex{glm::vec3(1.0f, -1.0f,  1.0f), glm::vec3(1,1,0), glm::vec3(0,0,1), glm::vec2(0,1)},
		Vertex{glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1,1,0), glm::vec3(0,0,1), glm::vec2(1,1)},
		Vertex{glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec3(1,1,0), glm::vec3(0,0,1), glm::vec2(1,0)},

		// BACK FACE (-Z)
		Vertex{glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(1,1,0), glm::vec3(0,0,-1), glm::vec2(0,0)},
		Vertex{glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(1,1,0), glm::vec3(0,0,-1), glm::vec2(0,1)},
		Vertex{glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec3(1,1,0), glm::vec3(0,0,-1), glm::vec2(1,1)},
		Vertex{glm::vec3(1.0f,  1.0f, -1.0f), glm::vec3(1,1,0), glm::vec3(0,0,-1), glm::vec2(1,0)}
	};

	GLuint indices[] =
	{
		// BOTTOM
		0,  1,  2,
		0,  2,  3,

		// TOP
		4,  6,  5,
		4,  7,  6,

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

	Texture textures[]
	{
		Texture("grassBlock.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	};

	std::vector <std::vector<GLuint>> ind;
	for (unsigned int i = 0; i < sizeof(indices); i)
	{
		ind.push_back({ indices[i++], indices[i++], indices[i++], indices[i++], indices[i++], indices[i++] });
	}

	std::vector <Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector <Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));

	meshes =
	{
		Mesh(verts, ind[0], tex),
		Mesh(verts, ind[1], tex),
		Mesh(verts, ind[2], tex),
		Mesh(verts, ind[3], tex),
		Mesh(verts, ind[4], tex),
		Mesh(verts, ind[5], tex),
	};
}

void Cube::Draw(Shader& shader, Camera& camera) 
{
	for (unsigned int i = 0; i < meshes.size(); i++)
	{
		meshes[i].Draw(shader, camera);
	}
}