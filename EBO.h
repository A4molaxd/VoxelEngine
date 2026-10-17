#pragma once

#include<glad/gl.h>
#include<vector>
#include<numbers>

class EBO
{
	public:
		GLuint ID;
		EBO(std::vector<GLuint>& indices);

		void Bind();
		void Unbind();
		void Delete();
};