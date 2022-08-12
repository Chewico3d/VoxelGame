#pragma once
#include <iostream>
#include <vector>

#include "VertexBuffer.h"

struct Layout
{
	unsigned int Size;
	unsigned int Type;
	unsigned int Normalize;
	unsigned int ElementSize;


};

class VertexArray
{
private:
	unsigned int Buffer_ID;
	std::vector<Layout> layouts;
	unsigned int Stride;
public:
	VertexArray();
	~VertexArray();

	void Bind();
	void AddLayout(unsigned int Size, unsigned int Type, unsigned int Normalize, unsigned int ElementSize);
	void SetVertexBuffer(VertexBuffer& VA);

};

