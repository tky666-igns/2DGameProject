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
		m_stage.Init();
		m_player.Init();
		m_state = LOAD;
		break;
	case LOAD:
		m_stage.Load();
		m_player.Load();
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
		m_stage.Update();
		m_player.Update();
		//HitCheckPlayerToStage();
		break;
	case ENDWAIT:
		if (m_fade.IsEndFadeOut()) {
			m_state = END;
		}

		break;
	case END:
		m_stage.Exit();
		m_player.Exit();
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
		m_stage.Draw();
		m_player.Draw();
		break;
	}
}

