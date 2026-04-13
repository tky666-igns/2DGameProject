#pragma once

#include <DxLib.h>
#include "../common.h"

// ステージオブジェクト構造体
typedef struct{
	VECTOR m_pos;	// 座標
	int m_state;	// ステージデータ　0=床・壁　1=宝箱　-1=何もなし
}OBJECT_DATA;

// ステージデータ構造体
typedef struct{
	OBJECT_DATA m_stageData[STAGE_Y][STAGE_X];
	int m_graphHndl[STAGEID_NUM];		// 画像ハンドル
}STAGE_DATA;


//		ステージ初期化
void InitStage();
//		ステージロード
void LoadStage();
//		ステージ更新
void UpdateStage();
//		ステージ描画
void DrawStage();
//		ステージ破棄
void ExitStage();
