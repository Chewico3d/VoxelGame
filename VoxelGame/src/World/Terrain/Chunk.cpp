#include "Chunk.h"
#include <GL/glew.h>
#include "Graphics/ErrorHandle.h"
#include "glm/glm.hpp"

float ExampleCube[] = {
	//	X		Y		Z		U		V
	//	Front Face
		0,		0,		0,		0,		0,
		0,		1,		0,		0,		1,
		1,		0,		0,		1,		0,
		1,		1,		0,		1,		1,

	//BackFace
		1,		0,		1,		0,		0,
		1,		1,		1,		0,		1,
		0,		0,		1,		1,		0,
		0,		1,		1,		1,		1,
	
	//Left
		0,		0,		1,		0,		0,
		0,		1,		1,		0,		1,
		0,		0,		0,		1,		0,
		0,		1,		0,		1,		1,

	//Right
		1,		0,		0,		0,		0,
		1,		1,		0,		0,		1,
		1,		0,		1,		1,		0,
		1,		1,		1,		1,		1,

	//Up
		0,		1,		0,		0,		0,
		0,		1,		1,		0,		1,
		1,		1,		0,		1,		0,
		1,		1,		1,		1,		1,

	//Down
		1,		0,		0,		0,		0,
		1,		0,		1,		0,		1,
		0,		0,		0,		1,		0,
		0,		0,		1,		1,		1,


};
unsigned int Indices[]{
	0,1,2,
	2,1,3,

	0 + 4,1 + 4,2 + 4,
	2 + 4,1 + 4,3 + 4,

	0 + 8,1 + 8,2 + 8,
	2 + 8,1 + 8,3 + 8,

	0 + 12,1 + 12,2 + 12,
	2 + 12,1 + 12,3 + 12,


	0 + 16,1 + 16,2 + 16,
	2 + 16,1 + 16,3 + 16,

	0 + 20,1 + 20,2 + 20,
	2 + 20,1 + 20,3 + 20,


};
Chunk::Chunk()
{

	IndexCount = 6 * 6;
	VB = new VertexBuffer(ExampleCube, 6 * 5  * 6 * sizeof(float));
	IB = new IndexBuffer(Indices, 6 * 6 * sizeof(unsigned int));
	VA = new VertexArray();

	VA->AddLayout(3, GL_FLOAT, GL_FALSE, 3 * sizeof(float));
	VA->AddLayout(2, GL_FLOAT, GL_FALSE, 2 * sizeof(float));
	VA->SetVertexBuffer(VB[0]);

}

void Chunk::Calculate()
{
	Data data = ChunkCreation::GenerateMesh();

	IndexCount = data.NumIndexs;
	VB = new VertexBuffer(data.VertexData, data.NumElements * sizeof(float));
	IB = new IndexBuffer(data.IndexData, data.NumIndexs * sizeof(unsigned int));
	VA = new VertexArray();

	VA->AddLayout(3, GL_FLOAT, GL_FALSE, 3 * sizeof(float));
	VA->AddLayout(2, GL_FLOAT, GL_FALSE, 2 * sizeof(float));
	VA->SetVertexBuffer(VB[0]);


}

void Chunk::Draw(Camera& camera, ObjectShader& shader)
{
	VA->Bind();
	IB->Bind();

	glm::mat4 CameraMatrix = camera.Matrix(80, 0.01f, 100);

	shader.Bind();
	shader.SetMatrix(CameraMatrix);
	glDrawElements(GL_TRIANGLES, IndexCount, GL_UNSIGNED_INT, 0);
}
