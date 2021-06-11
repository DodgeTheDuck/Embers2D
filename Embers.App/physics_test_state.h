#pragma once
#pragma once

#include <Embers.Core/state.h>

class Ship;

class PhysicsTestState : public CORE::State {

public:
	PhysicsTestState();

	virtual void Init(void);
	virtual void Tick(void);
	virtual void Draw(void);

	~PhysicsTestState();

private:

	Ship* _player;

};