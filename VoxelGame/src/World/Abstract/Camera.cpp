#include "Camera.h"

Camera::Camera(int With, int Height, glm::vec3 Position)
{
	this->With = With;
	this->Height = Height;
	this->Position = Position;
}

glm::mat4 Camera::Matrix(float FOVdeg, float NearPlane, float FarPlane)
{
	glm::mat4 view = glm::mat4(1.0f);
	
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(Position, Position + Orientation, UP);
	projection = glm::perspective(glm::radians(FOVdeg), ((float)With / (float)Height), NearPlane, FarPlane);
	
	return projection * view;

}

void Camera::Input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		Position += Speed * Orientation;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		Position += -Speed * glm::normalize(glm::cross(Orientation, UP));
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		Position += Speed * glm::normalize(glm::cross(Orientation, UP));
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		Position += -Speed * Orientation;
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		Position += Speed * UP;
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
		Position += -Speed * UP;
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		double MouseX;
		double MouseY;

		glfwGetCursorPos(window, &MouseX, &MouseY);

		float rotx = Sensibility * (float)(MouseX - (With / 2)) / With;
		float roty = Sensibility * (float)(MouseY - (Height / 2)) / Height;

		glm::vec3 NewRot = glm::rotate(Orientation, glm::radians(-roty), glm::normalize(glm::cross(Orientation, UP)));
		NewRot = glm::rotate(NewRot, glm::radians(-rotx), UP);

		Orientation = NewRot;
		glfwSetCursorPos(window, With / 2, Height / 2);

	}

}
