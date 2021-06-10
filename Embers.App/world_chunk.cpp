
#include "stdafx.h"
#include "world_chunk.h"
#include "world.h"
#include "tile.h"
#include "world_generator.h"

#include <Embers.Core/texture.h>
#include <Embers.Core/engine.h>
#include <Embers.Core/asset_bank.h>

#include <Embers.Graphics/mesh.h>
#include <Embers.Graphics/fbo.h>
#include <Embers.Graphics/vbo.h>
#include <Embers.Graphics/vao.h>
#include <Embers.Graphics/gl.h>

WorldChunk::WorldChunk(WorldGenerator * generator, uint32_t offx, uint32_t offy, uint32_t w, uint32_t h) {

	_width = w;
	_height = h;
	_dirty = true;

	_tiles = (Tile**)calloc(w, sizeof(Tile*));
	for (int x = 0; x < w; x++) {
		_tiles[x] = (Tile*)calloc(h, sizeof(Tile));		
		for (int y = 0; y < h; y++) {
			_tiles[x][y] = Tile((ETileType)generator->GetTile((offx * w) + x, (offy * h) + y));
		}
	}

	_texture = EMB_ASSET_BANK->GetAsset<CORE::Texture>("tex_tileset");

	int fboW = w * World::TILE_SIZE;
	int fboH = h * World::TILE_SIZE;

	_fbo = new GFX::FBO(fboW, fboH);
	_vao = new GFX::VAO();
	_vao->Bind();

	GFX::Mesh mesh = GFX::Mesh::Rect(0, 0, fboW, fboH, GFX::EDrawStyle::TRIANGLES);
	mesh.SetTexCoords(0, glm::vec2(0, 1));
	mesh.SetTexCoords(1, glm::vec2(1, 1));
	mesh.SetTexCoords(2, glm::vec2(1, 0));
	mesh.SetTexCoords(3, glm::vec2(0, 0));

	_vbo = new GFX::VBO(mesh);


	_vaoBorder = new GFX::VAO();
	_vaoBorder->Bind();
	_vboBorder = new GFX::VBO(GFX::Mesh::Rect(-1, -1, fboW + 2, fboH + 2, GFX::EDrawStyle::LINES, { 1.0, 0.0, 0.0, 1.0 }));
	_vaoBorder->Unbind();

}

void WorldChunk::Draw(uint32_t column, uint32_t row) {

	if (_dirty) {

		glm::mat4 view = EMB_GL->GetView();
		glm::mat4 proj = EMB_GL->GetProjection();

		float fboW = _width * World::TILE_SIZE;
		float fboH = _height * World::TILE_SIZE;		

		EMB_GL->Viewport(0, 0, _width * World::TILE_SIZE, _height * World::TILE_SIZE);

		EMB_GL->ClearView();
		EMB_GL->SetProjection(glm::ortho(0.0f, fboW, fboH, 0.0f, -1.0f, 1.0f));

		_fbo->Bind();
		_fbo->Clear();
		_texture->Bind();
		for (int x = 0; x < _width; x++) {
			for (int y = 0; y < _height; y++) {
				Tile tile = _tiles[x][y];
				EMB_GL->PushMatrix(glm::translate(glm::mat4(1.0), glm::vec3(x * World::TILE_SIZE, y * World::TILE_SIZE, 0)));
				tile.Draw();
				EMB_GL->PopMatrix();
			}
		}
		_dirty = false;

		EMB_GL->RebindRenderPass();
		EMB_GL->SetView(view);
		EMB_GL->SetProjection(proj);
		EMB_GL->Viewport(0, 0, 1024, 768);
	}
	
	_vao->Bind();
	EMB_GL->PushMatrix(glm::translate(glm::mat4(1.0), glm::vec3(column * World::TILE_SIZE * World::CHUNK_SIZE, row * World::TILE_SIZE * World::CHUNK_SIZE, 0)));
	EMB_GL->BindTexture(_fbo->Color());
	EMB_GL->DrawElements(GFX::EDrawStyle::TRIANGLES, 6);

	//_vaoBorder->Bind();
	//EMB_GL->BindTexture(0);
	//EMB_GL->DrawElements(GFX::EDrawStyle::LINES, 8);

	EMB_GL->PopMatrix();


}

Tile& WorldChunk::GetTile(uint32_t x, uint32_t y) {
	return _tiles[x][y];
}

void WorldChunk::_Rebuild(void) {

	//delete _vao;
	//delete _vbo;

	//GFX::VAO* vao = new GFX::VAO();
	//vao->Bind();

	//int x = ceil(c % 16);
	//int y = ceil(c / 16);

	//float xs = (1.0f / 16.0f) * x;
	//float ys = (1.0f / 16.0f) * y;

	//float cw = 1.0f / 16.0f;
	//float ch = 1.0f / 16.0f;

	//GFX::Mesh mesh = GFX::Mesh::Rect(colNum * _cellWidth * _size, 20 * lineNum, _cellWidth * _size, _cellHeight * _size, GFX::EDrawStyle::TRIANGLES);

	//mesh.SetTexCoords(0, glm::vec2(xs, ys));
	//mesh.SetTexCoords(1, glm::vec2(xs + cw, ys));
	//mesh.SetTexCoords(2, glm::vec2(xs + cw, ys + ch));
	//mesh.SetTexCoords(3, glm::vec2(xs, ys + ch));

	//GFX::VBO* vbo = new GFX::VBO(mesh);

	//_vbo.push_back(vbo);
	//_vao.push_back(vao);

}