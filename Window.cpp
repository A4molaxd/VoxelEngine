#include"Window.h"

// TODO: resizeable window

Window::Window(const unsigned int width, const unsigned int height, const float dt)
{
	Window::dt = dt;
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	window = glfwCreateWindow(width, height, "Test", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD\n";
	}

	glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

	glViewport(0, 0, width, height);
}

void Window::Options()
{
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
}

void Window::Update()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Window::Clear()
{
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Close()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Window::CalculateTimes()
{
	crntTime = glfwGetTime();
	timeDiff = crntTime - prevTime;
	counter++;
	if (timeDiff >= dt)
	{
		std::string FPS = std::to_string((1.0 / timeDiff) * counter);
		std::string newTitle = "Voxel Engine - " + FPS + " FPS";
		glfwSetWindowTitle(window, newTitle.c_str());

		prevTime = crntTime;
		counter = 0;
	}
}

void Window::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Window::GetWindowSize(GLFWwindow* window, int* width, int* height) {
	glfwGetWindowSize(window, width, height);
}

double Window::GetTimeDiff()
{
	return timeDiff;
}