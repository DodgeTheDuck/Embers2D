#pragma once

#include <Embers.Lib/dll.h>
#include <Embers.Lib/singleton.h>

namespace CORE {

	class State;

	class EMB_API StateManager : public LIB::Singleton<StateManager> {

	public:
		void Push(State* state);
		void Pop(void);
		State* Top(void);

	private:
		std::stack<State*> _states;


	};

}