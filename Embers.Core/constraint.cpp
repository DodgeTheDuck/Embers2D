
#include "stdafx.h"
#include "constraint.h"

namespace CORE {

	bool Constraint::IsDead(void) {
		return (_life <= 0);
	}

}