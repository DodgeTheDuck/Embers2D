#pragma once

#include <Embers.Lib/dll.h>
#include <Embers.Lib/singleton.h>

namespace CORE {

	class Console;
	class Metrics;

	class EMB_API Debug : public LIB::Singleton<Debug> {

	public:
		void Init(void);

		CORE::Console* Console(void);
		CORE::Metrics* Metrics(void);

	private:

		CORE::Console* _console;
		CORE::Metrics* _metrics;

	};

}
