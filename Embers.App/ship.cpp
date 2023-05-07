
#include "stdafx.h"
#include "ship.h"

#include <Embers.Core/material.h>
#include <Embers.Core/polygon.h>
#include <Embers.Core/rigid_body.h>
#include <Embers.Core/engine.h>
#include <Embers.Core/asset_bank.h>
#include <Embers.Core/texture.h>
#include <Embers.Core/shader.h>
#include <Embers.Core/transform.h>

#include <Embers.Graphics/gl.h>

Ship::Ship() {

	GetComponent<CORE::CTransform>()->Translate(glm::vec3(128, 128, 0));


	AddComponent<CORE::CPolygon>()
		->SetPoints({
			{-16, -12},
			{16, 0},
			{-16, +12},
		})
		->SetMaterial(EMB_ASSET_BANK->GetAsset<CORE::Material>("mat_polygon"))
		->SetOrigin(0, 0);

	_body = AddComponent<CORE::CRigidBody>();

}

void Ship::Tick(void) {

	CORE::CTransform* t = GetComponent<CORE::CTransform>();

	if (EMB_INPUT->GetKeyState(CORE::EKey::W) == CORE::EKeyState::DOWN) {

		float x = cos(glm::radians(t->Angle)) * 400;
		float y = sin(glm::radians(t->Angle)) * 400;

		//_body->ApplyForceAtCenter({x, y});
	}

	if (EMB_INPUT->GetKeyState(CORE::EKey::D) == CORE::EKeyState::DOWN) {
		//_body->ApplyTorque(1000);
	}

	if (EMB_INPUT->GetKeyState(CORE::EKey::A) == CORE::EKeyState::DOWN) {
		//_body->ApplyTorque(-1000);
	}

	Entity::Tick();
}

void Ship::PostTick(void) {

}

void Ship::DrawPass(GFX::ERenderPass pass) {

}