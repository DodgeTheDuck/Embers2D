
#include "stdafx.h"
#include "physics_world.h"


namespace CORE {

	PhysicsWorld::PhysicsWorld(void) {


	}

	void PhysicsWorld::Init(void) {
		b2Vec2 gravity(0.0f, -10.0f);
		_world = new b2World(gravity);
	}

	void PhysicsWorld::Tick(void) {

	}

	void PhysicsWorld::PostTick(void) {

	}

	void PhysicsWorld::Draw(void) {

	}

	void PhysicsWorld::DrawPass(GFX::ERenderPass pass) {

	}


}