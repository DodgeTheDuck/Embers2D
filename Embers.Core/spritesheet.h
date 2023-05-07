#pragma once

#include "asset.h"
#include "texture.h"
#include <string>

namespace CORE {

	class Shader;

	class EMB_API Spritesheet : public Asset {

	public:
		Spritesheet(Texture * t, int cellWidth, int cellHeight);
		void Bind(void);

		int GetWidth(void);
		int GetHeight(void);

	private:
		
		Texture* _texture;
		int _cellWidth;
		int _cellHeight;
		Shader* _shader;

	};

}