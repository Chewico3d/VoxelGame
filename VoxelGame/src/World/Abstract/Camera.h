#pragma once
#include "glm/glm.hpp"
#include "glm/matrix.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/gtx/vector_angle.hpp"
#include "glm/ext.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Camera
{
public:
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 UP = glm::vec3(0.0f, 1.0f, 0.0f);

	int With, Height;

	float Speed = 0.01f;
	float Sensibility = 100.0f; 

	Camera(int With, int Height, glm::vec3 Position);
	glm::mat4 Matrix(float FOVdeg, float NearPlane, float FarPlane);
	void Input(GLFWwindow* window);

};

