#include "scenetitle.h"


// コンストラクタ
SceneTitle::SceneTitle()
{
	m_state = INIT;
}

SceneTitle::~SceneTitle()
{
	Exit();
}

// 実行処理
int SceneTitle::Loop() 
{
	// 終了を外部に伝える
	int result = -1;

	switch (m_state)
	{
	case SceneTitle::INIT:
		// 初期化関連
		Init();
		m_state = SceneTitle::LOAD;
		break;
	case SceneTitle::LOAD:
		Load();
		// BGM鳴らす
		m_sound.RequestSound(m_sound.BGM_TITLE, DX_PLAYTYPE_LOOP);
		// フェードイン開始
		RequestFadeIn();
		m_state = SceneTitle::STARTWAIT;
		break;
	case SceneTitle::STARTWAIT:
		Step();
		if (IsEndFadeIn()) 
		{
			m_state = SceneTitle::MAIN;
		}
		break;
	case SceneTitle::MAIN:
		Step();
		// Zキーで次の場面へ
		if (IsInputTrg(KEY_SHOT))
		{
			// フェードアウト開始
			RequestFadeOut();

			m_state = SceneTitle::ENDWAIT;
		}
		break;
	case SceneTitle::ENDWAIT:

		if (IsEndFadeOut())
		{
			m_state = SceneTitle::END;
		}
		break;
	case SceneTitle::END:
		Exit();
		// 音楽止めて次へ
		m_sound.StopAllSound();
		m_state = SceneTitle::INIT;
		result = 0;	// ゲームの終了を知らせる
		break;
	}

	return result;
}

// 描画処理
void SceneTitle::Draw() {
	switch (m_state)
	{
	case SceneTitle::STARTWAIT:
	case SceneTitle::MAIN:
	case SceneTitle::ENDWAIT:
		// タイトル画面描画
		DrawFormatString(20, 20, WHITE, "次のシーンへ(Z)");
		DrawRotaGraph((int)(WINDOW_SIZE_X / 1.3),
			(int)(WINDOW_SIZE_Y / 1.3), 1.0f, 0.0f, m_hdl, TRUE);
		break;
	}
}

void SceneTitle::Init()
{
	m_hdl = -1;
}

void SceneTitle::Load()
{
	if (m_hdl == -1)
	{
		m_hdl = LoadGraph("data/game/TITLE.png");
	}
}

void SceneTitle::Step()
{

}

void SceneTitle::Exit()
{
	if (m_hdl != -1)
	{
		DeleteGraph(m_hdl);
		m_hdl = -1;
	}
}

