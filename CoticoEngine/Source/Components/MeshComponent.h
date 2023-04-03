#pragma once
#include"BaseComponent.h"
#include"Render/Mesh.h"

class MeshComponent : public BaseComponent
{
public:
	MeshComponent();
	~MeshComponent();

	Mesh* GetMesh() { return this->mesh; };
private:
	Mesh* mesh;
};