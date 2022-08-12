#pragma once
#include <GL/glew.h>
#include <iostream>

class TextureBuffer
{
private:
	unsigned int TextureID;
public:
	TextureBuffer();

	void Load(const std::string ImagePath);
	void Bind(unsigned int Slot);

};

