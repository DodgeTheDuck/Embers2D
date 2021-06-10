
#include "stdafx.h"
#include "projectile.h"

#include <Embers.Core/material.h>
#include <Embers.Core/sprite.h>
#include <Embers.Core/rigid_body.h>
#include <Embers.Core/engine.h>
#include <Embers.Core/asset_bank.h>
#include <Embers.Core/texture.h>
#include <Embers.Core/shader.h>
#include <Embers.Core/transform.h>

#include <Embers.Core/ef_impulse.h>

#include <Embers.Graphics/gl.h>

Projectile::Projectile(void) {

	_body = AddComponent<CORE::CRigidBody>();

	AddComponent<CORE::CSprite>()
		->SetMaterial(EMB_ASSET_BANK->GetAsset<CORE::Material>("mat_ship"))
		->SetCellSize(32, 32)
		->SetOrigin(16, 16);

}

void Projectile::Tick(void) {

	CORE::CTransform* t = GetComponent<CORE::CTransform>();

	float x = t->Position.x;
	float y = t->Position.y;

	float mx = EMB_INPUT->GetMouseState().x;
	float my = EMB_INPUT->GetMouseState().y;

	float dx = mx - x;
	float dy = my - y;

	float angle = atan2(dy, dx);

	t->SetAngle(glm::degrees(angle));

	if (EMB_INPUT->GetKeyState(CORE::EKey::W) == CORE::EKeyState::DOWN) {
		_body->AddEffector(new CORE::EFImpulse(glm::vec3(cos(angle) * 2.0f, sin(angle) * 2.0f, 0.0f), 0.01));
	}

	Entity::Tick();
}