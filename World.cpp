#include"World.h"

void World::Draw(Shader& shader, Camera& camera)
{
	shader.Activate();
	glUniform3f(glGetUniformLocation(shader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
	camera.Matrix(shader, "camMatrix");
	for (int i = 0; i < chunkManager.loadedChunks.size(); i++)
		chunkManager.loadedChunks[i].Draw(shader, camera);
}

