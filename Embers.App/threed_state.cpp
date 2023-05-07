
#include "stdafx.h"

#include <Embers.Core/state.h>
#include <Embers.Core/engine.h>
#include <Embers.Core/scene_graph.h>
#include <Embers.Core/transform.h>
#include <Embers.Core/input.h>
#include <Embers.App/test_mesh.h>

#include "threed_state.h"
#include "camera.h"



ThreeDTestState::ThreeDTestState() : State() {

}

void ThreeDTestState::Init(void) {

	EMB_SCENE->Graph()->Root()->AddChild<Camera>(new Camera());
	EMB_SCENE->Graph()->Root()->AddChild<TestMesh>(new TestMesh({0, 0, 0}));
	
}

void ThreeDTestState::Tick(void) {

}

void ThreeDTestState::Draw(void) {

}

ThreeDTestState::~ThreeDTestState() {

}
