#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include"Render/Shader.h"

class Camera
{
public:
	Camera(int width, int height, glm::vec3 position);

	void UpdateMatrix(float FOVdeg, float nearPlane, float farPlane);
	void Matrix(Shader& shader, const char* uniform);
	void Inputs(GLFWwindow* window);

public:
	glm::vec3 position;
	glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.f);
	glm::mat4 cameraMatrix = glm::mat4(1.f);

	int width, height;
	float speed = 0.025f;
	float sensitivity = 100.f;

	bool firstClick = true;
};