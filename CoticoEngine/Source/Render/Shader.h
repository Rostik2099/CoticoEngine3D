#pragma once
#include<glad/glad.h>
#include<glm/common.hpp>
#include<glm/matrix.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>

class Shader
{
public:
	Shader(const char* vertexFile, const char* fragmentFile);
	~Shader();

	void Activate();
	void Delete();
	std::string GetFileContents(const char* fileName);
	void SetMatrix(const char* name, glm::mat4 matrix);

private:
	void CompileErrors(unsigned int shader, const char* type);
public:
	GLuint ID;
};