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
	virtual void Draw(Camera& camera);

	void SetShaders(const char* vertShader, const char* fragShader);
	void SetTexture(const char* texturePath);
	void SetLocation(CVector newLoc) override;
	void SetRotation(CVector newRot) override;
	void SetScale(CVector newScale) override;
	void SetTransform(CTransform newTransform) override;

protected:
	void UpdateMatrix();

protected:
	Mesh* mesh;
	Shader* shaderProgram = nullptr;
	glm::mat4 modelMatrix = glm::mat4(1.f);
};