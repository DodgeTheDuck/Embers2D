
#include "stdafx.h"

#include <Embers.Graphics/gl.h>


#include <Windows.h>

#include "engine.h"
#include "sprite.h"
#include "text.h"
#include "console.h"
#include "metrics.h"
#include "state.h"
#include "window.h"

#include "texture.h"

namespace CORE {

	Engine::Engine() {

		_targetTps = 0;
		_targetFps = 0;

		_threshTps = 0;
		_threshFps = 0;

		_tpsDelta = 0;
		_fpsDelta = 0;
		_secDelta = 0;

		_tpsCounter = 0;
		_fpsCounter = 0;

		QueryPerformanceFrequency(&_freq);
		QueryPerformanceCounter(&_prev);
		QueryPerformanceCounter(&_now);		

	}

	void Engine::Init(void) {

		CORE::Window* mainWindow = EMB_WINDOW_MANAGER->New(1024, 768, "Embers2D");
		mainWindow->Open();		

		EMB_GL->Init(EMB_WINDOW_MANAGER->GetApplicationHandle(), mainWindow->GetHandle());
		EMB_SCENE->Init();
		EMB_PHYSICS_WORLD->Init();
		EMB_ASSET_BANK->Load();
		EMB_DEBUG->Init();
		EMB_CONDUCTOR->Init();

		_targetTps = 128;
		_targetFps = 512;

		_threshTps = (1.0 / _targetTps) * 1000.0f;
		_threshFps = (1.0 / _targetFps) * 1000.0f;

		_tpsDelta = 0;
		_fpsDelta = 0;
		_secDelta = 0;

		_tpsCounter = 0;
		_fpsCounter = 0;

		QueryPerformanceFrequency(&_freq);
		QueryPerformanceCounter(&_prev);
		QueryPerformanceCounter(&_now);

		EMB_DEBUG->Console()->WriteLine("Hello world");
		EMB_DEBUG->Console()->WriteLine("Hello world 2");

		EMB_CONDUCTOR->Add(EEventType::TICK, std::bind(&Engine::Tick, this), 128);
		EMB_CONDUCTOR->Add(EEventType::DRAW, std::bind(&Engine::Draw, this), 512);

	}

	void Engine::Run(void) {

		while (true) {

			EMB_WINDOW_MANAGER->DoEvents();
			EMB_CONDUCTOR->Update();	
			
		}

	}

	void Engine::Tick(void) {

		EMB_PHYSICS_WORLD->Tick();
		EMB_SCENE->Tick();

		State* state = EMB_STATE_MANAGER->Top();
		if (state) {
			state->Tick();
		}

		EMB_SCENE->PostTick();

	}

	void Engine::Draw(void) {

		//EMB_GL->SetView(glm::translate(glm::mat4(1.0), glm::vec3(-512, -512, 0)));

		EMB_SCENE->DrawPass(GFX::ERenderPass::PRE_DRAW);

		EMB_GL->BeginRenderPass(GFX::ERenderPass::SCENE);

		EMB_SCENE->Draw();

		State* state = EMB_STATE_MANAGER->Top();
		if (state) {
			state->Draw();
		}

		EMB_GL->ClearView();

		EMB_GL->BeginRenderPass(GFX::ERenderPass::BLUR_X);
		EMB_GL->DrawRenderPass(GFX::ERenderPass::SCENE);

		EMB_SCENE->DrawPass(GFX::ERenderPass::BLUR_X);

		EMB_GL->BeginRenderPass(GFX::ERenderPass::BLUR_Y);
		EMB_GL->DrawRenderPass(GFX::ERenderPass::BLUR_X);

		EMB_SCENE->DrawPass(GFX::ERenderPass::BLUR_Y);

		EMB_GL->BeginRenderPass(GFX::ERenderPass::GUI);
		EMB_GL->DrawRenderPass(GFX::ERenderPass::BLUR_Y);

		EMB_SCENE->DrawPass(GFX::ERenderPass::GUI);

		EMB_GL->BeginRenderPass(GFX::ERenderPass::DISPLAY);
		EMB_GL->DrawRenderPass(GFX::ERenderPass::GUI);

		EMB_GL->Swap();

	}

	Engine::~Engine(void) {

	}

}