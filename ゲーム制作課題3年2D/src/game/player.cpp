#include "player.h"
#include "../common.h"
#include "../lib/input.h"

#define START_POS_X		(48)	// プレイヤーの開始地点(横)
#define START_POS_Y		(432)	// プレイヤーの開始地点(縦)
#define PLAYER_SPD		(2)		// プレイヤーの移動速度
#define PLAYER_JUMP_POW	(5.0f)	// プレイヤーの移動速度

// 方向
enum tagDir{
	UP,
	RIGHT,
	DOWN,
	LEFT
};

PLAYER_DATA g_player = { 0 };

static const int g_iAnimID[][4] = {
	{ 0, 1, 2, 1 }, { 3, 4, 5, 4 }, { 6, 7, 8, 7 }, { 9, 10, 11, 10 }
};


//-------------------------------
//		プレイヤー初期化
//-------------------------------
void InitPlayer()
{
	g_player.m_pos.x = START_POS_X;
	g_player.m_pos.y = START_POS_Y;
	g_player.m_jumpPow = 0.0f;
	g_player.m_animCnt = 0;
	g_player.m_state = PLAYER_WAIT;
	g_player.m_dir = RIGHT;

	for (int i = 0; i < GRAPH_NUM; i++)
	{
		g_player.m_hndl[i] = -1;
	}
}


//-------------------------------
//		プレイヤーロード
//-------------------------------
void LoadPlayer()
{
	if (g_player.m_hndl[0] == -1)
	{
		LoadDivGraph("graph/player00.png", GRAPH_NUM, 3, 4,
			PLAYER_SIZE_X, PLAYER_SIZE_Y, g_player.m_hndl);
	}
}


//-------------------------------
//		プレイヤー更新
//-------------------------------
void UpdatePlayer()
{
	// プレイヤーの行動
	switch (g_player.m_state) {
	case PLAYER_WAIT:
		// 右移動
		if (IsKeyInputRep(KEY_RIGHT))
		{
			g_player.m_state = PLAYER_MOVE;
			g_player.m_dir = RIGHT;
			g_player.m_pos.x += PLAYER_SPD;
		}
		// 左移動
		else if (IsKeyInputRep(KEY_LEFT))
		{
			g_player.m_state = PLAYER_MOVE;
			g_player.m_dir = LEFT;
			g_player.m_pos.x -= PLAYER_SPD;
		}
		// 左右どちらも移動無し
		else
		{
			g_player.m_state = PLAYER_WAIT;
		};
		// ジャンプ
		if (IsKeyInputTrg(KEY_UP))
		{
			g_player.m_state = PLAYER_JUMP;
			g_player.m_jumpPow = PLAYER_JUMP_POW;
		}
		break;
	case PLAYER_MOVE:
		// 右移動
		if (IsKeyInputRep(KEY_RIGHT))
		{
			g_player.m_state = PLAYER_MOVE;
			g_player.m_dir = RIGHT;
			g_player.m_pos.x += PLAYER_SPD;
		}
		// 左移動
		else if (IsKeyInputRep(KEY_LEFT))
		{
			g_player.m_state = PLAYER_MOVE;
			g_player.m_dir = LEFT;
			g_player.m_pos.x -= PLAYER_SPD;
		}
		// 左右どちらも移動無し
		else
		{
			g_player.m_state = PLAYER_WAIT;
		}
		// ジャンプ
		if (IsKeyInputTrg(KEY_UP))
		{
			g_player.m_state = PLAYER_JUMP;
			g_player.m_jumpPow = PLAYER_JUMP_POW;
		}
		break;
	case PLAYER_JUMP:
		// 左右移動ではあるが、状態はジャンプから変更させない
		if (IsKeyInputRep(KEY_RIGHT))
		{
			g_player.m_dir = RIGHT;
			g_player.m_pos.x += PLAYER_SPD;
		}
		else if (IsKeyInputRep(KEY_LEFT))
		{
			g_player.m_dir = LEFT;
			g_player.m_pos.x -= PLAYER_SPD;
		}
		break;
	}

	// 重力処理
	g_player.m_jumpPow -= GRAVITY;
	g_player.m_pos.y -= g_player.m_jumpPow;

	// 当たり判定がない間だけ使用するので、いずれは消す
	if (g_player.m_pos.y > WINDOW_SIZE_Y)
	{
		g_player.m_pos.y = WINDOW_SIZE_Y;
		SetLandPlayer();
	}

	// アニメーション更新
	// 今回はアニメーション4回分をループして再生
	// 1つのアニメーションにつき10カウント数えてから次へいく予定
	g_player.m_animCnt = (g_player.m_animCnt + 1) % 40;
}


//-------------------------------
//		プレイヤー描画
//-------------------------------
void DrawPlayer()
{
	int hndlNum = g_iAnimID[g_player.m_dir][g_player.m_animCnt / 10];
	VECTOR offset = GetOffset();
	int x = (int)(g_player.m_pos.x - offset.x);
	int y = (int)(g_player.m_pos.y - offset.y);

	DrawRotaGraph(x, y, 1.0f, 0.0f, g_player.m_hndl[hndlNum], TRUE);
}


//-------------------------------
//		プレイヤー破棄
//-------------------------------
void ExitPlayer()
{
	for (int i = 0; i < GRAPH_NUM; i++)
	{
		if (g_player.m_hndl[i] != -1)
		{
			DeleteGraph(g_player.m_hndl[i]);
			g_player.m_hndl[i] = -1;
		}
	}
}


//-------------------------------
//		プレイヤー破棄
//-------------------------------
VECTOR GetOffset()
{
	VECTOR offset;
	offset.x = g_player.m_pos.x - WINDOW_SIZE_X * 0.5f;
	offset.y = g_player.m_pos.y - WINDOW_SIZE_Y * 0.5f;
	offset.z = 0.0f;

	return offset;
}


//-------------------------------
//		地面接地時処理
//-------------------------------
void SetLandPlayer(void)
{
	g_player.m_jumpPow = 0.0f;
	g_player.m_state = PLAYER_WAIT;
}


//-------------------------------
//		落下時処理
//-------------------------------
void SetJumpPlayer(void)
{
	g_player.m_state = PLAYER_JUMP;
}


//-------------------------------
//		待ち状態時の処理
//-------------------------------
void WaitExec(void)
{
}


//-------------------------------
//		移動状態時の処理
//-------------------------------
void MoveExec(void)
{
}


//-------------------------------
//		ジャンプ状態時の処理
//-------------------------------
void JumpExec(void)
{
}

//-------------------------------
//		左右移動実行
//-------------------------------
void MoveCalc()
{
}


//-------------------------------
//		ジャンプ実行
//-------------------------------
void JumpCalc()
{
}

