
#include "stdafx.h"
#include "tile.h"
#include "world.h"

#include <Embers.Graphics/mesh.h>
#include <Embers.Graphics/vao.h>
#include <Embers.Graphics/vbo.h>
#include <Embers.Graphics/gl.h>

Tile::Tile(ETileType id) {
	Id = id;
	_vao = NULL;
	_vbo = NULL;
	_dirty = true;
}

void Tile::Draw(void) {

	if (Id > 0) {

		if (_dirty) {
			Rebuild();
			_dirty = false;
		}

		_vao->Bind();
		EMB_GL->DrawElements(GFX::EDrawStyle::TRIANGLES, 6);
	}

}

void Tile::Rebuild(void) {

	delete _vao;
	delete _vbo;

	GFX::VAO* vao = new GFX::VAO();
	vao->Bind();

	int x = ceil(Id % 4);
	int y = ceil(Id / 4);

	double pw = (1.0 / 128.0);
	double ph = (1.0 / 256.0);

	float cw = pw * 32.0f;
	float ch = ph * 32.0f;

	float xs = cw * x + ((pw * 0) * x);
	float ys = ch * y + ((ph * 0) * y);

	GFX::Mesh mesh = GFX::Mesh::Rect(0, 0, World::TILE_SIZE, World::TILE_SIZE, GFX::EDrawStyle::TRIANGLES);

	mesh.SetTexCoords(0, glm::vec2(xs, ys));
	mesh.SetTexCoords(1, glm::vec2(xs + cw, ys));
	mesh.SetTexCoords(2, glm::vec2(xs + cw, ys + ch));
	mesh.SetTexCoords(3, glm::vec2(xs, ys + ch));

	GFX::VBO* vbo = new GFX::VBO(mesh);

	_vbo = vbo;
	_vao = vao;

};