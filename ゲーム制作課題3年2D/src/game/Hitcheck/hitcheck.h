#pragma once
#include <math.h>
#include "../Player/player.h"
#include "../Stage/stage.h"
#include "../../common.h"
#include "../Trap/Trap.h"
#include "../Trap/TrapManager.h"
#include "../../lib/collision.h"


class Hit
{
public:
	// プレイヤーとステージオブジェクトの当たり判定
	bool HitCheckPlayerToStage();
	// プレイヤーとゴールの当たり判定
	bool HitCheckPlayerToGoal();
	// プレイヤーと罠の当たり判定
	bool HitCheckPlayerToTrap();

	Player m_player;
	Stage m_stage;
	Trap m_trap;
};
