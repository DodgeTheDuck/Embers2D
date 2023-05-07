#include "stdafx.h"

#include "player.h"

#include <Embers.Core/engine.h>
#include <Embers.Core/scene_graph.h>

Player::Player(void) {
	
	EMB_SCENE->Graph()->Root()->AddChild<Camera>(new Camera());

}

void Player::Tick(void) {
	
}

void Player::DrawPass(GFX::ERenderPass pass) {

}