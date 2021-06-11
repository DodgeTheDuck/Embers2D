
#include "stdafx.h"

#include <Embers.Core/state.h>
#include <Embers.Core/engine.h>
#include <Embers.Core/scene_graph.h>
#include <Embers.Core/transform.h>
#include <Embers.Core/input.h>

#include "physics_test_state.h"
#include "ship.h"
#include "asteroid.h"
#include "camera.h"
#include <time.h>


PhysicsTestState::PhysicsTestState() : State() {
	_player = NULL;
}

void PhysicsTestState::Init(void) {

	//EMB_SCENE->Graph()->Root()->AddChild<Camera>(new Camera());

	srand(time(NULL));

	_player = EMB_SCENE->Graph()->Root()->AddChild<Ship>(new Ship());

	for (int i = 0; i < 16; i++) {
		Asteroid * asteroid = EMB_SCENE->Graph()->Root()->AddChild<Asteroid>(new Asteroid());
	}


	//EMB_SCENE->Graph()->Root()->AddChild<Blur>(new Blur());
}

void PhysicsTestState::Tick(void) {

}

void PhysicsTestState::Draw(void) {

}

PhysicsTestState::~PhysicsTestState() {

}
