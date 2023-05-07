
#include "stdafx.h"
#include "input.h"

namespace CORE {

	void Input::Init(void) {

		for (int i = 0; i < 256; i++) {
			_keys[(EKey)i] = EKeyState::UP;
		}

	}

	void Input::SetMousePosition(int x, int y) {		
		_mouseState.dx = x - 1024 / 2;
		_mouseState.dy = y - 768 / 2;
		_mouseState.x = x;
		_mouseState.y = y;
	}

	void Input::ResetMouseDelta(void) {
		_mouseState.dx = 0;
		_mouseState.dy = 0;
	}

	Mouse Input::GetMouseState(void) {
		return _mouseState;
	}

	void Input::SetKeyState(EKey key, EKeyState state) {
		_keys[key] = state;
	}

	EKeyState Input::GetKeyState(EKey key) {
		return _keys[key];
	}

}