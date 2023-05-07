#include "stdafx.h"

#include "spritesheet.h"
#include "shader.h"
#include "engine.h"

namespace CORE {

	Spritesheet::Spritesheet(Texture* texture, int cellWidth, int cellHeight) {
		_texture = texture;
		_cellWidth = cellWidth;
		_cellHeight = cellHeight;
		_shader = EMB_ASSET_BANK->GetAsset<Shader>("sha_sprite");
	}

	void Spritesheet::Bind(void) {
		_shader->Bind();
		_texture->Bind();
	}

}