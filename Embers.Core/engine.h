#pragma once

#include "state_manager.h"
#include "window_manager.h"
#include "asset_bank.h"
#include "scene.h"
#include "input.h"
#include "debug.h"
#include "conductor.h"

#include <Embers.Lib/dll.h>

namespace CORE {

	class State;
	class CSprite;
	class Text;	

	class EMB_API Engine {

	public:
		Engine();
		~Engine(void);

		void Init(void);
		void Run(void);

		void Tick(void);
		void Draw(void);

	private:

		uint32_t	_targetTps;
		uint32_t	_targetFps;
		long double _threshTps;
		long double _threshFps;
		double		_tpsDelta;
		double		_fpsDelta;
		double		_secDelta;
		int			_tpsCounter;
		int			_fpsCounter;

		LONGLONG _delta;
		LARGE_INTEGER _freq, _now, _prev;

	};

}

#define EMB_STATE_MANAGER CORE::StateManager::GetInstance()
#define EMB_WINDOW_MANAGER CORE::WindowManager::GetInstance()
#define EMB_ASSET_BANK CORE::AssetBank::GetInstance()
#define EMB_SCENE CORE::Scene::GetInstance()
#define EMB_INPUT CORE::Input::GetInstance()
#define EMB_DEBUG CORE::Debug::GetInstance()
#define EMB_CONDUCTOR CORE::Conductor::GetInstance()

#define EMB_INIT(state)																									\
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR cmd, _In_ int cmdShow) {		\
	EMB_WINDOW_MANAGER->SetApplicationHandle(hInstance);																\
	CORE::Engine* eng = new CORE::Engine();																				\
	eng->Init();																										\
	EMB_STATE_MANAGER->Push(state);																						\
	eng->Run();																											\
	return 0;																											\
}
