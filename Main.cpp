//	 
//	 //\\   || || ||\\//|| // \\ ||		//\\   \\// ||\\
//	//__\\  ||_|| || `´ || || || ||	   //__\\   \\	|| ||
// //    \\	   || ||	|| \\_// ||__ //    \\ //\\ ||//
//

#include"World.h"
#include"Window.h"
#include"Light.h"

const unsigned int init_width = 800;
const unsigned int init_height = 800;

bool wireframeRendering = false;

int width, height;

const float dt = 1.0f / 30.0f;

int main()
{
	Window window(init_width, init_height, dt);
	window.Options();

	InitBlockTypes();

	Shader shader("default.vert", "default.frag");
	shader.Activate();

	World world;
	world.chunkManager.Generate(world.seed);
	world.chunkManager.Update();

	Light light(glm::vec3(1.0f), glm::vec4(1.0f));
	light.Activate(shader);

	Camera camera(init_width, init_height, glm::vec3(-16.4f, 22.2f, 24.1f));


	while (!glfwWindowShouldClose(window.window)) 
	{
		if (wireframeRendering)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		window.Clear();
		
		window.GetWindowSize(window.window, &width, &height);

		camera.UpdateResolution(width, height);

		window.CalculateTimes();

		if (window.GetTimeDiff() >= dt)
		{
			camera.Inputs(window.window);

			if (glfwGetKey(window.window, GLFW_KEY_P))
			{
				std::cout << world.GetCube(5, 5, 0).type << std::endl;
				std::cout << camera.Orientation.x << " " << camera.Orientation.y << " " << camera.Orientation.z << std::endl;
			}
			if (glfwGetKey(window.window, GLFW_KEY_R))
				wireframeRendering = !wireframeRendering;
		}
		camera.UpdateMatrix(45.0f, 0.1f, 100.0f);
		world.Draw(shader, camera);
		if (wireframeRendering)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		window.Update();
	}

	shader.Delete();

	window.Close();

	return 0;
}