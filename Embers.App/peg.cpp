
#include "stdafx.h"
#include "peg.h"

#include <Embers.Core/material.h>
#include <Embers.Core/polygon.h>
#include <Embers.Core/rigid_body.h>
#include <Embers.Core/engine.h>
#include <Embers.Core/asset_bank.h>
#include <Embers.Core/texture.h>
#include <Embers.Core/shader.h>
#include <Embers.Core/transform.h>

#include <Embers.Graphics/gl.h>

Peg::Peg() {


	std::vector<glm::vec2> points;

	int nPoints = 16;
	int radius = 16;

	for (int i = 0; i < nPoints; i++) {

		float r = glm::radians(360.0f / nPoints) * i;		

		float x = cos(r) * radius;
		float y = sin(r) * radius;

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

}

void Peg::Tick(void) {
	Entity::Tick();
}

void Peg::PostTick(void) {

}

void Peg::DrawPass(GFX::ERenderPass pass) {

}