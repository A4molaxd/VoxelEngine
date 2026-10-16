#pragma once

#include<glad/gl.h>
#include<vector>

class EBO
{
	public:
		GLuint ID;
		EBO(std::vector<GLuint>& indices);

		void Bind();
		void Unbind();
		void Delete();
};