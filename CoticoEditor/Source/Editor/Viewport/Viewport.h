#pragma once
#include "EditorUI/ImGUILayer.h"
#include "Render/FrameBuffers/FrameBuffer.h"

class Viewport : public ImGUILayer
{
public:
	Viewport();
	void Render() override;

private:
	FrameBuffer* FB;
};

