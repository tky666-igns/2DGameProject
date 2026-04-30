#include "scenetitle.h"


void SceneTitle::Init()
{
	m_state = INIT;
}

int SceneTitle::Step() 
{
	switch (m_state)
	{
	case SceneTitle::INIT:
		// 初期化関連
		m_hndl = -1;
		m_state = LOAD;
		break;
	case SceneTitle::LOAD:
		if (m_hndl == -1)
		{
			m_hndl = LoadGraph("data/game/TITLE.png");
		}
		m_fade.RequestFadeIn();
		m_state = STARTWAIT;
		break;
	case SceneTitle::STARTWAIT:
		if (m_fade.IsEndFadeIn() == true) 
		{
			m_sound.RequestSound(Sound::tagSound::BGM_TITLE, DX_PLAYTYPE_LOOP);
			m_state = MAIN;
		}
		break;
	case SceneTitle::MAIN:
		if (IsKeyInputTrg(KEY_SHOT) == true)
		{
			m_fade.RequestFadeOut();
			m_state = ENDWAIT;
		}
		break;
	case SceneTitle::ENDWAIT:
		if (m_fade.IsEndFadeOut() == true) 
		{
			m_state = END;
		}
		break;
	case SceneTitle::END:
		if (m_hndl != -1) 
		{
			DeleteGraph(m_hndl);
			m_hndl = -1;
		}
		// 破棄
		m_sound.StopAllSound();
		m_state = INIT;
		return 1;
	}

	return 0;
}

void SceneTitle::Draw() {
	switch (m_state)
	{
	case STARTWAIT:
	case MAIN:
	case ENDWAIT:
		// タイトル画面描画
		DrawFormatString(20, 20, WHITE, "タイトルシーン(Z)");
		DrawRotaGraph((float)(WINDOW_SIZE_X * 0.5f),
			(float)WINDOW_SIZE_Y * 0.5f, 1.0f, 0.0f, m_hndl, TRUE);
		break;
	}
}

