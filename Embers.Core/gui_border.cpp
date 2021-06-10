#include "stdafx.h"
#include "gui_border.h"
#include "asset_bank.h"
#include "engine.h"
#include "shader.h"

#include <Embers.Graphics/vao.h>
#include <Embers.Graphics/vbo.h>
#include <Embers.Graphics/gl.h>
#include <Embers.Graphics/mesh.h>

namespace CORE {

	CGuiBorder::CGuiBorder(SceneObject* owner) : CGuiComponent(owner) {
		_shader = EMB_ASSET_BANK->GetAsset<Shader>("sha_gui");
	}

	void CGuiBorder::DrawPass(GFX::ERenderPass pass) {

		if (_isDirty) {
			_Rebuild();
			_isDirty = false;
		}

		switch (pass) {
		case GFX::ERenderPass::GUI:
			_shader->Bind();
			//_vaoTitle->Bind();
			//EMB_GL->DrawElements(GFX::EDrawStyle::TRIANGLES, 6);
			_vaoBorder->Bind();
			EMB_GL->DrawElements(GFX::EDrawStyle::LINES, 8);
			break;
		//case GFX::ERenderPass::BLUR_X:
		//	_vaoTitle->Bind();
		//	EMB_GL->DrawElements(GFX::EDrawStyle::TRIANGLES, 6);
		//	break;
		//case GFX::ERenderPass::BLUR_Y:
		//	_vaoTitle->Bind();
		//	EMB_GL->DrawElements(GFX::EDrawStyle::TRIANGLES, 6);
		//	break;
		}
	}

	void CGuiBorder::_Rebuild(void) {

		_vaoTitle = new GFX::VAO();
		_vaoTitle->Bind();
		_vboTitle = new GFX::VBO(GFX::Mesh::Rect(-1, -32, _width+2, 32, GFX::EDrawStyle::TRIANGLES, { 0.0, 0.0, 0.0, 0.8 }));
		_vaoTitle->Unbind();

		_vaoBorder = new GFX::VAO();
		_vaoBorder->Bind();
		_vboBorder = new GFX::VBO(GFX::Mesh::Rect(-1, -1, _width+2, _height+2, GFX::EDrawStyle::LINES, { 1.0, 1.0, 1.0, 0.7 }));
		_vaoBorder->Unbind();

	}

}