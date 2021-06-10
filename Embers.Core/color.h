#pragma once

#include <Embers.Lib/dll.h>
#include <stdint.h>

namespace CORE {

	struct EMB_API RGB_32 {
		RGB_32(uint32_t r, uint32_t g, uint32_t b) {
			this->r = r;
			this->g = g;
			this->b = b;
		}
		uint32_t r;
		uint32_t g;
		uint32_t b;
	};

}