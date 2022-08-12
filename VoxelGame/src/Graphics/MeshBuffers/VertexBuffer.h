#pragma once
class VertexBuffer
{
private:
	unsigned int Buffer_ID;
public:
	VertexBuffer(void* data, unsigned int Size);
	~VertexBuffer();

	void Bind();

};

