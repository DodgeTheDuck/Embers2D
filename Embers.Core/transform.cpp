
#include "stdafx.h"
#include "transform.h"
#include <Embers.Graphics/gl.h>

namespace CORE {

	CTransform::CTransform(SceneObject* owner) : Component(owner) {
		Position = glm::vec3(0, 0, 0);
		_scale = glm::vec3(1.0, 1.0, 1.0);
		Angle = 0;
	}

	void CTransform::Translate(glm::vec3 translation) {
		Position += translation;
	}

	void CTransform::Rotate(float angle) {
		Angle += angle;
	}

	void CTransform::SetAngle(float angle) {
		Angle = angle;
	}

	void CTransform::SetScale(float x, float y, float z) {
		_scale.x = x;
		_scale.y = y;
		_scale.z = z;
	}

	void CTransform::Tick(void) {

	}

	void CTransform::PreDraw(void) {
		EMB_GL->PushMatrix(glm::translate(glm::mat4(1.0), Position) * glm::rotate(glm::mat4(1.0) * glm::scale(glm::mat4(1.0), _scale), glm::radians(Angle), glm::vec3(0, 0, 1)));
	}

	void CTransform::Draw(void) {

	}

	void CTransform::PostDraw(void) {
		EMB_GL->PopMatrix();
	}

	void CTransform::DrawPass(GFX::ERenderPass pass) {

	}

}