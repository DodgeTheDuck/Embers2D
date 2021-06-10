
#include "stdafx.h"
#include "texture.h"

#include <Embers.Graphics/texture.h>

namespace CORE {

	Texture::Texture(std::string& path) {

		unsigned char * data = stbi_load(path.c_str(), &_width, &_height, &_nChannels, 0);

		_glTex = new GFX::Texture(data, _width, _height);
	}

	void Texture::Bind(void) {
		_glTex->Bind();
	}

	int Texture::GetWidth(void) {
		return _width;
	}

	int Texture::GetHeight(void) {
		return _height;
	}

}
