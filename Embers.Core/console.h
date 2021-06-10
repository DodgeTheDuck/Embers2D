#pragma once

#include "scene_object.h"

namespace CORE {

	class CGuiTextBlock;

	class EMB_API Console : public SceneObject {

	public:
		Console(void);
		void WriteLine(std::string text);

	private:
		CGuiTextBlock* _output;

	};

}