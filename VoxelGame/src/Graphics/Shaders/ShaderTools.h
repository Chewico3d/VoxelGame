#pragma once
#include <GL/glew.h>

#include <iostream>
#include <sstream>
#include <fstream>

class ShaderTools
{
public:
	static std::string Load(const std::string& path);

	static unsigned int CompileShader(const std::string& path, int type);
	static unsigned int CreateProgram(unsigned int ShaderID);
	static unsigned int CreateProgram(unsigned int sid1, unsigned int sid2);
};
