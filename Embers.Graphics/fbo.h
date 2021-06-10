#pragma once

#include "mesh.h"
#include <Embers.Lib/dll.h>

namespace GFX {

	class VAO;
	class VBO;

	class EMB_API FBO {

	public:
		FBO(uint32_t width, uint32_t height);

		void Bind(void);
		uint32_t Color(void);
		void Draw(void);
		void Clear(void);

		~FBO(void);

	private:
		unsigned int _fbo;

		uint32_t _color;
		VAO * _vao;
		VBO * _vbo;
		Mesh _mesh;

	};

}