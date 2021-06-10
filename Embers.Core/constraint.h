#pragma once

#include <Embers.Lib/dll.h>

namespace CORE {

	class CRigidBody;

	class EMB_API Constraint {

	public:
		virtual void Apply(CRigidBody* body) = 0;

		bool IsDead(void);

	protected:
		bool _life;

	};

}