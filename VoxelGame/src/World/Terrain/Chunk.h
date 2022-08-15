#pragma once
#include <iostream>
#include <list>
#include <vector>

#include "ChunkCreation.h"

#include "Graphics/MeshBuffers/VertexArray.h"
#include "Graphics/MeshBuffers/VertexBuffer.h"
#include "Graphics/MeshBuffers/IndexBuffer.h"
#include "World/Abstract/Camera.h"
#include "Graphics/Shaders/ObjectShader.h"

class Chunk
{
private:
	unsigned int IndexCount;
	std::vector<int> CordinteID[3];
	
	VertexArray* VA;
	VertexBuffer* VB;
	IndexBuffer* IB;

public:
	Chunk();
	void Calculate();
	void Draw(Camera& camera, ObjectShader& shader);

};

