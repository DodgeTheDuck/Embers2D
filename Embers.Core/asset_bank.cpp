
#include "stdafx.h"
#include "asset_bank.h"

#include <Embers.Def/loader.h>

#include "texture.h"
#include "shader.h"
#include "spritesheet.h"
#include "material.h"

namespace CORE {

	void AssetBank::Load(void) {

		DEF::DefProperties propsTex = DEF::Loader::Load("./def/texture.emb_def");

		for (DEF::DefProperties::iterator it = propsTex.begin(); it != propsTex.end(); ++it) {
			std::string key = it->first;
			Texture* value = new Texture(propsTex[key][0]);
			_assets[key] = value;
		}

		DEF::DefProperties propsShader = DEF::Loader::Load("./def/shader.emb_def");

		for (DEF::DefProperties::iterator it = propsShader.begin(); it != propsShader.end(); ++it) {
			std::string key = it->first;
			Shader* value = new Shader(propsShader[key][0], propsShader[key][1]);
			_assets[key] = value;
		}

		DEF::DefProperties propsMaterial = DEF::Loader::Load("./def/material.emb_def");

		for (DEF::DefProperties::iterator it = propsMaterial.begin(); it != propsMaterial.end(); ++it) {
			std::string key = it->first;
			Material* value = new Material();

			value->SetShader(GetAsset<Shader>(propsMaterial[key][0]));
			value->SetTexture(ETextureType::DIFFUSE, GetAsset<Texture>(propsMaterial[key][1]));

			_assets[key] = value;
		}

		DEF::DefProperties propsSprites = DEF::Loader::Load("./def/sprites.emb_def");

		for (DEF::DefProperties::iterator it = propsSprites.begin(); it != propsSprites.end(); ++it) {
			std::string key = it->first;
			Spritesheet* value = new Spritesheet(GetAsset<Texture>(propsSprites[key][0]), std::stoi(propsSprites[key][1]), std::stoi(propsSprites[key][2]));
			_assets[key] = value;
		}

	}

}