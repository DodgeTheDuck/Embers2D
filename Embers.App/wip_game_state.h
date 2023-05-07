#pragma once

#include <Embers.Core/state.h>

class WIPGameState : public CORE::State {

public:
	WIPGameState();

	virtual void Init(void);
	virtual void Tick(void);
	virtual void Draw(void);

	~WIPGameState();

private:

};