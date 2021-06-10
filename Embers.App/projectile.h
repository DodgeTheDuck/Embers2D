#pragma once

#include <Embers.Core/entity.h>

namespace CORE {
	class CRigidBody;
}

class Projectile : public CORE::Entity {

public:
	Projectile(void);
	virtual void Tick(void);


private:
	CORE::CRigidBody* _body;

};