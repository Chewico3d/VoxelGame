#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Graphics/Shaders/ObjectShader.h"

class Scene
{
private:
	GLFWwindow* window;

public:
	Scene();

	void Start();

};

