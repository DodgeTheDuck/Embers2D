#pragma once

#include <Embers.Core/entity.h>

class World;

namespace CORE {
	class CRigidBody;
}

class Player : public CORE::Entity {

public:
	Player(World* world);
	virtual void Tick(void);
	virtual void PostTick(void);
	virtual void DrawPass(GFX::ERenderPass pass);


private:

	World* _world;

	float _zoom;
	CORE::CRigidBody* _body;

	int _jumpFrames;
	int _jumpFramesMax;
	bool _grounded;

};