
#include "stdafx.h"
#include "ef_gravity.h"
#include "rigid_body.h"

namespace CORE {

	EFGravity::EFGravity(glm::vec3 dir, float force) {
		_dir = dir;
		_force = force;
		_life = 1;
	}

	void EFGravity::Apply(CRigidBody* body) {
		body->Velocity += _dir * _force;
	}

}