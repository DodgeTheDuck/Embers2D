#pragma once


class WorldGenerator {

public:
	WorldGenerator(uint32_t w, uint32_t h);
	void Generate(void);

	int GetTile(uint32_t x, uint32_t y);	

private:
	uint32_t _width;
	uint32_t _height;

	int** _tiles;

};