#pragma once

#include <Embers.Lib/dll.h>
#include "asset.h"

namespace GFX {
	class Texture;
}

namespace CORE {

	class EMB_API Texture : public Asset {

	public:	
		Texture(std::string& path);
		void Bind(void);

		int GetWidth(void);
		int GetHeight(void);

	private:
		GFX::Texture * _glTex;

		int _width;
		int _height;
		int _nChannels;

	};

}