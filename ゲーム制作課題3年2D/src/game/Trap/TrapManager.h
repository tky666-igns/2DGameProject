#pragma once
#include "Trap.h"
#include "../Player/player.h"

class TrapManager
{
public:
	void Init();
	void Load();
	void Exit();
	void Step(VECTOR playerPos);
	void Draw();
	int Request();

	Trap& GetTrap(int id) { return m_trap[id]; }

private:
	Trap m_trap[TRAP_MAX];
	Player m_player;
};
