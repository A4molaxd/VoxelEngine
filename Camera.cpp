#include"Camera.h"

Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width;
	Camera::height = height;
	Position = position;
}

void Camera::UpdateMatrix(float FOVdeg, float nearPlane, float farPlane)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(Position, Position + Orientation, Up);
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / (float)height, nearPlane, farPlane);

	cameraMatrix = projection * view;
}

void Camera::UpdateResolution(int width, int height)
{
	Camera::width = width;
	Camera::height = height;
}

void Camera::Matrix(Shader& shader, const char* uniform) {
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

void Camera::Inputs(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		if (glm::length(accel) < maxAccel)
			accel += speed * -glm::normalize(glm::cross(glm::cross(Orientation, Up), Up));
		else
			accel = maxAccel * glm::normalize(accel);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		if (glm::length(accel) < maxAccel)
			accel += speed * -glm::normalize(glm::cross(Orientation, Up));
		else
			accel = maxAccel * glm::normalize(accel);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		if (glm::length(accel) < maxAccel)
			accel += speed * glm::normalize(glm::cross(glm::cross(Orientation, Up), Up));
		else
			accel = maxAccel * glm::normalize(accel);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		if (glm::length(accel) < maxAccel)
			accel += speed * glm::normalize(glm::cross(Orientation, Up));
		else
			accel = maxAccel * glm::normalize(accel);
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		if (glm::length(accel) < maxAccel)
			accel += speed * Up;
		else
			accel = maxAccel * glm::normalize(accel);
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		if (glm::length(accel) < maxAccel)
			accel += speed * -Up;
		else
			accel = maxAccel * glm::normalize(accel);
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		maxVel = 2.0f;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_RELEASE)
	{
		maxVel = 1.0f;
	}
	if (!isFocused && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		isFocused = true;
	}
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		isFocused = false;
	}
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
	{
		std::cout << Position[0] << "x, " << Position[1] << "y, " << Position[2] << "z." << std::endl;
	}
	

	Position += vel;
	if (glm::length(vel) < maxVel)
		vel += accel;
	accel *= damping;
	vel *= damping;

	if (isFocused)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (firstClick) 
		{
			glfwSetCursorPos(window, (width / 2), (height / 2));
			firstClick = false;
		}

		double mouseX;
		double mouseY;

		glfwGetCursorPos(window, &mouseX, &mouseY);

		float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
		float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

		glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up)));


		if (!((glm::angle(newOrientation, Up) <= glm::radians(5.0f)) or (glm::angle(newOrientation, -Up) <= glm::radians(5.0f))))
		{
			Orientation = newOrientation;
		}

		Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);

		glfwSetCursorPos(window, (width / 2), (height / 2));
	}
	else
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		firstClick = true;
	}
}