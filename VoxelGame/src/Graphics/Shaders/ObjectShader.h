#pragma once
#include <iostream>
#include "ShaderTools.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class ObjectShader
{
private:
	unsigned int Program_ID;
	unsigned int MatrixID = -1;
public:
	ObjectShader(const std::string& fragmentShader, const std::string& vertexShader);

	void Bind();
	void SetUniform1i(unsigned int uniformID, int value);
	void SetUniform1i(const std::string& Name, int value);
	void SetMatrix(glm::mat4 Matrix);

};

