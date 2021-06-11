#pragma once

#include <Embers.Lib/dll.h>
#include "component.h"

namespace CORE {

	class EMB_API CTransform : public Component {

	public:
		CTransform(SceneObject* owner);
		void Translate(glm::vec3 translation);
		void Rotate(float angle);

		void SetAngle(float angle);
		void SetScale(float x, float y, float z);

		void Tick(void);

		virtual void PreDraw(void);
		void Draw(void);
		virtual void PostDraw(void);
		virtual void DrawPass(GFX::ERenderPass pass);

		glm::vec3	Position;
		float		Angle;


	private:
		
		glm::vec3 _scale;

	};

}