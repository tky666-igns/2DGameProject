#include "scenegame.h"



void Scene::Init() {
	m_state = INIT;
	m_endWaitCount = END_WAIT;
}

int Scene::Step()
{
	switch (m_state)
	{
	case INIT:
		InitStage();
		InitPlayer();
		m_state = LOAD;
		break;
	case LOAD:
		LoadStage();
		LoadPlayer();
		m_fade.RequestFadeIn();
		m_state = MAIN;
		break;
	case STARTWAIT:
		if (m_fade.IsEndFadeIn())
		{
			m_state = MAIN;
		}
		break;
	case MAIN:
		UpdateStage();
		UpdatePlayer();
		//HitCheckPlayerToStage();
		break;
	case ENDWAIT:
		if (m_fade.IsEndFadeOut()) {
			m_state = END;
		}

		break;
	case END:
		ExitStage();
		ExitPlayer();
		m_state = INIT;
		return m_res;
		break;
	}

	return 0;
}


void Scene::Draw(void)
{
	switch (m_state)
	{
	case STARTWAIT:
	case MAIN:
	case ENDWAIT:
		DrawFormatString(20, 20, WHITE, "ÉQÅ[ÉÄ");
		DrawStage();
		DrawPlayer();
		break;
	}
}

