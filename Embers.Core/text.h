#pragma once

#include <Embers.Lib/dll.h>

namespace GFX {
	class VAO;
	class VBO;
}

namespace CORE {	

	class Texture;
	class Shader;

	class EMB_API Text {

	public:
		Text(const std::string &text = "");		
		void Append(const std::string &text);
		void Set(const std::string& text);
		void Clear(void);
		void Draw(void);

	private:
		void _Rebuild(void);

		bool _dirty;
		std::string _text;

		std::vector<GFX::VBO*> _vbo;
		std::vector<GFX::VAO*> _vao;
		CORE::Texture* _texture;
		CORE::Shader* _shader;


	};

}