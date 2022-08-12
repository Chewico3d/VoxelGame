#pragma once
#include <iostream>
#include <vector>

#include "Graphics/MeshBuffers/VertexArray.h"
#include "Graphics/MeshBuffers/VertexBuffer.h"
#include "Graphics/MeshBuffers/IndexBuffer.h"
#include "World/Abstract/Camera.h"
#include "Graphics/Shaders/ObjectShader.h"


class Chunk
{
private:
	std::vector<int> CordinteID[3];
	VertexArray* VA;
	VertexBuffer* VB;
	IndexBuffer* IB;

public:
	Chunk();
	void Draw(Camera& camera, ObjectShader& shader);

};

