#pragma once

#include <Embers.Graphics/mesh.h>;

class Tile;

namespace CORE {
	class Texture;
	class Spritesheet;
}

namespace GFX {
	class FBO;
	class VAO;
	class VBO;	
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

	GFX::Mesh _chunkMesh;
	GFX::Mesh _outlineMesh;

	CORE::Spritesheet* _tileset;

	Tile** _tiles;

};