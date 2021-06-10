
#include "stdafx.h"
#include "metrics.h"
#include "transform.h"
#include "gui_border.h"
#include "gui_panel.h"
#include "gui_text_block.h"

namespace CORE {

	Metrics::Metrics(void) {

		AddComponent<CTransform>()
			->Translate(glm::vec3(1024-(164+8), 8, 0));
		AddComponent<CGuiBorder>()
			->SetDimensions(164, 128);


		_panel = new SceneObject();
		SceneObject* textFps = new SceneObject();
		SceneObject* textTps = new SceneObject();

		_panel->AddComponent<CTransform>();
		_panel->AddComponent<CGuiPanel>()
			->SetDimensions(164, 128);

		_fps = textFps->AddComponent<CGuiTextBlock>()
			->SetText("FPS: 0");

		_tps = textTps->AddComponent<CGuiTextBlock>()			
			->SetText("TPS: 0");

		textFps->AddComponent<CTransform>()
			->Translate(glm::vec3(8, 8, 0));

		textTps->AddComponent<CTransform>()
			->Translate(glm::vec3(8, 32, 0));

		this->AddChild(_panel);

	}

	void Metrics::SetFps(uint32_t fps) {
		std::string text = "FPS: ";
		text.append(std::to_string(fps));
		_fps->SetText(text);
	}

	void Metrics::SetTps(uint32_t tps) {
		std::string text = "TPS: ";
		text.append(std::to_string(tps));
		_tps->SetText(text);
	}

	void Metrics::AddMetric(const std::string& name) {

		SceneObject* metricObj = new SceneObject();;
		CGuiTextBlock* metricTxt = metricObj->AddComponent<CGuiTextBlock>()
			->SetText(name + ": 0");

		metricObj->AddComponent<CTransform>()
			->Translate(glm::vec3(8, 8 + 24 * _metrics.size(), 0));

		_panel->AddChild(metricObj);

		SMetric m;
		m.name = name;
		m.textBlock = metricTxt;
		m.value = 0;
		_metrics[name] = m;

	}

	void Metrics::UpdateMetric(const std::string& name, int value) {
		std::string text = name + ": ";
		text.append(std::to_string(value));
		_metrics[name].textBlock->SetText(text);
	}

}