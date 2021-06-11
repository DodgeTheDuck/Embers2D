
#include "stdafx.h"
#include "tile.h"
#include "player.h"
#include "world.h"

#include <Embers.Core/material.h>
#include <Embers.Core/sprite.h>
#include <Embers.Core/rigid_body.h>
#include <Embers.Core/engine.h>
#include <Embers.Core/asset_bank.h>
#include <Embers.Core/texture.h>
#include <Embers.Core/shader.h>
#include <Embers.Core/transform.h>

#include <Embers.Core/ef_gravity.h>
#include <Embers.Core/ef_impulse.h>

#include <Embers.Graphics/gl.h>

Player::Player(World* world) {

	_world = world;
	_zoom = 1.0f;
	_grounded = true;
	_jumpFrames = 0;
	_jumpFramesMax = 10;

	GetComponent<CORE::CTransform>()->Translate(glm::vec3(256, 0, 0));

	_body = AddComponent<CORE::CRigidBody>();

	//_body->AddEffector(new CORE::EFGravity(glm::vec3(0.0f, 1.0f, 0.0f), 0.2f));

	AddComponent<CORE::CSprite>()
		->SetMaterial(EMB_ASSET_BANK->GetAsset<CORE::Material>("mat_person"))
		->SetCellSize(64, 96)
		->SetOrigin(32, 48);

}

void Player::Tick(void) {

	CORE::CTransform* t = GetComponent<CORE::CTransform>();

	int x = 0;
	int y = 0;

	if (_grounded) {
		_jumpFrames = 0;
	}

	if (EMB_INPUT->GetKeyState(CORE::EKey::W) == CORE::EKeyState::DOWN) {
		if (_jumpFrames < _jumpFramesMax) {
			y = -1;
			_jumpFrames++;
		}
	}

	if (EMB_INPUT->GetKeyState(CORE::EKey::A) == CORE::EKeyState::DOWN) {
		x = -1;
	}

	if (EMB_INPUT->GetKeyState(CORE::EKey::D) == CORE::EKeyState::DOWN) {
		x = 1;
	}

	if (EMB_INPUT->GetKeyState(CORE::EKey::NUM_PLUS) == CORE::EKeyState::DOWN) {
		_zoom += 0.01;
	}

	if (EMB_INPUT->GetKeyState(CORE::EKey::NUM_MINUS) == CORE::EKeyState::DOWN) {
		_zoom -= 0.01;
	}

	if (x != 0 || y != 0) {
		float angle = atan2(y, x);
		_body->AddEffector(new CORE::EFImpulse(glm::vec3(cos(angle) * 1.0f, sin(angle) * 7.5f, 0.0f), 0.2));
	}

	Entity::Tick();
}

void Player::PostTick(void) {

	//CORE::CTransform* t = GetComponent<CORE::CTransform>();

	//int bodyLeft = floor(t->Position.x) - 20;
	//int bodyRight = floor(t->Position.x) + 20;

	//int bodyBottom = floor(t->Position.y + 28);


	//int feetY = floor(t->Position.y + 48);
	//int feetLeft = t->Position.x - 20;
	//int feetRight = t->Position.x + 20;	

	//Tile& tileFeet = _world->TileAt(feetLeft, feetY);

	//if (tileFeet.Id > 0) {
	//	t->Position.y -= feetY % World::TILE_SIZE;		
	//	_grounded = true;
	//}
	//else {
	//	_grounded = false;
	//}

	//Tile& tileBodyLeft = _world->TileAt(bodyLeft, bodyBottom);

	//if (tileBodyLeft.Id > 0) {

	//	if (_world->TileAt(bodyLeft, bodyBottom - World::TILE_SIZE).Id == ETileType::AIR && _grounded) {
	//		t->Position.y -= World::TILE_SIZE;
	//	}
	//	else {
	//		t->Position.x += bodyLeft % 8;
	//	}

	//}

	//Tile& tileBodyRight = _world->TileAt(bodyRight, bodyBottom);

	//if (tileBodyRight.Id > 0) {
	//	

	//	if (_world->TileAt(bodyRight, bodyBottom - World::TILE_SIZE).Id == ETileType::AIR && _grounded) {
	//		t->Position.y -= World::TILE_SIZE;
	//	}
	//	else {
	//		t->Position.x -= bodyRight % 8;
	//	}


	//}

}

void Player::DrawPass(GFX::ERenderPass pass) {


	if (pass == GFX::ERenderPass::PRE_DRAW) {

		CORE::CTransform* t = GetComponent<CORE::CTransform>();

		glm::mat4 view = glm::scale(glm::mat4(1.0), glm::vec3(_zoom, _zoom, 1)) * glm::translate(glm::mat4(1.0), (-t->Position));
		EMB_GL->SetView(view);
	}
}