#pragma once

#include <Embers.Lib/dll.h>
#include <Embers.Graphics/gl.h>
#include "gui_component.h"

namespace GFX {
	class VBO;
	class VAO;
}

namespace CORE {

	class Shader;

	class EMB_API CGuiPanel : public CGuiComponent {

	public:

		CGuiPanel(SceneObject* owner);
		virtual void DrawPass(GFX::ERenderPass pass);

	protected:
		virtual void _Rebuild(void);

	private:

		GFX::VBO* _vbo;
		GFX::VAO* _vao;

		Shader* _shader;

	};

}