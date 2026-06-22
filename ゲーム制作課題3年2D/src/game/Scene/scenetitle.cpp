#include "scenetitle.h"


// コンストラクタ
void SceneTitle::Init()
{
	m_state = INIT;
}

// 実行処理
int SceneTitle::Step() 
{

	switch (m_state)
	{
	case SceneTitle::INIT:
		// 初期化関連
		m_hdl = -1;
		m_state = SceneTitle::LOAD;
		break;
	case SceneTitle::LOAD:
		if (m_hdl == -1)
		{
			m_hdl = LoadGraph("data/game/TITLE.png");
		}
		// BGM鳴らす
		m_sound.RequestSound(m_sound.BGM_TITLE, DX_PLAYTYPE_LOOP);
		// フェードイン開始
		m_fade.RequestFadeIn();
		m_state = SceneTitle::STARTWAIT;
		break;
	case SceneTitle::STARTWAIT:
		if (m_fade.IsEndFadeIn() == true) 
		{
			m_state = SceneTitle::MAIN;
		}
		break;
	case SceneTitle::MAIN:
		// Zキーで次の場面へ
		if (m_in.IsInputTrg(KEY_SHOT) == true)
		{
			// フェードアウト開始
			m_fade.RequestFadeOut();
			m_state = SceneTitle::ENDWAIT;
		}
		break;
	case SceneTitle::ENDWAIT:
		if (m_fade.IsEndFadeOut() == true)
		{
			m_state = SceneTitle::END;
		}
		break;
	case SceneTitle::END:
		// 音楽止めて次へ
		m_sound.StopAllSound();
		if (m_hdl != -1) 
		{
			DeleteGraph(m_hdl);
			m_hdl = -1;
		}
		m_state = SceneTitle::INIT;
		return 1;
	}

	return 0;
}

// 描画処理
void SceneTitle::Draw() {
	switch (m_state)
	{
	case STARTWAIT:
	case MAIN:
	case ENDWAIT:
		// タイトル画面描画
		DrawFormatString(20, 20, WHITE, "次のシーンへ(Z)");
		DrawRotaGraph((int)(WINDOW_SIZE_X / 1.3),
			(int)WINDOW_SIZE_Y / 1.3, 1.0f, 0.0f, m_hdl, TRUE);
		break;
	}
}

