#pragma once

#include <Embers.Lib/singleton.h>
#include <Embers.Graphics/gl.h>

namespace CORE {

	class SceneGraph;

	class EMB_API Scene : public LIB::Singleton<Scene> {

	public:
		Scene(void);
		void Init(void);

		void Tick(void);
		void PostTick(void);
		void Draw(void);
		void DrawPass(GFX::ERenderPass pass);

		SceneGraph* Graph(void);

	private:
		SceneGraph* _sceneGraph;

	};

}