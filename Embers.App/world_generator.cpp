
#include "stdafx.h"
#include "world_generator.h"
#include "tile.h"
#include <time.h>

WorldGenerator::WorldGenerator(uint32_t w, uint32_t h) {

	srand(time(NULL));

	_width = w;
	_height = h;

	_tiles = (int**)calloc(w, sizeof(int*));

	if (_tiles) {
		for (int x = 0; x < w; x++) {
			_tiles[x] = (int*)calloc(h, sizeof(int));
			if (_tiles[x]) {
				for (int y = 0; y < h; y++) {
					_tiles[x][y] = 0;
				}
			}
		}
	}

}

void WorldGenerator::Generate(void) {

	float floorHeight = _height;
	float stoneHeight = _height/2;

	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			_tiles[x][y] = ETileType::GRASS;			
		}
		floorHeight += (rand() % 200 - 50) / 100.0;
		stoneHeight += (rand() % 200 - 100) / 100.0;
	}

}

int WorldGenerator::GetTile(uint32_t x, uint32_t y) {
	return _tiles[x][y];
}