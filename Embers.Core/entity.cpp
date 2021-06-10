
#include "stdafx.h"
#include "entity.h"
#include "transform.h"

namespace CORE {

	Entity::Entity(void) : SceneObject() {
		AddComponent<CTransform>();
	}	

	void Entity::Tick(void) {
		SceneObject::Tick();
	}

	void Entity::Draw(void) {
		SceneObject::Draw();
	}

}
