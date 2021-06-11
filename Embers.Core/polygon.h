#pragma once
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

	class EMB_API CPolygon : public Component {

	public:
		CPolygon(SceneObject* owner);

		void Tick(void);

		virtual void PreDraw(void);
		void Draw(void);
		virtual void PostDraw(void);

		virtual void DrawPass(GFX::ERenderPass pass);

		std::vector<glm::vec2> GetPoints(void);

		CPolygon* SetPoints(std::vector<glm::vec2> points);
		CPolygon* SetOrigin(float x, float y);
		CPolygon* SetMaterial(Material* mat);

		Material* GetMaterial(void);

	private:

		void _Rebuild(void);

		GFX::VBO* _vbo;
		GFX::VAO* _vao;
		GFX::Mesh _mesh;

		std::vector<glm::vec2> _points;

		bool _dirty;

		Material* _material;

		float _ox;
		float _oy;

	};

}