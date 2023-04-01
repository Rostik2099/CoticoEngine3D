#pragma once
#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>

class Shader
{
public:
	Shader(const char* vertexFile, const char* fragmentFile);

	void Activate();
	void Delete();
	std::string GetFileContents(const char* fileName);

public:
	GLuint ID;
};