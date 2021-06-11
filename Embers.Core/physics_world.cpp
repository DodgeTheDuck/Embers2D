
#include "stdafx.h"
#include "physics_world.h"


namespace CORE {

	PhysicsWorld::PhysicsWorld(void) {


	}

	void PhysicsWorld::Init(void) {
		b2Vec2 gravity(0.0f, 0.0f);
		_world = new b2World(gravity);
	}

	b2Body * PhysicsWorld::CreateBody(b2BodyDef * bodyDef) {
		return _world->CreateBody(bodyDef);
	}

	void PhysicsWorld::Tick(void) {
		_world->Step(1.0f / 128.0f, 6, 2);
	}

	void PhysicsWorld::PostTick(void) {

	}

	void PhysicsWorld::Draw(void) {

	}

	void PhysicsWorld::DrawPass(GFX::ERenderPass pass) {

	}


}