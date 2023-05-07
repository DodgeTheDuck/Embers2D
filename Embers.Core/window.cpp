
#include "stdafx.h"
#include "window.h"

#include "engine.h"
#include "input.h"

namespace CORE {

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
		_Create(_hInstance, 1024, 768, "Embers 2D");
	}

	HWND Window::GetHandle(void) {
		return _hWnd;
	}

	HDC Window::GetDeviceContext(void) {
		return _hDc;
	}

	LRESULT Window::_WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

		RECT r;

		GetWindowRect(hWnd, &r);

		int winW = r.right - r.left;
		int winH = r.bottom - r.top;

		switch (msg) {
		case WM_MOUSEMOVE: 
			EMB_INPUT->SetMousePosition(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			SetCursorPos(r.left + winW / 2, r.top + winH / 2);
			break;
		case WM_KEYDOWN:
			EMB_INPUT->SetKeyState((EKey)wParam, EKeyState::DOWN);
			break;
		case WM_KEYUP:
			EMB_INPUT->SetKeyState((EKey)wParam, EKeyState::UP);
			break;
		case WM_DESTROY:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);

		}


		return 0;

	}

	void Window::_Create(HINSTANCE hInstance, uint32_t width, uint32_t height, const char* title) {

		RECT rect = RECT();
		rect.top = 0;
		rect.left = 0;
		rect.right = width;
		rect.bottom = height;

		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CS_OWNDC, false);

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
		_hWnd = CreateWindow("EMBERS2D", title, WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CS_OWNDC, 256, 256, rect.right-rect.left, rect.bottom-rect.top, NULL, NULL, _hInstance, NULL);
		_hDc = GetDC(_hWnd);

	}

	Window::~Window(void) {

	}

}