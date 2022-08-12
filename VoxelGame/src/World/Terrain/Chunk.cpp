#include "Chunk.h"
#include <GL/glew.h>
#include "Graphics/ErrorHandle.h"
#include "glm/glm.hpp"

float ExampleCube[] = {
	//	X		Y		Z		U		V
	//	Front Face
		-0.5f,	-.5f,	-.5f,	0.0f,	0.0f,
		-0.5f,	 .5f,	-.5f,	0.0f,	1.0f,
		 0.5f,	-.5f,	-.5f,	1.0f,	0.0f,
		 0.5f,	 .5f,	-.5f,	1.0f,	1.0f


};
unsigned int Indices[]{
	0,1,2,
	2,1,3

};
Chunk::Chunk()
{
 	VB = new VertexBuffer(ExampleCube, 5 * 4 * sizeof(float));
	IB = new IndexBuffer(Indices, 3 * 2 * sizeof(unsigned int));
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
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
