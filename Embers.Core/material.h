#pragma once

#include "material_color_property.h"
#include "asset.h"

namespace CORE {

	class Texture;
	class Shader;
	class MaterialColorProperty;

	enum ETextureType : int {
		DIFFUSE
	};

	class EMB_API Material : public Asset {

	public:
		Material(void);
		void Bind(void);
		void Update(void);
		void SetShader(Shader* shader);
		Texture* GetTexture(ETextureType type);
		void SetTexture(ETextureType type, CORE::Texture* texture);

	private:
		Shader* _shader;
		MaterialColorProperty _diffuse;
		std::map<ETextureType, CORE::Texture*> _textures;

		std::map<ETextureType, CORE::MaterialColorProperty*> _colorProps;

	};

}
