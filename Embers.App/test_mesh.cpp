
#include "stdafx.h"
#include "test_mesh.h"

#include <Embers.Core/material.h>
#include <Embers.Core/rigid_body.h>
#include <Embers.Core/engine.h>
#include <Embers.Core/asset_bank.h>
#include <Embers.Core/texture.h>
#include <Embers.Core/shader.h>
#include <Embers.Core/transform.h>
#include <Embers.Core/model.h>

#include <Embers.Graphics/gl.h>


TestMesh::TestMesh(glm::vec3 pos) {

	GetComponent<CORE::CTransform>()->Translate(pos);

	AddComponent<CORE::CModel>()
		->SetMaterial(EMB_ASSET_BANK->GetAsset<CORE::Material>("mat_polygon"))
		->FromFile("./models/statuette.obj")
		->SetOrigin(0, 0, 0);

	_body = AddComponent<CORE::CRigidBody>();

}

void TestMesh::Tick(void) {
	//GetComponent<CORE::CTransform>()->Rotate(glm::vec3(0, 1, 0), 0.01);
	Entity::Tick();
}

void TestMesh::PostTick(void) {
	Entity::PostTick();
}

void TestMesh::DrawPass(GFX::ERenderPass pass) {

}