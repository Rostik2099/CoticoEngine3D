#pragma once
#include"BaseComponent.h"
#include"Render/Mesh.h"

class MeshComponent : public BaseComponent
{
public:
	MeshComponent();
	~MeshComponent();

	Mesh* GetMesh() { return this->mesh; };
	virtual void Draw(Camera& camera);

	void SetShaders(const char* vertShader, const char* fragShader);
	void SetTexture(const char* texturePath);
private:
	Mesh* mesh;
	Shader* shaderProgram = nullptr;
};