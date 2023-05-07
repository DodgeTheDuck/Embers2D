#pragma once

#include <Embers.Core/state.h>

class ThreeDTestState : public CORE::State {

public:
	ThreeDTestState();

	virtual void Init(void);
	virtual void Tick(void);
	virtual void Draw(void);

	~ThreeDTestState();

private:

};