#include "sceneresult.h"

void SceneResult::Init()
{
	m_state = INIT;
}

int SceneResult::Step() 
{
	int result = 0;

	switch (m_state)
	{
	case SceneResult::INIT:
		m_hdl = -1;
		m_state = SceneResult::LOAD;
		break;
	case SceneResult::LOAD:
		if (m_hdl == -1)
		{
			m_hdl = LoadGraph("data/game/RESULT.png");
		}
		m_sound.RequestSound(Sound::BGM_TITLE, DX_PLAYTYPE_LOOP);
		m_fade.RequestFadeIn();
		m_state = SceneResult::STARTWAIT;
		break;
	case SceneResult::STARTWAIT:
		if (m_fade.IsEndFadeIn())
		{
			m_state = SceneResult::MAIN;
		}
		break;
	case SceneResult::MAIN:
		if (CheckHitKey(KEY_INPUT_Z))
		{
			m_fade.RequestFadeOut();
			m_state = SceneResult::ENDWAIT;
		}
		break;
	case SceneResult::ENDWAIT:
		if (m_fade.IsEndFadeOut())
		{
			m_state = SceneResult::END;
		}
		break;
	case SceneResult::END:
		if (m_hdl != -1) 
		{
			DeleteGraph(m_hdl);
			m_hdl = -1;
		}
		// 破棄
		m_sound.StopAllSound();
		m_state = SceneResult::INIT;
		result = 0;
	}

	return result;
}

void SceneResult::Draw() {
	switch (m_state)
	{
	case STARTWAIT:
	case MAIN:
	case ENDWAIT:
		DrawFormatString(20, 20, WHITE, "リザルトシーン(Z)");
		DrawRotaGraph((int)(WINDOW_SIZE_X / 2),
			(int)WINDOW_SIZE_Y / 2, 1.0f, 0.0f, m_hdl, TRUE);
		break;
	}
}


