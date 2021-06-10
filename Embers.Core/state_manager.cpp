
#include "stdafx.h"
#include "state_manager.h" 
#include "state.h"

namespace CORE {

	void StateManager::Push(State* state) {
		_states.push(state);
	}

	void StateManager::Pop(void) {
		_states.pop();
	}

	State* StateManager::Top(void) {
		if (_states.size() == 0) return NULL;
		return _states.top();
	}

}