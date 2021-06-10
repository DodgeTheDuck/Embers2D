#pragma once

#include <Embers.Lib/dll.h>

namespace CORE {

	class EMB_API Window {

	public:
		Window(HINSTANCE hInstance, uint32_t width, uint32_t height, const char * title);

		void Open();
		void Close();
		void Rebuild();

		HWND GetHandle(void);
		HDC GetDeviceContext(void);

		~Window(void);

	private:
		static LRESULT _WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		void _Create(HINSTANCE hInstance, uint32_t width, uint32_t height, const char* title);

		HINSTANCE _hInstance;
		HWND _hWnd;
		HDC _hDc;

	};

}