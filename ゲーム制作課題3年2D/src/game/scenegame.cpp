#include "scenegame.h"



void Scene::Init() {
	m_state = SCENEGAME_INIT;
	m_res = 0;
}



int Scene::Step()
{
	switch (m_state)
	{
	case SCENEGAME_INIT:
		InitStage();
		InitPlayer();
		m_state = SCENEGAME_LOAD;
		break;
	case SCENEGAME_LOAD:
		LoadStage();
		LoadPlayer();
		m_fade.RequestFadeIn();
		m_state = SCENEGAME_MAIN;
		break;
	case SCENEGAME_STARTWAIT:
		if (m_fade.IsEndFadeIn())
		{
			m_state = SCENEGAME_MAIN;
		}
		break;
	case SCENEGAME_MAIN:
		UpdateStage();
		UpdatePlayer();
		//HitCheckPlayerToStage();
		break;
	case SCENEGAME_ENDWAIT:
		if (m_fade.IsEndFadeOut()) {
			m_state = SCENEGAME_END;
		}

		break;
	case SCENEGAME_END:
		ExitStage();
		ExitPlayer();
		m_state = SCENEGAME_INIT;
		return m_res;
		break;
	}

	return 0;
}


void Scene::Draw(void)
{
	switch (m_state)
	{
	case SCENEGAME_STARTWAIT:
	case SCENEGAME_MAIN:
	case SCENEGAME_ENDWAIT:
		DrawFormatString(20, 20, WHITE, "ÉQÅ[ÉÄ");
		DrawStage();
		DrawPlayer();
		break;
	}
}