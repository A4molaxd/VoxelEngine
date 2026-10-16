#pragma once

#include<glad/gl.h>
#include<stb/stb_image.h>

#include"shaderClass.h"

class Texture
{
	public:
		GLuint ID;
		const char* type;
		GLuint unit;

		Texture(const char* image, const char* texType, GLuint slot, GLenum format, GLenum pixelType);
		
		void texUnit(Shader& shader, const char* unifomr, GLuint unit);
		void Bind();
		void Unbind();
		void Delete();
};	