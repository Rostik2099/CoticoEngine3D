#include "FrameBuffer.h"

FrameBuffer::FrameBuffer()
{
	glGenFramebuffers(1, &FBID);
	glBindFramebuffer(GL_FRAMEBUFFER, FBID);
	FBTex = new FrameBufferTexture;

	glGenRenderbuffers(1, &RBID);
	glBindRenderbuffer(GL_RENDERBUFFER, RBID);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 800, 800);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, RBID);

	auto FBstatus = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (FBstatus != GL_FRAMEBUFFER_COMPLETE)
		std::cout << "FBO Error" << FBstatus << std::endl;
	
	glBindFramebuffer(GL_RENDERBUFFER, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}	

FrameBuffer::~FrameBuffer()
{
	glDeleteFramebuffers(1, &FBID);
}

GLuint FrameBuffer::GetTexID()
{
	return FBTex->ID;
}
