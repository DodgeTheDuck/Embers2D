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

	class EMB_API CGuiBorder : public CGuiComponent {

	public:

		CGuiBorder(SceneObject* owner);
		virtual void DrawPass(GFX::ERenderPass pass);

	protected:
		virtual void _Rebuild(void);

	private:

		GFX::VBO* _vboTitle;
		GFX::VAO* _vaoTitle;

		GFX::VBO* _vboBorder;
		GFX::VAO* _vaoBorder;

		Shader* _shader;

	};

}