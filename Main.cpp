#include"World.h"
#include"Window.h"
#include"Light.h"

const unsigned int width = 800;
const unsigned int height = 800;

const float dt = 1.0f / 30.0f;

int main()
{
	Window window(height, width, dt);
	window.Options();

	InitBlockTypes();

	Shader shader("default.vert", "default.frag");
	shader.Activate();

	World world;
	world.chunkManager.Generate(world.seed);

	Light light(glm::vec3(1.0f), glm::vec4(1.0f));
	light.Activate(shader);

	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 20.0f));

	while (!glfwWindowShouldClose(window.window)) 
	{
		window.CalculateTimes();

		if (window.GetTimeDiff() >= dt)
		{
			camera.Inputs(window.window);
		}

		window.Clear();
		
		camera.UpdateMatrix(45.0f, 0.1f, 100.0f);

		world.Draw(shader, camera);

		window.Update();
	}

	shader.Delete();

	window.Close();

	return 0;
}