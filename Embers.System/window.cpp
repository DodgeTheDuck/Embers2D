
#include "stdafx.h"
#include "window.h"

namespace SYS {

	Window::Window(HINSTANCE hInstance, uint32_t width, uint32_t height, const char* title) {
		_Create(hInstance, width, height, title);
	}

	void Window::Open(void) {
		ShowWindow(_hWnd, SW_SHOW);
		SetForegroundWindow(_hWnd);
		SetFocus(_hWnd);
	}

	void Window::Close(void) {
		DestroyWindow(_hWnd);
		_hWnd = NULL;
	}

	void Window::Rebuild(void) {
		Close();
		_Create(_hInstance, 640, 480, "Embers 2D");
	}

	HINSTANCE Window::GetApplicationHandle(void) {
		return _hInstance;
	}

	HWND Window::GetHandle(void) {
		return _hWnd;
	}

	HDC Window::GetDeviceContext(void) {
		return _hDc;
	}

	LRESULT Window::_WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

		switch (msg) {

		case WM_DESTROY:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);

		}

		return 0;

	}

	void Window::_Create(HINSTANCE hInstance, uint32_t width, uint32_t height, const char* title) {

		WNDCLASSEX wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = (WNDPROC)([](HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) -> LRESULT { _WndProc(hWnd, msg, wParam, lParam); return true; });
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance;
		wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = "EMBERS2D";
		wcex.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);

		RegisterClassEx(&wcex);

		_hInstance = hInstance;
		_hWnd = CreateWindow("EMBERS2D", title, WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CS_OWNDC, 256, 256, width, height, NULL, NULL, _hInstance, NULL);
		_hDc = GetDC(_hWnd);

	}

	Window::~Window(void) {

	}

}