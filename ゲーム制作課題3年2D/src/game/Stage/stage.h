#pragma once

#include <DxLib.h>
#include "../../common.h"
#include "../Player/player.h"



class Stage
{
public:
	// ステージオブジェクト構造体
	struct OBJECT_DATA {
		VECTOR m_pos;	// 座標
		int m_state;	// ステージデータ　0=床・壁　1=宝箱　-1=何もなし
	};

	// ステージデータ構造体
	struct STAGE_DATA{
		OBJECT_DATA m_stageData[STAGE_Y][STAGE_X];
		int m_graphHdl[STAGEID_NUM];		// 画像ハンドル
	};
public:
	Player m_player;

	STAGE_DATA m_stage;

	//		ステージ初期化
	void Init();
	//		ステージロード
	void Load();
	//		ステージ更新
	void Update();
	//		ステージ描画
	void Draw();
	//		ステージ破棄
	void Exit();

};

