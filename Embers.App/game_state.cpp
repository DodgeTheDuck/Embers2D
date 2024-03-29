
#include "stdafx.h"

#include <Embers.Core/state.h>
#include <Embers.Core/engine.h>
#include <Embers.Core/scene_graph.h>
#include <Embers.Core/transform.h>
#include <Embers.Core/input.h>

#include "game_state.h"
#include "player.h"
#include "world.h"


GameState::GameState() : State() {	
	_player = NULL;
}

void GameState::Init(void) {

	EMB_SCENE->Graph()->Root()->AddChild<Player>(new Player());
	_world = EMB_SCENE->Graph()->Root()->AddChild<World>(new World(4, 4));

}

void GameState::Tick(void) {

}

void GameState::Draw(void) {
	
}

GameState::~GameState() {

}
