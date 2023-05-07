#pragma once
#pragma once

#include <Embers.Core/state.h>

class PoggleGameState : public CORE::State {

public:
	PoggleGameState();

	virtual void Init(void);
	virtual void Tick(void);
	virtual void Draw(void);

	~PoggleGameState();

private:

};