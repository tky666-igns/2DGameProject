#pragma once
#include <math.h>
#include "player.h"
#include "stage.h"
#include "../common.h"
#include "../lib/collision.h"


class Hit
{
public:
	// プレイヤーとステージオブジェクトの当たり判定
	void HitCheckPlayerToStage();
	// プレイヤーとゴールの当たり判定
	void HitCheckPlayerToGoal();
	// プレイヤーと罠の当たり判定
	void HitCheckPlayerToTrap();


};
