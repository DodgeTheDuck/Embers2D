
#include "stdafx.h"

#include <Embers.Core/state.h>
#include <Embers.Core/engine.h>
#include <Embers.Core/scene_graph.h>
#include <Embers.Core/transform.h>
#include <Embers.Core/input.h>

#include "poggle_game_state.h"
#include "peg.h"

#include <time.h>


PoggleGameState::PoggleGameState() : State() {
	
}

void PoggleGameState::Init(void) {	

	for (int i = 0; i < 16; i++) {
		Peg* peg = EMB_SCENE->Graph()->Root()->AddChild<Peg>(new Peg());
	}

}

void PoggleGameState::Tick(void) {

}

void PoggleGameState::Draw(void) {

}

PoggleGameState::~PoggleGameState() {

}
