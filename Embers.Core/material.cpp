
#include "stdafx.h"
#include "material.h"

#include "texture.h"
#include "shader.h"
#include "engine.h"
#include "asset_bank.h"

namespace CORE {

	Material::Material(void) {
		_shader = NULL;		
		//_diffuse.SetColor(RGB_32(0, 255, 0));		
	}

	void Material::Bind(void) {
		_shader->Bind();
		_textures[ETextureType::DIFFUSE]->Bind();
	}

	void Material::Update(void) {
		//_shader->SetVec3("matDiffuse", _diffuse.GetColor().r, _diffuse.GetColor().g, _diffuse.GetColor().b);
	}

	void Material::SetShader(Shader* shader) {
		_shader = shader;
	}

	Texture* Material::GetTexture(ETextureType type) {
		return _textures[type];
	}

	void Material::SetTexture(ETextureType type, CORE::Texture* texture) {
		_textures[type] = texture;
	};

}
