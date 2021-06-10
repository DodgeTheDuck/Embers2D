
#include "stdafx.h"

#include "scene_object.h"
#include "component.h"

namespace CORE {

	SceneObject::SceneObject(void) {

	}

	void SceneObject::Tick(void) {
		for (int i = 0; i < _components.size(); i++) {
			_components[i]->Tick();
		}
		for (int i = 0; i < _children.size(); i++) {
			_children[i]->Tick();
		}
	}

	void SceneObject::PostTick(void) {
		//for (int i = 0; i < _components.size(); i++) {
		//	_components[i]->PostTick();
		//}
		for (int i = 0; i < _children.size(); i++) {
			_children[i]->PostTick();
		}
	}

	void SceneObject::Draw(void) {
		for (int i = 0; i < _components.size(); i++) {
			_components[i]->PreDraw();
		}
		for (int i = 0; i < _components.size(); i++) {
			_components[i]->Draw();
		}
		for (int i = 0; i < _children.size(); i++) {
			_children[i]->Draw();
		}
		for (int i = 0; i < _components.size(); i++) {
			_components[i]->PostDraw();
		}
	}

	void SceneObject::DrawPass(GFX::ERenderPass pass) {
		for (int i = 0; i < _components.size(); i++) {
			_components[i]->PreDraw();
		}
		for (int i = 0; i < _components.size(); i++) {
			_components[i]->DrawPass(pass);
		}
		for (int i = 0; i < _children.size(); i++) {
			_children[i]->DrawPass(pass);
		}
		for (int i = 0; i < _components.size(); i++) {
			_components[i]->PostDraw();
		}
	}

}