#include "player.h"



 static const int	START_POS_X		= 48;	// プレイヤーの開始地点(横)
 static const int	START_POS_Y		= 432;	// プレイヤーの開始地点(縦)
 static const int	PLAYER_SPD		= 2;	// プレイヤーの移動速度
 static const float	PLAYER_JUMP_POW	= 5.0f;	// プレイヤーの移動速度


// 方向
enum tagDir{
	UP,
	RIGHT,
	DOWN,
	LEFT
};

static const int g_iAnimID[][4] = {
	{ 0, 1, 2, 1 }, { 3, 4, 5, 4 }, { 6, 7, 8, 7 }, { 9, 10, 11, 10 }
};


//-------------------------------
//		プレイヤー初期化
//-------------------------------
void Player::Init()
{
	m_pos.x = START_POS_X;
	m_pos.y = START_POS_Y;
	m_jumpPow = 0.0f;
	m_animCnt = 0;
	m_state = PLAYER_WAIT;
	m_dir = RIGHT;

	for (int i = 0; i < GRAPH_NUM; i++)
	{
		m_hndl[i] = -1;
	}
}


//-------------------------------
//		プレイヤーロード
//-------------------------------
void Player::Load()
{
	if (m_hndl[0] == -1)
	{
		LoadDivGraph("graph/player00.png", GRAPH_NUM, 3, 4,
			PLAYER_SIZE_X, PLAYER_SIZE_Y, m_hndl);
	}
}


//-------------------------------
//		プレイヤー更新
//-------------------------------
void Player::Update()
{
	// プレイヤーの行動
	switch (m_state) {
	case PLAYER_WAIT:
		// 右移動
		if (m_nowKey.IsInputRep(KEY_RIGHT))
		{
			m_state = PLAYER_MOVE;
			m_dir = RIGHT;
			m_pos.x += PLAYER_SPD;
		}
		// 左移動
		else if (m_nowKey.IsInputRep(KEY_LEFT))
		{
			m_state = PLAYER_MOVE;
			m_dir = LEFT;
			m_pos.x -= PLAYER_SPD;
		}
		// 左右どちらも移動無し
		else
		{
			m_state = PLAYER_WAIT;
		};
		// ジャンプ
		if (m_nowKey.IsInputTrg(KEY_UP))
		{
			m_state = PLAYER_JUMP;
			m_jumpPow = PLAYER_JUMP_POW;
		}
		break;
	case PLAYER_MOVE:
		// 右移動
		if (m_nowKey.IsInputRep(KEY_RIGHT))
		{
			m_state = PLAYER_MOVE;
			m_dir = RIGHT;
			m_pos.x += PLAYER_SPD;
		}
		// 左移動
		else if (m_nowKey.IsInputRep(KEY_LEFT))
		{
			m_state = PLAYER_MOVE;
			m_dir = LEFT;
			m_pos.x -= PLAYER_SPD;
		}
		// 左右どちらも移動無し
		else
		{
			m_state = PLAYER_WAIT;
		}
		// ジャンプ
		if (m_nowKey.IsInputTrg(KEY_UP))
		{
			m_state = PLAYER_JUMP;
			m_jumpPow = PLAYER_JUMP_POW;
		}
		break;
	case PLAYER_JUMP:
		// 左右移動ではあるが、状態はジャンプから変更させない
		if (m_nowKey.IsInputRep(KEY_RIGHT))
		{
			m_dir = RIGHT;
			m_pos.x += PLAYER_SPD;
		}
		else if (m_nowKey.IsInputRep(KEY_LEFT))
		{
			m_dir = LEFT;
			m_pos.x -= PLAYER_SPD;
		}
		break;
	}

	// 重力処理
	m_jumpPow -= GRAVITY;
	m_pos.y -= m_jumpPow;

	// 当たり判定がない間だけ使用するので、いずれは消す
	if (m_pos.y > WINDOW_SIZE_Y)
	{
		m_pos.y = WINDOW_SIZE_Y;
		SetLandPlayer();
	}

	// アニメーション更新
	// 今回はアニメーション4回分をループして再生
	// 1つのアニメーションにつき10カウント数えてから次へいく予定
	m_animCnt = (m_animCnt + 1) % 40;
}


//-------------------------------
//		プレイヤー描画
//-------------------------------
void Player::Draw()
{
	int hndlNum = g_iAnimID[m_dir][m_animCnt / 10];
	VECTOR offset = GetOffset();
	int x = (int)(m_pos.x - offset.x);
	int y = (int)(m_pos.y - offset.y);

	DrawRotaGraph(x, y, 1.0f, 0.0f, m_hndl[hndlNum], TRUE);
}


//-------------------------------
//		プレイヤー破棄
//-------------------------------
void Player::Exit()
{
	for (int i = 0; i < GRAPH_NUM; i++)
	{
		if (m_hndl[i] != -1)
		{
			DeleteGraph(m_hndl[i]);
			m_hndl[i] = -1;
		}
	}
}


//-------------------------------
//		プレイヤー破棄
//-------------------------------
VECTOR Player::GetOffset()
{
	VECTOR offset;
	offset.x = m_pos.x - WINDOW_SIZE_X * 0.5f;
	offset.y = m_pos.y - WINDOW_SIZE_Y * 0.5f;
	offset.z = 0.0f;

	return offset;
}


//-------------------------------
//		地面接地時処理
//-------------------------------
void Player::SetLandPlayer(void)
{
	m_jumpPow = 0.0f;
	m_state = PLAYER_WAIT;
}


//-------------------------------
//		落下時処理
//-------------------------------
void Player::SetJumpPlayer(void)
{
	m_state = PLAYER_JUMP;
}


//-------------------------------
//		待ち状態時の処理
//-------------------------------
void Player::WaitExec(void)
{
}


//-------------------------------
//		移動状態時の処理
//-------------------------------
void Player::MoveExec(void)
{
}


//-------------------------------
//		ジャンプ状態時の処理
//-------------------------------
void Player::JumpExec(void)
{
}

//-------------------------------
//		左右移動実行
//-------------------------------
void Player::MoveCalc()
{
}


//-------------------------------
//		ジャンプ実行
//-------------------------------
void Player::JumpCalc()
{
}

