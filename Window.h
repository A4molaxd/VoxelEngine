#pragma once

#include<glad/gl.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<string>

class Window 
{
	public:
		GLFWwindow* window;

		Window(const unsigned int height, const unsigned int width, const float dt);

		void CalculateTimes();

		void Options();

		void Update();

		void Clear();
		
		void Close();

		static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

		void GetWindowSize(GLFWwindow* window, int* width, int* height);

		double GetTimeDiff();
		
	private:
		float dt;

		double crntTime = 0.0;
		double prevTime = 0.0;
		double timeDiff = 0.0;

		unsigned int counter = 0;

};