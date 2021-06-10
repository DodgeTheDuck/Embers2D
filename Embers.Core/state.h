#pragma once

#include "Embers.Lib\dll.h"

namespace CORE {

	class EMB_API State {

	public:
		State();

		virtual void Init(void) = 0;
		virtual void Tick(void) = 0;
		virtual void Draw(void) = 0;

		~State();

	protected:


	private:


	};

}