#pragma once

namespace GFX {
	class VAO;
	class VBO;
}

enum ETileType {
	AIR,
	GRASS,
	SOIL,
	STONE
};

class Tile {

public:
	Tile(ETileType id);
	void Draw(void);

	void Rebuild(void);

	ETileType Id;

private:

	bool _dirty;

	GFX::VAO* _vao;
	GFX::VBO* _vbo;

};