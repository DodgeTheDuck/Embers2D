
#include "stdafx.h"
#include "texture.h"

namespace GFX {

	Texture::Texture(unsigned char * data, int width, int height, int channels) {

		glGenTextures(1, &_texture);
		glBindTexture(GL_TEXTURE_2D, _texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		if (channels == 4) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		}
		else {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}

		glGenerateMipmap(GL_TEXTURE_2D);

	}

	void Texture::Bind(void) {
		glBindTexture(GL_TEXTURE_2D, _texture);
	}

	uint32_t Texture::GetHandle(void) {
		return _texture;
	}

	Texture::~Texture(void) {
		glDeleteTextures(1, &_texture);
	}

}