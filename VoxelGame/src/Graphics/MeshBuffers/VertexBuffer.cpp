#include "VertexBuffer.h"
#include <GL/glew.h>
#include "Graphics/ErrorHandle.h"

VertexBuffer::VertexBuffer(void* data, unsigned int Size)
{
	GLCall(glGenBuffers(1, &Buffer_ID));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, Buffer_ID));
	GLCall(glBufferData(GL_ARRAY_BUFFER, Size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &Buffer_ID);
}

void VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, Buffer_ID);
}
