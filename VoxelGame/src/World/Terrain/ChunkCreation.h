#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <list>

#define XSize 16
#define YSize 256
#define ZSize 16

struct vertex {
	float x, y, z;
};

struct Data {

	float* VertexData;
	unsigned int NumElements;

	unsigned int* IndexData;
	unsigned int NumIndexs;
};


class ChunkCreation
{
public:
	static Data GenerateMesh();
	static bool IsSolid(glm::ivec3 Pos);

};

