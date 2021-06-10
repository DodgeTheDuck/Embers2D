#pragma once

#include <Embers.Lib/dll.h>
#include "gl.h"
#include "vertex.h"

namespace GFX {

	class EMB_API Mesh {
		
	public:

		static Mesh Rect(float left, float top, float width, float height, EDrawStyle style, glm::vec4 color = { 1.0, 1.0, 1.0, 1.0 });
		std::vector<Vertex> Vertices(void);
		std::vector<uint32_t> Indices(void);
		void SetTexCoords(uint32_t index, glm::vec2 coords);

	private:
		std::vector<Vertex> _verts;
		std::vector<uint32_t> _indices;
		EDrawStyle _style;

	};

}