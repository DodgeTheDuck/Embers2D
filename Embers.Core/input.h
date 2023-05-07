#pragma once

#include <Embers.Lib/dll.h>
#include <Embers.Lib/singleton.h>

namespace CORE {

	enum EKeyState {
		UP,
		DOWN
	};

	enum EKey {
		A = 65,
		W = 87,
		D = 68,
		S = 83,
		NUM_PLUS = 107,
		NUM_MINUS = 109
	};

	struct Mouse {
		int x;
		int y;
		float dx;
		float dy;
	};

	class EMB_API Input : public LIB::Singleton<Input> {

	public:
		void Init(void);

		void SetMousePosition(int x, int y);
		void ResetMouseDelta(void);
		Mouse GetMouseState(void);

		void SetKeyState(EKey key, EKeyState state);
		EKeyState GetKeyState(EKey);

	private:

		std::map<EKey, EKeyState> _keys;

		Mouse _mouseState;
		

	};

}