#pragma once
#include"BaseComponent.h"
#include"Types/CVector.h"
#include"Render/Mesh.h"

class MeshComponent : public BaseComponent
{
public:
	MeshComponent();
	~MeshComponent();

	Mesh* GetMesh() { return this->mesh; };
	CVector GetLocation() { return this->location; };
	virtual void Draw(Camera& camera);

	void SetShaders(const char* vertShader, const char* fragShader);
	void SetTexture(const char* texturePath);
	void SetLocation(CVector newLoc);

protected:
	Mesh* mesh;
	Shader* shaderProgram = nullptr;
	CVector location;
};