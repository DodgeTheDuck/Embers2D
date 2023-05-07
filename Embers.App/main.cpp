#include "stdafx.h"

#include "game_state.h"
#include "physics_test_state.h"
#include "poggle_game_state.h"
#include "threed_state.h"

#include <Embers.Core/state.h>
#include <Embers.Core/engine.h>

enum class EAppToUse {
	GAME_TEST = 0x0,
	PHYSICS_TEST = 0x1,
	POGGLE = 0x2,
	WIP = 0x3,
	THREED = 0x4
};

const EAppToUse APP_TO_USE = EAppToUse::THREED;
																						
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR cmd, _In_ int cmdShow) {		

	CORE::State* state;

	switch (APP_TO_USE) {
		case EAppToUse::GAME_TEST: {
			state = new GameState();
			break;
		}
		case EAppToUse::PHYSICS_TEST: {
			state = new PhysicsTestState();
			break;
		}
		case EAppToUse::POGGLE: {
			state = new PoggleGameState();
			break;
		}
		case EAppToUse::THREED: {
			state = new ThreeDTestState();
			break;
		}
		default: {
			return 0;
		}
	}

	EMB_WINDOW_MANAGER->SetApplicationHandle(hInstance);																	
	CORE::Engine* eng = new CORE::Engine();																				
	eng->Init();											
	state->Init();
	EMB_STATE_MANAGER->Push(state);																							
	eng->Run();																											
	return 0;								

}