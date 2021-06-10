#pragma once

namespace GFX {

	class Mesh;

	class EMB_API VBO {

	public:
		VBO(std::vector<float> verts, std::vector<uint32_t> indices);
		VBO(Mesh mesh);
		~VBO(void);

	private:
		uint32_t _vbo;
		uint32_t _ebo;

	};

}