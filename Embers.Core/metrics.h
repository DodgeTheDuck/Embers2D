#pragma once

#include <Embers.Lib/dll.h>
#include "scene_object.h"

namespace CORE {

	class CGuiTextBlock;

	struct SMetric {		
		std::string name;
		int value;
		CGuiTextBlock* textBlock;
	};

	class EMB_API Metrics : public SceneObject {

	public:
		Metrics(void);

		void SetFps(uint32_t fps);
		void SetTps(uint32_t tps);

		void AddMetric(const std::string& name);
		void UpdateMetric(const std::string& name, int value);

	private:
		CGuiTextBlock* _fps;
		CGuiTextBlock* _tps;

		SceneObject * _panel;

		std::map<std::string, SMetric> _metrics;


	};

}