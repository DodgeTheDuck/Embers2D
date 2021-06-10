
#include "stdafx.h"
#include "world.h"

#include "world_chunk.h"

#include <Embers.Core/material.h>
#include <Embers.Core/sprite.h>
#include <Embers.Core/debug.h>
#include <Embers.Core/metrics.h>
#include <Embers.Core/rigid_body.h>
#include <Embers.Core/engine.h>
#include <Embers.Core/asset_bank.h>
#include <Embers.Core/texture.h>
#include <Embers.Core/shader.h>
#include <Embers.Core/transform.h>
#include "world_generator.h"

#include <Embers.Core/ef_impulse.h>

#include <Embers.Graphics/gl.h>

World::World(uint32_t w, uint32_t h) {

	_columns = w;
	_rows = h;

	EMB_DEBUG->Metrics()->AddMetric("Tiles");
	EMB_DEBUG->Metrics()->AddMetric("Chunks");

	EMB_DEBUG->Metrics()->UpdateMetric("Tiles", w * CHUNK_SIZE * h * CHUNK_SIZE);
	EMB_DEBUG->Metrics()->UpdateMetric("Chunks", w * h);

	WorldGenerator* generator = new WorldGenerator(w * CHUNK_SIZE, h * CHUNK_SIZE);
	generator->Generate();
	
	_chunks = (WorldChunk***)calloc(_columns, sizeof(WorldChunk**));

	for (int x = 0; x < _columns; x++) {
		_chunks[x] = (WorldChunk**)calloc(_rows, sizeof(WorldChunk*));
		for (int y = 0; y < _rows; y++) {
			_chunks[x][y] = new WorldChunk(generator, x, y, CHUNK_SIZE, CHUNK_SIZE);
		}
	}

	_shader = EMB_ASSET_BANK->GetAsset<CORE::Shader>("sha_sprite");

}

void World::Tick(void) {

}

void World::Draw(void) {

	_shader->Bind();


	for (int x = 0; x < _columns; x++) {
		for (int y = 0; y < _rows; y++) {
			_chunks[x][y]->Draw(x, y);
		}
	}

}

Tile& World::TileAt(uint32_t x, uint32_t y) {

	uint32_t wx = x / World::TILE_SIZE;
	uint32_t wy = y / World::TILE_SIZE;

	uint32_t cx = 0;
	uint32_t cy = 0;

	if (wx > 0) {
		cx = floor(wx / World::CHUNK_SIZE);
	}
	if (wy > 0) {
		cy = floor(wy / World::CHUNK_SIZE);
	}

	WorldChunk* chunk = _chunks[cx][cy];

	return chunk->GetTile(wx - (cx * CHUNK_SIZE), wy - (cy * CHUNK_SIZE));

}