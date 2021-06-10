
#include "stdafx.h"
#include "gui_text_block.h"
#include "asset.h"
#include "engine.h"
#include "shader.h"
#include "texture.h"

#include <Embers.Graphics/vao.h>
#include <Embers.Graphics/vbo.h>
#include <Embers.Graphics/mesh.h>
#include <Embers.Graphics/gl.h>

namespace CORE {

	CGuiTextBlock::CGuiTextBlock(SceneObject* owner) : CGuiComponent(owner) {
		_shader = EMB_ASSET_BANK->GetAsset<Shader>("sha_text");
		_texture = EMB_ASSET_BANK->GetAsset<Texture>("tex_text");
		_cellWidth = 10;
		_cellHeight = 12;
		_size = 1.0f;
		_dirty = true;
	}

	CGuiTextBlock* CGuiTextBlock::SetText(const std::string& text) {
		_text = text;
		_dirty = true;
		return this;
	}

	CGuiTextBlock* CGuiTextBlock::Append(const std::string& text) {
		_text += text;
		_dirty = true;
		return this;
	}

	void CGuiTextBlock::DrawPass(GFX::ERenderPass pass) {

		if (pass == GFX::ERenderPass::GUI) {
			if (_dirty) {
				_Rebuild();
			}

			_shader->Bind();
			_texture->Bind();

			for (int i = 0; i < _vao.size(); i++) {
				_vao[i]->Bind();
				EMB_GL->DrawElements(GFX::EDrawStyle::TRIANGLES, 6);
			}
		}

	}

	void CGuiTextBlock::_Rebuild(void) {

		for (int i = 0; i < _vao.size(); i++) {
			delete(_vao[i]);
			delete(_vbo[i]);
		}

		_vao.clear();
		_vbo.clear();

		int lineNum = 0;
		int colNum = 0;

		for (int i = 0; i < _text.length(); i++) {


			char c = _text[i];

			if (c == '\n') {
				lineNum++;
				colNum = 0;
			} else {

				GFX::VAO* vao = new GFX::VAO();
				vao->Bind();

				int x = ceil(c % 16);
				int y = ceil(c / 16);

				float xs = (1.0f / 16.0f) * x;
				float ys = (1.0f / 16.0f) * y;

				float cw = 1.0f / 16.0f;
				float ch = 1.0f / 16.0f;

				_mesh = GFX::Mesh::Rect(colNum * _cellWidth * _size, 20 * lineNum, _cellWidth * _size, _cellHeight * _size, GFX::EDrawStyle::TRIANGLES);

				_mesh.SetTexCoords(0, glm::vec2(xs, ys));
				_mesh.SetTexCoords(1, glm::vec2(xs + cw, ys));
				_mesh.SetTexCoords(2, glm::vec2(xs + cw, ys + ch));
				_mesh.SetTexCoords(3, glm::vec2(xs, ys + ch));

				GFX::VBO* vbo = new GFX::VBO(_mesh);

				_vbo.push_back(vbo);
				_vao.push_back(vao);

				colNum++;

			}

		}

		_dirty = false;

	}

}
