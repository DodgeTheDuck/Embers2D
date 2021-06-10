
#include "stdafx.h"
#include "fbo.h"
#include "texture.h"
#include "gl.h"
#include "mesh.h"
#include "vao.h"
#include "vbo.h"


namespace GFX {

	FBO::FBO(uint32_t width, uint32_t height) {

		glGenFramebuffers(1, &_fbo);

		glBindFramebuffer(GL_FRAMEBUFFER, _fbo);
		
		glGenTextures(1, &_color);
		glBindTexture(GL_TEXTURE_2D, _color);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);

		uint32_t depthStenTex = 0;

		glGenTextures(1, &depthStenTex);
		glBindTexture(GL_TEXTURE_2D, depthStenTex);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, width, height, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, NULL);


		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _color, 0);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, depthStenTex, 0);

		GLenum DrawBuffers[1] = { GL_COLOR_ATTACHMENT0 };
		glDrawBuffers(1, DrawBuffers);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		_vao = new VAO();
		_vao->Bind();

		_mesh = Mesh::Rect(-1.0, -1.0, 2, 2, EDrawStyle::TRIANGLES);

		_vbo = new VBO(_mesh);

		_vao->Unbind();

	}

	void FBO::Bind(void) {
		glBindFramebuffer(GL_FRAMEBUFFER, _fbo);
	}

	void FBO::Clear(void) {
		glClear(GL_COLOR_BUFFER_BIT);
	}

	uint32_t FBO::Color(void) {
		return _color;
	}

	void FBO::Draw(void) {
		_vao->Bind();
		glBindTexture(GL_TEXTURE_2D, _color);
		GL::GetInstance()->DrawElementsScene(EDrawStyle::TRIANGLES, 6);
	}

	FBO::~FBO(void) {
		glDeleteFramebuffers(1, &_fbo);
	}

}