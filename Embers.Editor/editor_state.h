#pragma once

#include <Embers.Core/state.h>

class EditorState : public CORE::State {

public:
	EditorState();

	virtual void Init(void);
	virtual void Tick(void);
	virtual void Draw(void);

	~EditorState();

private:

};