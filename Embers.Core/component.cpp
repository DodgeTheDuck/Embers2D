
#include "stdafx.h"
#include "component.h"
#include "scene_object.h"

namespace CORE {

	Component::Component(SceneObject* owner) {
		_owner = owner;
	}

}