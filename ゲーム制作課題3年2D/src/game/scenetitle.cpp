#include "scenetitle.h"


// 初期化処理
void SceneTitle::Init()
{
	m_state = INIT;
	m_hdl = -1;
}

// 実行処理
int SceneTitle::Loop() 
{

	int result = -1;

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
		// フェードイン開始
		m_fade.FADE::RequestFadeIn();
		m_sound.RequestSound(m_sound.BGM_TITLE, DX_PLAYTYPE_LOOP);
		m_state = SceneTitle::STARTWAIT;
		break;
	case SceneTitle::STARTWAIT:
		if (m_fade.IsEndFadeIn()) 
		{
			m_state = SceneTitle::MAIN;
		}
		break;
	case SceneTitle::MAIN:
		// Zキーで次の場面へ
		if (CheckHitKey(KEY_INPUT_Z) == true)
		{
			// フェードアウト開始
			m_fade.RequestFadeOut();
			m_state = SceneTitle::ENDWAIT;
		}
		break;
	case SceneTitle::ENDWAIT:
		if (m_fade.IsEndFadeOut())
		{
			m_state = SceneTitle::END;
		}
		break;
	case SceneTitle::END:
		if (m_hdl != -1) 
		{
			DeleteGraph(m_hdl);
			m_hdl = -1;
		}
		// 破棄
		m_sound.StopAllSound();
		m_state = INIT;
		result = 0;
		break;
	}

	return result;
}

// 描画処理
void SceneTitle::Draw() {
	switch (m_state)
	{
	case STARTWAIT:
	case MAIN:
	case ENDWAIT:
		// タイトル画面描画
		DrawFormatString(20, 20, WHITE, "タイトルシーン(Z)");
		DrawRotaGraph((int)(WINDOW_SIZE_X / 2),
			(int)WINDOW_SIZE_Y / 2, 1.0f, 0.0f, m_hdl, TRUE);

		break;
	}
}

