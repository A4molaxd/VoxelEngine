#include"Light.h"

Light::Light(glm::vec3 position, glm::vec4 color)
{
	Light::position = position;
	Light::color = color;
}

void Light::Activate(Shader shader)
{
	glUniform4f(glGetUniformLocation(shader.ID, "lightColor"), color.x, color.y, color.z, color.w);
	glUniform3f(glGetUniformLocation(shader.ID, "lightPos"), position.x, position.y, position.z);
}