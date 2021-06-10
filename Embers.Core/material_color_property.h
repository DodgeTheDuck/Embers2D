#pragma once

#include "color.h"

namespace CORE {	

	class Texture;

	class EMB_API MaterialColorProperty {

	public:
		MaterialColorProperty(void);

		RGB_32 Color;
		Texture* Texture;

	private:


	};

}	