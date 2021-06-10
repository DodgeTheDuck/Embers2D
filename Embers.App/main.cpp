
#include "stdafx.h"
#include "game_state.h"
#include <Embers.Core/engine.h>
																						
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR cmd, _In_ int cmdShow) {		

	GameState* state = new GameState();

	EMB_WINDOW_MANAGER->SetApplicationHandle(hInstance);																	
	CORE::Engine* eng = new CORE::Engine();																				
	eng->Init();											
	state->Init();
	EMB_STATE_MANAGER->Push(state);																							
	eng->Run();																											
	return 0;								

}