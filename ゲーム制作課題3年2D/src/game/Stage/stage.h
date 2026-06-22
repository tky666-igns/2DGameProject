#pragma once

#include <DxLib.h>
#include "../../common.h"
#include "../Player/player.h"

class Object
{
public:
	VECTOR m_pos;	// 座標
	int m_state;	// ステージデータ　0=床・壁　1=宝箱　-1=何もなし

};
class Stage : public::Object
{
public:
	Player m_player;
	Object m_stageData[STAGE_Y][STAGE_X];
	int m_graphHdl[STAGEID_NUM];		// 画像ハンドル
	// ステージ初期化
	void Init();
	// ステージロード
	void Load();
	// ステージ更新
	void Update();
	// ステージ描画
	void Draw();
	// ステージ破棄
	void Exit();

};

