#include "ObjectShader.h"

ObjectShader::ObjectShader(const std::string& fragmentShader, const std::string& vertexShader)
{
	unsigned int FragmentID = ShaderTools::CompileShader(fragmentShader, GL_FRAGMENT_SHADER);
	unsigned int VertexID = ShaderTools::CompileShader(vertexShader, GL_VERTEX_SHADER);
	
	Program_ID = ShaderTools::CreateProgram(FragmentID, VertexID);

}

void ObjectShader::Bind()
{
	glUseProgram(Program_ID);
}

void ObjectShader::SetUniform1i(unsigned int uniformID, int value)
{
	Bind();
	glUniform1i(uniformID, value);
}

void ObjectShader::SetUniform1i(const std::string& Name, int value)
{
	Bind();
	glUniform1i(glGetUniformLocation(Program_ID, Name.c_str()), value);
}

void ObjectShader::SetMatrix(glm::mat4 Matrix)
{
	if (MatrixID == -1)
		MatrixID = glGetUniformLocation(Program_ID, "matrix");

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, glm::value_ptr(Matrix));
}
