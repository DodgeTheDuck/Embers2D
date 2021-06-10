
#include "stdafx.h"
#include "text.h"
#include "texture.h"
#include "shader.h"
#include "asset_bank.h"
#include "engine.h"

#include <Embers.Graphics/gl.h>
#include <Embers.Graphics/texture.h>
#include <Embers.Graphics/vao.h>
#include <Embers.Graphics/vbo.h>

namespace CORE {

	Text::Text(const std::string& text) {
		_text = text;
		_dirty = true;
		_shader = EMB_ASSET_BANK->GetAsset<CORE::Shader>("sha_sprite");
		_texture = EMB_ASSET_BANK->GetAsset<CORE::Texture>("tex_text");
	}

	void Text::Draw(void) {
		
		if (_dirty) {
			_Rebuild();
		}

		_shader->Bind();
		_texture->Bind();

		for (int i = 0; i < _vao.size(); i++) {
			_vao[i]->Bind();
			//EMB_GL->DrawElements();			
		}

	}

	void Text::Append(const std::string& text) {
		_text += text;
		_dirty = true;
	}

	void Text::Set(const std::string& text) {
		_text = text;
		_dirty = true;
	}

	void Text::Clear(void) {
		_text = "";
		_dirty = true;
	}

	void Text::_Rebuild(void) {

		for (int i = 0; i < _vao.size(); i++) {
			delete(_vao[i]);
			delete(_vbo[i]);
		}

		_vbo.clear();
		_vao.clear();

		for (int i = 0; i < _text.length(); i++) {

			GFX::VAO* vao = new GFX::VAO();
			vao->Bind();

			char c = _text[i];

			int x = ceil(c % 16);
			int y = ceil(c / 16);

			float xs = (1.0f / 16.0f) * x;
			float ys = (1.0f / 16.0f) * y;

			float cw = 1.0f / 16.0f;
			float ch = 1.0f / 16.0f;

			GFX::VBO* vbo = new GFX::VBO({
					 5.0f + i * 10,  6.0f + 256, 0.0f,   xs + cw, ys + ch,
					 5.0f + i * 10, -6.0f+256, 0.0f,     xs + cw, ys,
					-5.0f + i * 10, -6.0f+256, 0.0f,     xs, ys,
					-5.0f + i * 10,  6.0f+256, 0.0f,     xs, ys + ch
				}, {
					0, 1, 3,
					1, 2, 3
				}
			);

			_vbo.push_back(vbo);
			_vao.push_back(vao);

		}

		_dirty = false;

	}


}