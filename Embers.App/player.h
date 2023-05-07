#pragma once

#include <Embers.Core/entity.h>
#include "camera.h"

namespace CORE {
	class CRigidBody;
}

class Player : public CORE::Entity {

public:
	Player(void);
	virtual void Tick(void);
	virtual void DrawPass(GFX::ERenderPass pass);

private:
	Camera _camera;

};