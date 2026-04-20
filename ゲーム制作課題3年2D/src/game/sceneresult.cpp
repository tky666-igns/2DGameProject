#include "sceneresult.h"
#include "../lib/fade.h"
#include "../common.h"

void SceneResult::Init()
{
	m_state = INIT;
	m_hndl = -1;
}

int SceneResult::Step() {
	switch (m_state)
	{
	case INIT:
		m_hndl = -1;
		m_state = LOAD;
		break;
	case LOAD:
		if (m_hndl == -1) {
			m_hndl = LoadGraph("data/geme/RESULT.png");
		}
		RequestFadeIn();
		m_state = STARTWAIT;
		break;
	case STARTWAIT:
		if (IsEndFadeIn()) {
			m_state = MAIN;
		}
		break;
	case MAIN:
		if (CheckHitKey(KEY_INPUT_RETURN)) {
			m_state = ENDWAIT;
			RequestFadeOut();
		}
		break;
	case ENDWAIT:
		if (IsEndFadeOut()) {
			m_state = END;
		}
		break;
	case END:
		if (m_hndl != -1) {
			DeleteGraph(m_hndl);
			m_hndl = -1;
		}
		m_state = INIT;
		return 1;
		break;
	}

	return 0;
}

void SceneResult::Draw() {
	switch (m_state)
	{
	case STARTWAIT:
		break;
	case MAIN:
		DrawFormatString(20, 20, WHITE, "リザルトシーン");
		DrawRotaGraph((int)(WINDOW_SIZE_X * 0.5f), (int)WINDOW_SIZE_Y * 0.5f, 1.0f, 0.0f, m_hndl, true);
		break;
	case ENDWAIT:
		break;
	}
}
