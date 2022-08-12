#include "VertexArray.h"
#include <GL/glew.h>
#include "Graphics/ErrorHandle.h"

VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &Buffer_ID));

}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &Buffer_ID);
}

void VertexArray::Bind()
{
	glBindVertexArray(Buffer_ID);
}

void VertexArray::AddLayout(unsigned int Size, unsigned int Type, unsigned int Normalize, unsigned int ElementSize)
{
	layouts.push_back({ Size,Type, Normalize, ElementSize });
	Stride += ElementSize;
}

void VertexArray::SetVertexBuffer(VertexBuffer& VA)
{
	glBindVertexArray(Buffer_ID);
	VA.Bind();

	unsigned int Size = layouts.size();
	unsigned int Offset = 0;
	for (int x = 0; x < Size; x++) {

		glEnableVertexAttribArray(x);
		glVertexAttribPointer(x, layouts[x].Size, layouts[x].Type, layouts[x].Normalize, Stride, (const void*)Offset);
		Offset += layouts[x].ElementSize;

	}

}


