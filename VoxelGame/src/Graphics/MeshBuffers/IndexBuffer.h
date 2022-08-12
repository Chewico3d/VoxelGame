#pragma once
class IndexBuffer
{
private:
	unsigned int Buffer_ID;
public:
	IndexBuffer(void* data,unsigned int Size);
	~IndexBuffer();

	void Bind();

};

