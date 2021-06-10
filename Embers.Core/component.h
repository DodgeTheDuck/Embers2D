#pragma once

#include <Embers.Graphics/gl.h>

namespace CORE {

	class SceneObject;

	class Component {

	public:

		Component(SceneObject* owner);

		virtual void Tick(void) = 0;

		virtual void PreDraw(void) = 0;
		virtual void Draw(void) = 0;
		virtual void PostDraw(void) = 0;
		virtual void DrawPass(GFX::ERenderPass pass) = 0;

	protected:
		SceneObject* _owner;

	};

}