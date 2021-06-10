
#include "stdafx.h"
#include "rigid_body.h"
#include "effector.h"
#include "transform.h"
#include "scene_object.h"

namespace CORE {

	CRigidBody::CRigidBody(SceneObject* owner) : Component(owner) {
		Acceleration = glm::vec3(0.0);
		Velocity = glm::vec3(0.0);
	}

	void CRigidBody::Tick(void) {

		std::vector<Effector*>::iterator it = _effectors.begin();

		while (it != _effectors.end()) {

			if ((*it)->IsDead()) {
				it = _effectors.erase(it);
			} else {
				(*it)->Apply(this);
				++it;
			}
		}

		Velocity += Acceleration;
		Acceleration = glm::vec3(0.0);

		Velocity *= 0.97;

		CTransform* transform = _owner->GetComponent<CTransform>();

		transform->Position += Velocity;

	}

	void CRigidBody::PreDraw(void) {

	}

	void CRigidBody::Draw(void) {

	}

	void CRigidBody::PostDraw(void) {
		
	}

	void CRigidBody::DrawPass(GFX::ERenderPass pass) {

	}

	CRigidBody* CRigidBody::AddEffector(Effector* effector) {
		_effectors.push_back(effector);
		return this;
	}


}