#pragma once

#include "gui_component.h"

#include <Embers.Lib/dll.h>
#include <Embers.Graphics/mesh.h>

namespace GFX {
	class VBO;
	class VAO;
}

namespace CORE {

	class Texture;
	class Shader;

	class EMB_API CGuiTextBlock : public CGuiComponent {

	public:

		CGuiTextBlock(SceneObject* owner);
		virtual CGuiTextBlock* SetText(const std::string& text);
		virtual CGuiTextBlock* Append(const std::string& text);
		virtual void DrawPass(GFX::ERenderPass pass);

	private:

		void _Rebuild(void);

		std::vector<std::string> _lines;

		std::string _text;

		bool _dirty;

		GFX::Mesh _mesh;
		std::vector<GFX::VBO*> _vbo;
		std::vector<GFX::VAO*> _vao;

		Texture * _texture;
		Shader* _shader;

		uint32_t _cellWidth;
		uint32_t _cellHeight;

		float _size;

	};

}