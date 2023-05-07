#pragma once

#include <Embers.Lib/dll.h>
#include <Embers.Graphics/mesh.h>

#include "component.h"

namespace GFX {
	class VAO;
	class VBO;
}

namespace CORE {

	class Material;
	class Spritesheet;

	class EMB_API CSprite : public Component {

	public:
		CSprite(SceneObject* owner);

		void Tick(void);

		virtual void PreDraw(void);
		void Draw(void);
		virtual void PostDraw(void);

		virtual void DrawPass(GFX::ERenderPass pass);

		CSprite* SetOrigin(float x, float y);
		CSprite* SetCellSize(uint32_t w, uint32_t h);
		CSprite* SetCellIndex(uint32_t index);
		//CSprite* SetMaterial(Material* mat);
		CSprite* SetSpritesheet(Spritesheet* sheet);

		//Material* GetMaterial(void);

	private:

		void _Rebuild(void);

		Spritesheet* _spriteSheet;

		GFX::VBO* _vbo;
		GFX::VAO* _vao;
		GFX::Mesh _mesh;

		bool _dirty;

		//Material* _material;

		uint32_t _sprWidth;
		uint32_t _sprHeight;

		uint32_t _cellIndex;

		uint32_t _frameTimer;

		float _ox;
		float _oy;

	};

}