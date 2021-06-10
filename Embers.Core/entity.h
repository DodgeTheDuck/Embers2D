#pragma once

#include "scene_object.h"

namespace CORE {

	class EMB_API Entity : public SceneObject {

	public:
		Entity(void);

		virtual void Tick(void);
		virtual void Draw(void);

	private: 


	};

}