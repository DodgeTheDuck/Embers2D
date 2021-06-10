#pragma once

#include <Embers.Core/state.h>

class Player;
class World;

class GameState : public CORE::State {

public:
	GameState();

	virtual void Init(void);
	virtual void Tick(void);
	virtual void Draw(void);

	~GameState();

private:

	Player* _player;
	World* _world;

};