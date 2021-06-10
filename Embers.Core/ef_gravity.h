#pragma once

#include <Embers.Lib/dll.h>
#include "effector.h"

namespace CORE {

	class CRigidBody;

	class EMB_API EFGravity : public Effector {

	public:
		EFGravity(glm::vec3 dir, float force);

		void Apply(CRigidBody* body);

	private:
		glm::vec3 _dir;
		float _force;

	};

}