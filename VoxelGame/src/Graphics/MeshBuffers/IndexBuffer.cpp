#include "IndexBuffer.h"
#include <GL/glew.h>
#include "Graphics/ErrorHandle.h"


IndexBuffer::IndexBuffer(void* data, unsigned int Size)
{
	GLCall(glGenBuffers(1, &Buffer_ID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Buffer_ID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, Size, data, GL_STATIC_DRAW));

}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &Buffer_ID);
}

void IndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Buffer_ID);
}
