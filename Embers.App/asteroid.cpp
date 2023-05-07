
#include "stdafx.h"
#include "asteroid.h"

#include <Embers.Core/material.h>
#include <Embers.Core/polygon.h>
#include <Embers.Core/rigid_body.h>
#include <Embers.Core/engine.h>
#include <Embers.Core/asset_bank.h>
#include <Embers.Core/texture.h>
#include <Embers.Core/shader.h>
#include <Embers.Core/transform.h>

#include <Embers.Graphics/gl.h>

Asteroid::Asteroid() {


	std::vector<glm::vec2> points;

	int nPoints = 8;
	int radius = 32;
	int start = radius + (radius - radius / 4);

	for (int i = 0; i < nPoints; i++) {
		
		float r = glm::radians(360.0f / nPoints) * i;

		float d = (rand() % radius) + radius/2;

		float x = cos(r) * d;
		float y = sin(r) * d;

		points.push_back({ x, y });

	}

	CORE::CTransform* t = GetComponent<CORE::CTransform>();
	t->Position.x = rand() % 1024;
	t->Position.y = rand() % 1024;


	AddComponent<CORE::CPolygon>()
		->SetPoints(points)
			->SetMaterial(EMB_ASSET_BANK->GetAsset<CORE::Material>("mat_polygon"))
		->SetOrigin(0, 0);

	_body = AddComponent<CORE::CRigidBody>();

	//_body->ApplyTorque(100000);

}

void Asteroid::Tick(void) {
	
	Entity::Tick();
}

void Asteroid::PostTick(void) {

}

void Asteroid::DrawPass(GFX::ERenderPass pass) {

}