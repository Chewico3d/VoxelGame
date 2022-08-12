#include "TextureBuffer.h"
#include "stb_image.h"

TextureBuffer::TextureBuffer()
{
	glCreateTextures(GL_TEXTURE_2D, 1, &TextureID);
	glBindTexture(GL_TEXTURE_2D, TextureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

}

void TextureBuffer::Load(const std::string ImagePath)
{
	stbi_set_flip_vertically_on_load(true);
	
	int With, Height, Bppx;
	unsigned char* LocalBuffer = stbi_load(ImagePath.c_str(), &With, &Height, &Bppx, 3);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, With, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, LocalBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (LocalBuffer)
		stbi_image_free(LocalBuffer);
}

void TextureBuffer::Bind(unsigned int Slot)
{
	glActiveTexture(GL_TEXTURE0 + Slot);
	glBindTexture(GL_TEXTURE_2D, TextureID);
}

