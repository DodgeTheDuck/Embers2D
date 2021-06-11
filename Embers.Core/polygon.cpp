

#include "stdafx.h"
#include "polygon.h"
#include "material.h"
#include "texture.h"
#include "transform.h"

#include <Embers.Graphics/vbo.h>
#include <Embers.Graphics/vao.h>
#include <Embers.Graphics/gl.h>
#include <Embers.Graphics/mesh.h>

namespace CORE {

	CPolygon::CPolygon(SceneObject* owner) : Component(owner) {

		_vao = NULL;
		_vbo = NULL;

		_material = NULL;

		_dirty = true;

		_ox = 0;
		_oy = 0;

	}

	void CPolygon::Tick(void) {

	}

	CPolygon* CPolygon::SetPoints(std::vector<glm::vec2> points) {
		_points = points;
		return this;
	}

	CPolygon* CPolygon::SetOrigin(float x, float y) {
		_ox = x;
		_oy = y;
		return this;
	}

	void CPolygon::PreDraw(void) {
		EMB_GL->PushMatrix(glm::translate(glm::mat4(1.0), glm::vec3(-_ox, -_oy, 0)));
	}

	void CPolygon::Draw(void) {

		if (_dirty) {
			_Rebuild();
		}

		_material->Bind();
		_material->Update();
		_vao->Bind();
		EMB_GL->DrawElements(GFX::EDrawStyle::LINES, _points.size()*2 + 2);

	}

	void CPolygon::PostDraw(void) {
		EMB_GL->PopMatrix();
	}

	void CPolygon::DrawPass(GFX::ERenderPass pass) {

	}

	CPolygon* CPolygon::SetMaterial(Material* mat) {
		_material = mat;
		return this;
	}

	std::vector<glm::vec2> CPolygon::GetPoints(void) {
		return _points;
	}

	Material* CPolygon::GetMaterial(void) {
		return _material;
	}

	void CPolygon::_Rebuild(void) {

		delete(_vbo);
		delete(_vao);

		_vao = new GFX::VAO();
		_vao->Bind();

		_mesh = GFX::Mesh::Polygon(_points, GFX::EDrawStyle::TRIANGLES);	

		_vbo = new GFX::VBO(_mesh);

		_vao->Unbind();

		_dirty = false;

	}

}