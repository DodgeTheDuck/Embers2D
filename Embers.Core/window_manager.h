#pragma once

#include <Embers.Lib/dll.h>
#include <Embers.Lib/singleton.h>

namespace CORE {

	class Window;

	class EMB_API WindowManager : public LIB::Singleton<WindowManager> {

	public:
		CORE::Window* New(uint32_t width, uint32_t height, const char * title);

		void DoEvents(void);

		void SetApplicationHandle(HINSTANCE hInstance);
		HINSTANCE GetApplicationHandle(void);

	private:
		HINSTANCE _hInstance;
		std::vector<CORE::Window*> _windows;

	};

}