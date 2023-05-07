#include "stdafx.h"

#include "gui_panel.h"
#include "asset_bank.h"
#include "engine.h"
#include "shader.h"

#include <Embers.Graphics/vao.h>
#include <Embers.Graphics/vbo.h>
#include <Embers.Graphics/gl.h>
#include <Embers.Graphics/mesh.h>

namespace CORE {

	CGuiPanel::CGuiPanel(SceneObject* owner) : CGuiComponent(owner) {
		_vao = NULL;
		_vbo = NULL;
		_shader = EMB_ASSET_BANK->GetAsset<Shader>("sha_gui");
	}

	void CGuiPanel::DrawPass(GFX::ERenderPass pass) {

		if (_isDirty) {
			_Rebuild();
			_isDirty = false;
		}

		switch (pass) {
		case GFX::ERenderPass::GUI:
			_shader->Bind();
			_vao->Bind();
			EMB_GL->DrawElements(GFX::EDrawStyle::TRIANGLES, 6);
			break;
		case GFX::ERenderPass::BLUR_X:
			_vao->Bind();
			EMB_GL->DrawElements(GFX::EDrawStyle::TRIANGLES, 6);
			break;
		case GFX::ERenderPass::BLUR_Y:
			_vao->Bind();
			EMB_GL->DrawElements(GFX::EDrawStyle::TRIANGLES, 6);
			break;
		}

	}

	void CGuiPanel::_Rebuild(void) {

		delete(_vao);
		delete(_vbo);

		_vao = new GFX::VAO();
		_vao->Bind();
		_vbo = new GFX::VBO(GFX::Mesh::Rect(0, 0, _width, _height, GFX::EDrawStyle::TRIANGLES, { 0.0, 0.0, 0.0, 0.65 }));
		_vao->Unbind();

	}

}