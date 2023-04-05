#pragma once
#include"Components/MeshComponent.h"

class CubeMapComponent : public MeshComponent
{
public:
	CubeMapComponent();
	~CubeMapComponent();

	Mesh* GetMesh() { return this->mesh; };
	void Draw(Camera& camera) override;
private:
	Mesh* mesh;
	Shader* skyboxShader;
};