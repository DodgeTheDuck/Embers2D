#pragma once

#include <Embers.Lib/dll.h>
#include "component.h"
#include <3rdParty/box2d/include/box2d/box2d.h>

namespace CORE {

	class Effector;	

	class EMB_API CRigidBody : public Component {

	public:
		CRigidBody(SceneObject* owner);

		void Tick(void);

		virtual void PreDraw(void);
		void Draw(void);
		virtual void PostDraw(void);
		virtual void DrawPass(GFX::ERenderPass pass);

		virtual void ApplyForce(glm::vec2 force, glm::vec2 point);
		virtual void ApplyForceAtCenter(glm::vec2 force);
		virtual void ApplyTorque(float torque);

		CRigidBody* AddEffector(Effector* effector);

	private:

		b2Body* _body;

		std::vector<Effector*> _effectors;

	};

}