#include "sceneresult.h"

void SceneResult::Init()
{
	m_state = INIT;
	m_hndl = -1;
}

void SceneResult::Load()
{
	if (m_hndl == -1)
	{
		m_hndl = LoadGraph("data/geme/RESULT.png");
	}
}

int SceneResult::Loop() 
{
	int m_ret = 0;

	switch (m_state)
	{
	case SceneResult::INIT:
		Init();
		m_hndl = -1;
		m_state = LOAD;
		break;
	case SceneResult::LOAD:
		Load();
		m_fade.RequestFadeIn();
		m_state = STARTWAIT;
		// BGM鳴らす
		//RequestSound(BGM_ID_TITLE,DX_PLAYTYPE_BACK);
		break;
	case SceneResult::STARTWAIT:
		if (m_fade.IsEndFadeIn()) {
			m_state = MAIN;
		}
		break;
	case SceneResult::MAIN:
		if (Step() == 1)
		{
			m_state = ENDWAIT;
			m_fade.RequestFadeOut();
		}
		break;
	case SceneResult::ENDWAIT:
		if (m_fade.IsEndFadeOut()) {
			m_state = END;
		}
		break;
	case SceneResult::END:
		if (m_hndl != -1) {
			DeleteGraph(m_hndl);
			m_hndl = -1;
		}
		// 破棄
		//StopAllSound();
		Exit();
		m_state = INIT;
		m_ret = 1;
		break;
	}

	return m_ret;
}

int SceneResult::Step()
{
	if (CheckHitKey(KEY_INPUT_Z))
		return 1;
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
			(float)WINDOW_SIZE_Y * 0.5f, 1.0f, 0.0f, m_hndl, true);
		break;
	}
}

void SceneResult::Exit()
{
	if (m_state != -1)
	{
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
}