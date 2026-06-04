#include "hitcheck.h"


// プレイヤーとステージオブジェクトの当たり判定
void Hit::HitCheckPlayerToStage()
{
	bool isHitGround = false;
	
	//ステージすべてのマップチップと判定
	for (int y = 0; y < STAGE_Y; y++)
	{
		for (int x = 0; x < STAGE_X; x++)
		{
			//調べている場所がブロックでなければ次へ進む
			if (m_stage.m_stageData[y][x].m_state != STAGEID_BLOCK)
			{
				continue;
			}
			//プレイヤーとマップを矩形同士の当たり判定で調べる
			bool isHit = CheckHitSquareToSquare(m_player.m_pos,
				PLAYER_SIZE_X, PLAYER_SIZE_Y,
				m_stage.m_stageData[y][x].m_pos,
				OBJECT_SIZE_X, OBJECT_SIZE_Y);
			//当たっていないブロックなら次へ
			if (isHit == false)
			{
				continue;
			}

			int posX = (int)m_player.m_pos.x;
			int posY = (int)m_player.m_pos.y;

			posX /= OBJECT_SIZE_X;
			posY /= OBJECT_SIZE_Y;
			//プレイヤーとブロックの位置関係を計算

			posX -= x;
			posY -= y;

			//めり込んだ距離を計算する
			//プレイヤーと物体の距離を計算する
			float lenX = m_player.m_pos.x - m_stage.m_stageData[y][x].m_pos.x;
			float lenY = m_player.m_pos.y - m_stage.m_stageData[y][x].m_pos.y;

			lenX = fabsf(lenX);
			lenY = fabsf(lenY);

			//距離はマイナスにはならない
			if (lenX < 0.0f) lenX *= -1.0f;
			if (lenY < 0.0f) lenY *= -1.0f;
			//本来離れているべき距離から現在離れている距離を引き算すると
			//めり込んだ距離が計算できる
			lenX = (PLAYER_SIZE_X / 2 + OBJECT_SIZE_X / 2) - lenX;
			lenY = (PLAYER_SIZE_Y / 2 + OBJECT_SIZE_Y / 2) - lenY;


			//横のほうに押し戻す想定
			if (lenX < lenY)
			{
				//押し戻す方向にブロックがなければ横に押し戻す
				if (m_stage.m_stageData[y][x + posX].m_state != STAGEID_BLOCK)
				{
					//posXをかけることにより左右の+-が正しく設定される
					lenX *= posX;
					//想定の方向にめり込んだ分だけ押し戻す
					m_player.m_pos.x += lenX;
				}
				//横がダメだったときは第二候補の上下で押し戻す
				else if (m_stage.m_stageData[y + posY][x].m_state != STAGEID_BLOCK)
				{
					//posYをかけることにより上下の+-が正しく設定される
					lenY *= posY;
					//想定の方向にめり込んだ分だけ押し戻す
					m_player.m_pos.y += lenY;
					//
					if (lenY < 0)
					{
						m_player.SetLandPlayer();
						isHitGround = true;
					}

				}
			}
			//縦のほうに押し戻す想定
			else
			{
				//押し戻す方向にブロックがなければ横に押し戻す
				if (m_stage.m_stageData[y + posY][x].m_state != STAGEID_BLOCK)
				{
					//posXをかけることにより左右の+-が正しく設定される
					lenY *= posY;
					//想定の方向にめり込んだ分だけ押し戻す
					m_player.m_pos.y += lenY;

					if (lenY < 0)
					{
						m_player.SetLandPlayer();
						isHitGround = true;
					}
				}
				//横がダメだったときは第二候補の上下で押し戻す
				else if (m_stage.m_stageData[y][x + posX].m_state != STAGEID_BLOCK)
				{
					//posYをかけることにより上下の+-が正しく設定される
					lenX *= posX;
					//想定の方向にめり込んだ分だけ押し戻す
					m_player.m_pos.x += lenX;
				}
			}

		}
	}

	if (!isHitGround) m_player.SetJumpPlayer();

}

// プレイヤーとゴールの当たり判定
void Hit::HitCheckPlayerToGoal()
{

}

// プレイヤーと罠の当たり判定
bool Hit::HitCheckPlayerToTrap()
{
	bool isHit = false;	//接触したかどうか

	if (m_player.m_isActive == false)
	{
		return false;
	}

	//敵の数分当たっているかどうか調べる
	for (int j = 0; j < TRAP_MAX; j++)
	{
		//プレイヤーと敵の当たり判定結果をisHit変数に入れる
		isHit = CheckHitCircleToCircle(m_pos, 30,
			m_enemy[j].m_pos, 40);


		if (isHit == true)
		{
			m_isActive = false;
			RequestExplosion(m_pos);
			RequestSound(SEID_EXPLOSION, DX_PLAYTYPE_BACK);
			return true;
		}

	}
	return isHit;

}