
#include "stdafx.h"
#include "window_manager.h"
#include "window.h"

namespace CORE {

	CORE::Window* WindowManager::New(uint32_t width, uint32_t height, const char * title) {
		CORE::Window* w = new CORE::Window(_hInstance, width, height, title);
		_windows.push_back(w);
		return w;
	}

	void WindowManager::DoEvents(void) {
		for (int i = 0; i < _windows.size(); i++) {
			HWND hWnd = _windows[i]->GetHandle();
			MSG message;
			bool ret = PeekMessage(&message, hWnd, 0, 0, PM_REMOVE);
			if (ret) {
				TranslateMessage(&message);
				DispatchMessage(&message);
			}			
		}
	}

	void WindowManager::SetApplicationHandle(HINSTANCE hInstance) {
		_hInstance = hInstance;
	}

	HINSTANCE WindowManager::GetApplicationHandle(void) {
		return _hInstance;
	}

}