#pragma once

#include <Embers.Lib/dll.h>
#include "component.h"

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

		CRigidBody* AddEffector(Effector* effector);

		glm::vec3 Velocity;
		glm::vec3 Acceleration;

	private:

		std::vector<Effector*> _effectors;

	};

}