#pragma once

#include <DxLib.h>

#define GRAPH_NUM		(12)	// 全画像数

// プレイヤーの状態
enum tagState{
	PLAYER_WAIT,
	PLAYER_MOVE,
	PLAYER_JUMP
};

// プレイヤーデータ構造体
typedef struct{
	VECTOR	m_pos;				// 座標
	float m_jumpPow;			// ジャンプ力
	int m_hndl[GRAPH_NUM];		// 画像ハンドル
	tagState m_state;			// プレイヤーの状態
	int m_dir;					// プレイヤーの向き
	int m_animCnt;				// アニメーションカウント用
}PLAYER_DATA;


//		プレイヤー初期化
void InitPlayer();
//		プレイヤーロード
void LoadPlayer();
//		プレイヤー更新
void UpdatePlayer();
//		プレイヤー描画
void DrawPlayer();
//		プレイヤー破棄
void ExitPlayer();

//		オフセット位置取得
VECTOR	GetOffset();
//		地面接地時処理
void SetLandPlayer();
//		落下時処理
void SetJumpPlayer();



// ここから下は、player.cpp内部でしか使用しない関数
//		待ち状態時の処理
void WaitExec();
//		移動状態時の処理
void MoveExec();
//		ジャンプ状態時の処理
void JumpExec();

//		左右移動実行
void MoveCalc();
//		ジャンプ実行
void JumpCalc();
