#pragma once

#include <Embers.Core/entity.h>

namespace CORE {
	class CRigidBody;
}

class TestMesh : public CORE::Entity {

public:
	TestMesh(glm::vec3 pos);
	virtual void Tick(void);
	virtual void PostTick(void);
	virtual void DrawPass(GFX::ERenderPass pass);


private:

	CORE::CRigidBody* _body;

};