#include "ShaderTools.h"
std::string ShaderTools::Load(const std::string& path) {

	std::ifstream fl(path);

	fl.seekg(0, std::ios::end);
	std::size_t size = fl.tellg();

	std::string out(size, ' ');
	fl.seekg(0);

	fl.read(&out[0], size);

	return out;

}

unsigned int ShaderTools::CompileShader(const std::string& path, int type) {

	unsigned int ShaderID = glCreateShader(type);
	std::string res = Load(path);
	const char* src = res.c_str();

	glShaderSource(ShaderID, 1, &src, NULL);
	glCompileShader(ShaderID);

	//Check errors
	int result = 0;
	glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE) {
		int lenght = 0;
		glGetShaderiv(ShaderID, GL_INFO_LOG_LENGTH, &lenght);

		char* message = (char*)alloca(lenght * sizeof(char));
		glGetShaderInfoLog(ShaderID, lenght, &lenght, message);

		std::cout << "Failed to compile" << std::endl << message << std::endl;
	}

	return ShaderID;


}

unsigned int ShaderTools::CreateProgram(unsigned int ShaderID) {


	unsigned int ProgramID = glCreateProgram();
	glAttachShader(ProgramID, ShaderID);
	glLinkProgram(ProgramID);

	glDeleteShader(ShaderID);

	return ProgramID;

}
unsigned int ShaderTools::CreateProgram(unsigned int sid1, unsigned int sid2) {


	unsigned int ProgramID = glCreateProgram();
	glAttachShader(ProgramID, sid1);
	glAttachShader(ProgramID, sid2);
	glLinkProgram(ProgramID);

	glDeleteShader(sid1);
	glDeleteShader(sid2);

	return ProgramID;

}