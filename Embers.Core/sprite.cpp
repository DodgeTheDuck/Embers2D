
#include "stdafx.h"
#include "sprite.h"
#include "material.h"
#include "texture.h"
#include "transform.h"

#include <Embers.Graphics/vbo.h>
#include <Embers.Graphics/vao.h>
#include <Embers.Graphics/gl.h>
#include <Embers.Graphics/mesh.h>

namespace CORE {

	CSprite::CSprite(SceneObject* owner) : Component(owner) {

		_vao = NULL;
		_vbo = NULL;

		_sprWidth = 0;
		_sprHeight = 0;

		_material = NULL;

		_cellIndex = 0;
		_frameTimer = 0;

		_dirty = true;

		_ox = 0;
		_oy = 0;

	}

	void CSprite::Tick(void) {
		//_frameTimer += 1;
		//if (_frameTimer >= 16) {
		//	_frameTimer = 0;
		//	_cellIndex++;
		//	_cellIndex %= 22;
		//	_Rebuild();
		//}
	}

	CSprite * CSprite::SetCellSize(uint32_t w, uint32_t h) {
		_sprWidth = w;
		_sprHeight = h;
		return this;
	};

	CSprite * CSprite::SetCellIndex(uint32_t index) {
		_cellIndex = index;
		return this;
	}

	CSprite* CSprite::SetOrigin(float x, float y) {
		_ox = x;
		_oy = y;
		return this;
	}

	void CSprite::PreDraw(void) {
		EMB_GL->PushMatrix(glm::translate(glm::mat4(1.0), glm::vec3(-_ox, -_oy, 0)));
	}

	void CSprite::Draw(void) {

		if (_dirty) {
			_Rebuild();			
		}		

		_material->Bind();
		_material->Update();
		_vao->Bind();		
		EMB_GL->DrawElements(GFX::EDrawStyle::TRIANGLES, 6);

	}

	void CSprite::PostDraw(void) {
		EMB_GL->PopMatrix();
	}

	void CSprite::DrawPass(GFX::ERenderPass pass) {

	}

	CSprite * CSprite::SetMaterial(Material* mat) {
		_material = mat;
		return this;
	}

	Material* CSprite::GetMaterial(void) {
		return _material;
	}

	void CSprite::_Rebuild(void) {

		delete(_vbo);
		delete(_vao);

		_vao = new GFX::VAO();
		_vao->Bind();


		float w = _sprWidth;
		float h = _sprHeight;

		_mesh = GFX::Mesh::Rect(0, 0, w, h, GFX::EDrawStyle::TRIANGLES);

		//TODO: Reimplement spritesheet cells/animation

		//int x = ceil(_cellIndex % 9);
		//int y = ceil(_cellIndex / 9);

		//uint32_t sepx = 0;
		//uint32_t sepy = 0;

		//double pw = (1.0 / _material->GetTexture(ETextureType::DIFFUSE)->GetWidth());
		//double ph = (1.0 / _material->GetTexture(ETextureType::DIFFUSE)->GetHeight());

		//float cw =  pw * _sprWidth;
		//float ch =  ph * _sprHeight;

		//float xs = cw * x + ((pw * sepx) * x);
		//float ys = ch * y + ((ph * sepy) * y);

		//_vbo = new GFX::VBO({
		//		 w-_ox,  h-_oy, 0.0f,     xs + cw, ys + ch,
		//		 w-_ox, -_oy, 0.0f,     xs + cw, ys,
		//		-_ox, -_oy, 0.0f,     xs, ys,
		//		-_ox,  h-_oy, 0.0f,     xs, ys + ch
		//	}, {
		//		0, 1, 3,
		//		1, 2, 3
		//	}
		//);

		_vbo = new GFX::VBO(_mesh);

		_vao->Unbind();

		_dirty = false;

	}

}