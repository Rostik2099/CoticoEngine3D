#include "FrameBuffer.h"
#include<iostream>

FrameBuffer::FrameBuffer()
{
	glGenFramebuffers(1, &FBID);
	glBindFramebuffer(GL_FRAMEBUFFER, FBID);

	glGenTextures(1, &TexID);
	glBindTexture(GL_TEXTURE_2D, TexID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 800, 800, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, TexID, 0);
	
	glGenRenderbuffers(1, &RBID);
	glBindRenderbuffer(GL_RENDERBUFFER, RBID);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 800, 800);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, RBID);
	
	auto FBstatus = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (FBstatus != GL_FRAMEBUFFER_COMPLETE)
		std::cout << "FBO Error" << FBstatus << std::endl;
	
	glBindFramebuffer(GL_RENDERBUFFER, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
}	

FrameBuffer::~FrameBuffer()
{
	glDeleteFramebuffers(1, &FBID);
}