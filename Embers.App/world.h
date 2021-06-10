#pragma once

#include <Embers.Core/entity.h>
#include "tile.h"

class WorldChunk;

namespace CORE {
	class Shader;
}

class World : public CORE::Entity {

public:
	World(uint32_t w, uint32_t h);
	virtual void Tick(void);
	virtual void Draw(void);

	Tile& TileAt(uint32_t x, uint32_t y);

	static const uint32_t TILE_SIZE = 32;
	static const uint32_t CHUNK_SIZE = 32;

private:

	uint32_t _columns;
	uint32_t _rows;

	WorldChunk*** _chunks;

	CORE::Shader* _shader;

};