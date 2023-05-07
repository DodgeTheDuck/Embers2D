
#include "stdafx.h"
#include "ef_impulse.h"
#include "rigid_body.h"

namespace CORE {

	EFImpulse::EFImpulse(glm::vec3 dir, float force) {
		_dir = dir;
		_force = force;
		_life = 1;
	}

	void EFImpulse::Apply(CRigidBody* body) {
		body->Acceleration += _dir * _force;
		_life -= 1;
	}

}