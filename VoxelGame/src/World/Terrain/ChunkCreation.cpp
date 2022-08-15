#include "ChunkCreation.h"

glm::ivec3 Directions[] = {
	glm::ivec3( 0, 0,-1), 
	glm::ivec3( 0, 0, 1),
	glm::ivec3(-1, 0, 0),
	glm::ivec3( 1, 0, 0),
	glm::ivec3( 0, 1, 0),
	glm::ivec3( 0,-1, 0)
};

float PlaneVertecies[] = {
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

Data ChunkCreation::GenerateMesh()
{

	int FacesCount = 0;

	//Counting Exact faces
	for (int x = 0; x < XSize; x++) {
		for (int y = 0; y < YSize; y++) {
			for (int z = 0; z < ZSize; z++) {

				glm::ivec3 CPos = glm::ivec3(x, y, z);
				if (!IsSolid(CPos))
					continue;

				int xx = CPos.x;
				int yy = CPos.y;
				int zz = CPos.z;

				for (int w = 0; w < 6; w++) {

					glm::ivec3 CheckPos = CPos + Directions[w];

					if (IsSolid(CheckPos))
						continue;

					FacesCount++;

				}

			}
		}
	}

	//Creating buffer and putting faces
	unsigned int VertciesLenght = FacesCount * 5 * 4;
	unsigned int IndexLenght = FacesCount * 6;
	float* Vertices = new float[VertciesLenght];
	unsigned int* Indices = new unsigned int[IndexLenght];

	int FaceID = 0;
	for (int x = 0; x < XSize; x++) {
		for (int y = 0; y < YSize; y++) {
			for (int z = 0; z < ZSize; z++) {

				glm::ivec3 CPos = glm::ivec3(x, y, z);
				if (!IsSolid(CPos))
					continue;

				for (int w = 0; w < 6; w++) {

					glm::ivec3 CheckPos = CPos + Directions[w];

					if (IsSolid(CheckPos))
						continue;

					for (int VertexLine = 0; VertexLine < 4; VertexLine++) {

						int LineID = FaceID * 5 * 4 + VertexLine * 5;
						int LookID = VertexLine * 5 + w * 5 * 4;

						float v0 = PlaneVertecies[LookID + 0] + CPos.x;
						if (CPos.x > 5)
							int putamadre = 9;
						Vertices[LineID + 0] = PlaneVertecies[LookID + 0] + x;
						Vertices[LineID + 1] = PlaneVertecies[LookID + 1] + y;
						Vertices[LineID + 2] = PlaneVertecies[LookID + 2] + z;

						Vertices[LineID + 3] = PlaneVertecies[LookID + 3];
						Vertices[LineID + 4] = PlaneVertecies[LookID + 4];

					}

					Indices[FaceID * 6 + 0] = 0 + FaceID * 4;
					Indices[FaceID * 6 + 1] = 1 + FaceID * 4;
					Indices[FaceID * 6 + 2] = 2 + FaceID * 4;
														   
					Indices[FaceID * 6 + 3] = 2 + FaceID * 4;
					Indices[FaceID * 6 + 4] = 1 + FaceID * 4;
					Indices[FaceID * 6 + 5] = 3 + FaceID * 4;

					FaceID++;
				}

			}
		}
	}


	return {Vertices, VertciesLenght, Indices, IndexLenght};
}

bool ChunkCreation::IsSolid(glm::ivec3 Pos)
{

	int FarX = Pos.x - 8;
	int FarY = Pos.y - 8;
	int FarZ = Pos.z - 8;

	return FarX * FarX + FarY * FarY + FarZ * FarZ < 60;
}
