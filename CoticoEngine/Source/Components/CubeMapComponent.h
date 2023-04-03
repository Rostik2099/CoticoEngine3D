#pragma once
#include"Components/MeshComponent.h"

class CubeMapComponent : public MeshComponent
{
public:
	CubeMapComponent();
	~CubeMapComponent();

	Mesh* GetMesh() { return this->mesh; };
	void Draw(Shader& shader, Camera& camera) override;
private:
	Mesh* mesh;
	Shader* skyboxShader;
};