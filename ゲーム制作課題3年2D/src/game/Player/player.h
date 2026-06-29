#pragma once
#include "../../common.h"
#include "../../lib/input.h"
#include <DxLib.h>

#define GRAPH_NUM		(12)	// 全画像数



class Player
{
public:
	// プレイヤーの状態
	enum tagState {
		PLAYER_WAIT,
		PLAYER_MOVE,
		PLAYER_JUMP
	};
	VECTOR	m_pos;				// 座標
	float m_jumpPow;			// ジャンプ力
	bool m_isActive;			// 生存
	int m_hdl[GRAPH_NUM];		// 画像ハンドル
	tagState m_state;			// プレイヤーの状態
	int m_dir;					// プレイヤーの向き
	int m_animeCnt;				// アニメーションカウント用
public:
	//		プレイヤー初期化
	void Init();
	//		プレイヤーロード
	void Load();
	//		プレイヤー更新
	void Update();
	//		プレイヤー描画
	void Draw();
	//		プレイヤー破棄
	void Exit();
	//		オフセット位置取得
	VECTOR	GetOffset();
	//		地面接地時処理
	void SetLandPlayer();
	//		落下時処理
	void SetJumpPlayer();
private:
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

};

