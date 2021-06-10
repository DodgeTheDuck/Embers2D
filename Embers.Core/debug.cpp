
#include "stdafx.h"
#include "debug.h"
#include "console.h"
#include "metrics.h"
#include "engine.h"
#include "scene_graph.h"

namespace CORE {

	void Debug::Init(void) {
		_console = new CORE::Console();
		_metrics = new CORE::Metrics();
		//EMB_SCENE->Graph()->Root()->AddChild(_console);
		EMB_SCENE->Graph()->Root()->AddChild(_metrics);
	}

	CORE::Console * Debug::Console(void) {
		return _console;
	}

	CORE::Metrics * Debug::Metrics(void) {
		return _metrics;
	}

}