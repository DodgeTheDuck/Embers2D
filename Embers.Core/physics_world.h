#pragma once

#include <Embers.Lib/singleton.h>
#include <Embers.Graphics/gl.h>
#include <3rdParty/box2d/include/box2d/box2d.h>

namespace CORE {

	class EMB_API PhysicsWorld : public LIB::Singleton<PhysicsWorld> {

	public:
		PhysicsWorld(void);
		void Init(void);

		void Tick(void);
		void PostTick(void);
		void Draw(void);
		void DrawPass(GFX::ERenderPass pass);

	private:
		b2World* _world;


	};

}