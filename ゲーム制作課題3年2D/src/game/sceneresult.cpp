#include "sceneresult.h"

void SceneResult::Init()
{
	m_state = INIT;
}

int SceneResult::Step() 
{
	switch (m_state)
	{
	case SceneResult::INIT:
		m_hndl = -1;
		m_state = LOAD;
		break;
	case SceneResult::LOAD:
		if (m_hndl == -1)
		{
			m_hndl = LoadGraph("data/game/RESULT.png");
		}
		m_fade.RequestFadeIn();
		m_state = STARTWAIT;
		break;
	case SceneResult::STARTWAIT:
		if (m_fade.IsEndFadeIn() == true) 
		{
			m_sound.RequestSound(Sound::tagSound::BGM_TITLE, DX_PLAYTYPE_LOOP);
			m_state = MAIN;
		}
		break;
	case SceneResult::MAIN:
		if (IsKeyInputTrg(KEY_SHOT) == true)
		{
			m_fade.RequestFadeOut();
			m_state = ENDWAIT;
		}
		break;
	case SceneResult::ENDWAIT:
		if (m_fade.IsEndFadeOut() == true) 
		{
			m_state = END;
		}
		break;
	case SceneResult::END:
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

void SceneResult::Draw() {
	switch (m_state)
	{
	case STARTWAIT:
	case MAIN:
	case ENDWAIT:
		DrawFormatString(20, 20, WHITE, "リザルトシーン(Z)");
		DrawRotaGraph((float)(WINDOW_SIZE_X * 0.5f),
			(float)WINDOW_SIZE_Y * 0.5f, 1.0f, 0.0f, m_hndl, TRUE);
		break;
	}
}


