
#include "stdafx.h"
#include "scene.h"
#include "scene_graph.h"

namespace CORE {

	Scene::Scene(void) {


		_sceneGraph = NULL;
	}

	void Scene::Init(void) {
		_sceneGraph = new SceneGraph();
	}

	void Scene::Tick(void) {
		_sceneGraph->Tick();
	}

	void Scene::PostTick(void) {
		_sceneGraph->PostTick();
	}

	void Scene::Draw(void) {
		_sceneGraph->Draw();
	}

	void Scene::DrawPass(GFX::ERenderPass pass) {
		_sceneGraph->DrawPass(pass);
	}

	SceneGraph* Scene::Graph(void) {
		return _sceneGraph;
	}

}