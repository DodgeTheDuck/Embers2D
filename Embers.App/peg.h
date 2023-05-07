#pragma once

#include <Embers.Core/entity.h>

namespace CORE {
	class CRigidBody;
}

class Peg : public CORE::Entity {

public:
	Peg();
	virtual void Tick(void);
	virtual void PostTick(void);
	virtual void DrawPass(GFX::ERenderPass pass);


private:

	CORE::CRigidBody* _body;

};