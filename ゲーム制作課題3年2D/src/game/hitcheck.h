#pragma once
#include <math.h>
#include "player.h"
#include "stage.h"
#include "../common.h"
#include "Trap.h"
#include "../lib/collision.h"


class Hit
{
public:
	// プレイヤーとステージオブジェクトの当たり判定
	void HitCheckPlayerToStage();
	// プレイヤーとゴールの当たり判定
	void HitCheckPlayerToGoal();
	// プレイヤーと罠の当たり判定
	bool HitCheckPlayerToTrap();

	Player m_player;
	Stage m_stage;
	Trap m_trap;
};
