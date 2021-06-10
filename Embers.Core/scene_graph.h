#pragma once

#include <Embers.Lib/dll.h>
#include <Embers.Graphics/gl.h>

namespace CORE {

	class SceneObject;

	class EMB_API SceneGraph {

	public:
		SceneGraph(void);

		void Tick(void);
		void PostTick(void);
		void Draw(void);
		void DrawPass(GFX::ERenderPass pass);

		SceneObject* Root(void);

	private:
		SceneObject* _root;

	};

}