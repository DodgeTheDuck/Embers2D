#pragma once

#include <Embers.Core/entity.h>

namespace CORE {
	class CRigidBody;
}

class Camera : public CORE::Entity {

public:
	Camera(void);
	virtual void Tick(void);
	virtual void DrawPass(GFX::ERenderPass pass);


private:
	float _zoom;
	CORE::CRigidBody* _body;

};