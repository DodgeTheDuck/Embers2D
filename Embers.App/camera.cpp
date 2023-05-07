
#include "stdafx.h"
#include "camera.h"

#include <Embers.Core/material.h>
#include <Embers.Core/sprite.h>
#include <Embers.Core/rigid_body.h>
#include <Embers.Core/engine.h>
#include <Embers.Core/asset_bank.h>
#include <Embers.Core/texture.h>
#include <Embers.Core/shader.h>
#include <Embers.Core/transform.h>
#include <glm/gtx/quaternion.hpp>

#include <Embers.Core/ef_impulse.h>

#include <Embers.Graphics/gl.h>

Camera::Camera(void) {

	CORE::CTransform* t = GetComponent<CORE::CTransform>();
	t->Position = glm::vec3(0, 0, 10);	

	_body = AddComponent<CORE::CRigidBody>();
	
	_zoom = 1;

}

void Camera::Tick(void) {

	int x = 0;
	int y = 0;

	CORE::Mouse mouse = EMB_INPUT->GetMouseState();

	CORE::CTransform* t = GetComponent<CORE::CTransform>();

	t->Rotate({ 0, 1, 0 }, mouse.dx / 10.0f);
	//t->Rotate({ 1, 0, 0 }, mouse.dy / 10.0f);

	if (EMB_INPUT->GetKeyState(CORE::EKey::W) == CORE::EKeyState::DOWN) {
		y = 1;
	}

	if (EMB_INPUT->GetKeyState(CORE::EKey::A) == CORE::EKeyState::DOWN) {
		x = -1;
	}

	if (EMB_INPUT->GetKeyState(CORE::EKey::S) == CORE::EKeyState::DOWN) {
		y = -1;
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
		//_body->ApplyForceAtCenter({ cos(angle) * 800, sin(angle) * 800 });
		_body->AddEffector(new CORE::EFImpulse({ x, y, 0 }, 0.05));
	}

	Entity::Tick();
}

void Camera::DrawPass(GFX::ERenderPass pass) {
	if (pass == GFX::ERenderPass::PRE_DRAW) {
		CORE::CTransform* t = GetComponent<CORE::CTransform>();
		glm::mat4 view = glm::scale(glm::mat4(1.0), glm::vec3(_zoom, _zoom, 1)) * glm::toMat4(t->Rotation) * glm::translate(glm::mat4(1.0), (-t->Position));
		EMB_GL->SetView(view);
		EMB_GL->SetPerspective();
	}
}