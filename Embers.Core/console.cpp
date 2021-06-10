
#include "stdafx.h"
#include "console.h"
#include "transform.h"
#include "gui_border.h"
#include "gui_panel.h"
#include "gui_text_block.h"

namespace CORE {

	Console::Console(void) {

		AddComponent<CTransform>()
			->Translate(glm::vec3(128, 128, 0));
		AddComponent<CGuiBorder>()
			->SetDimensions(512, 128);

		SceneObject* panel = new SceneObject();
		SceneObject* text = new SceneObject();

		panel->AddComponent<CTransform>();
		panel->AddComponent<CGuiPanel>()
			->SetDimensions(512, 128);

		_output = text->AddComponent<CGuiTextBlock>()
			->SetText("");

		this->AddChild(panel);
		panel->AddChild(text);

	}

	void Console::WriteLine(std::string text) {
		std::string line = text;
		line.append("\n");
		_output->Append(line);
	}

}