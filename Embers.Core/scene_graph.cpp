
#include "stdafx.h"
#include "scene_graph.h"
#include "scene_object.h"

namespace CORE {

	SceneGraph::SceneGraph(void) {
		_root = new SceneObject();
	}

	void SceneGraph::Tick(void) {
		_root->Tick();
	}

	void SceneGraph::PostTick(void) {
		_root->PostTick();
	}

	void SceneGraph::Draw(void) {
		_root->Draw();
	}

	void SceneGraph::DrawPass(GFX::ERenderPass pass) {
		_root->DrawPass(pass);
	}

	SceneObject* SceneGraph::Root(void) {
		return _root;
	}

}