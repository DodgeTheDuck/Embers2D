#pragma once

class Tile;

namespace CORE {
	class Texture;
}

namespace GFX {
	class FBO;
	class VAO;
	class VBO;
	class Mesh;
}

class WorldGenerator;

class WorldChunk {


public:
	WorldChunk(WorldGenerator * generator, uint32_t offx, uint32_t offy, uint32_t w, uint32_t h);
	void Draw(uint32_t column, uint32_t row);

	Tile& GetTile(uint32_t x, uint32_t y);

private:

	void _Rebuild(void);

	bool _dirty;

	uint32_t _width;
	uint32_t _height;

	GFX::FBO * _fbo;

	GFX::VAO * _vao;
	GFX::VBO * _vbo;

	GFX::VBO* _vboBorder;
	GFX::VAO* _vaoBorder;

	CORE::Texture* _texture;

	Tile** _tiles;

};