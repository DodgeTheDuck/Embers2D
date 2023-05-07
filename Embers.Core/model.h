#pragma once
#pragma once

#include <Embers.Lib/dll.h>
#include <Embers.Graphics/mesh.h>

#include "component.h"
#include <vector>

namespace GFX {
	class VAO;
	class VBO;
}

namespace CORE {

	class Material;

	class EMB_API CModel : public Component {

	public:
		CModel(SceneObject* owner);

		void Tick(void);

		virtual void PreDraw(void);
		void Draw(void);
		virtual void PostDraw(void);

		virtual void DrawPass(GFX::ERenderPass pass);

		std::vector<glm::vec3> GetPoints(void);

		CModel* FromFile(const char* path);
		CModel* SetPoints(std::vector<glm::vec3> points);
		CModel* SetOrigin(float x, float y, float z);
		CModel* SetMaterial(Material* mat);

		Material* GetMaterial(void);

	private:

		void _Rebuild(void);

		GFX::VBO* _vbo;
		GFX::VAO* _vao;
		GFX::Mesh _mesh;

		std::vector<glm::vec3> _points;
		std::vector<glm::vec3> _normals;
		std::vector<glm::vec2> _uvs;
		std::vector<uint32_t> _indices;

		bool _dirty;

		Material* _material;

		float _ox;
		float _oy;
		float _oz;

	};

}