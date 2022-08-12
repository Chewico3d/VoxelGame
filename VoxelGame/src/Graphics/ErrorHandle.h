#pragma once
#include <iostream>
#include <GL/glew.h>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GlClearError();\
x;\
GlCheckError();


static void GlClearError() {
	while (glGetError() != GL_NO_ERROR);
}

static void GlCheckError() {
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL error] ( " << error << " )" << std::endl;
	}
}