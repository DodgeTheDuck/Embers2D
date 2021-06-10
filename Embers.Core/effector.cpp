
#include "stdafx.h"
#include "effector.h"

namespace CORE {

	bool Effector::IsDead(void) {
		return (_life <= 0);
	}

}