#include "scenetitle.h"

void SceneTitle::Init()
{
	m_state = INIT;
	m_hndl = -1;
}

void SceneTitle::Load()
{
	if (m_hndl == -1)
	{
		m_hndl = LoadGraph("../Data/Image/Title/Title.JPG");
	}
}

int SceneTitle::Loop() 
{
	int m_ret = 0;

	switch (m_state)
	{
	case SceneTitle::INIT:
		Init();
		m_hndl = -1;
		m_state = LOAD;
		break;
	case SceneTitle::LOAD:
		Load();
		m_fade.RequestFadeIn();
		m_state = STARTWAIT;
		break;
	case SceneTitle::STARTWAIT:
		if (m_fade.IsEndFadeIn()) {
			m_state = MAIN;
		}
		break;
	case SceneTitle::MAIN:
		if (CheckHitKey(KEY_INPUT_RETURN)) {
			m_state = ENDWAIT;
			m_fade.RequestFadeOut();
		}
		break;
	case SceneTitle::ENDWAIT:
		if (m_fade.IsEndFadeOut()) {
			m_state = END;
		}
		break;
	case SceneTitle::END:
		if (m_hndl != -1) {
			DeleteGraph(m_hndl);
			m_hndl = -1;
		}
		m_state = INIT;
		m_ret = 1;
		break;
	}

	return m_ret;
}

int SceneTitle::Step()
{
	if (CheckHitKey(KEY_INPUT_Z))
		return 1;

	return 0;
}


void SceneTitle::Draw() {
	switch (m_state)
	{
	case STARTWAIT:
		break;
	case MAIN:
		DrawFormatString(20, 20, WHITE, "タイトルシーン(Z)");
		DrawRotaGraph((int)(WINDOW_SIZE_X * 0.5f), (int)WINDOW_SIZE_Y * 0.5f, 1.0f, 0.0f, m_hndl, true);
		break;
	case ENDWAIT:
		break;
	}
}

void SceneTitle::Exit()
{
	if (m_state != -1)
	{
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
}