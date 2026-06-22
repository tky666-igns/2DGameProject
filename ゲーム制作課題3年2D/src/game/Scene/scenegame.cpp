#include "scenegame.h"



// ‰Šú‰»ˆ—
void Scene::Init() {
	m_state = INIT;
	m_endWaitCount = END_WAIT;
}

// Àsˆ—
int Scene::Step()
{
	switch (m_state)
	{
	case INIT:
		m_stage.Init();
		m_player.Init();
		m_endWaitCount = 0;
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
			m_sound.RequestSound(Sound::BGMID_GAME, DX_PLAYTYPE_LOOP);
			m_state = MAIN;
		}
		break;
	case MAIN:
		m_stage.Update();
		m_player.Update();
		//“–‚½‚è”»’èˆ—
		m_hit.HitCheckPlayerToStage();

		if ( m_hit.HitCheckPlayerToTrap() == true)
		{
			m_endWaitCount = END_WAIT;
			m_fade.RequestFadeOut();
			m_state = ENDWAIT;
		}
		break;
	case ENDWAIT:
		if (m_fade.IsEndFadeOut()) {
			m_state = END;
		}
		m_endWaitCount--;
		break;
	case END:
		m_stage.Exit();
		m_player.Exit();
		m_state = INIT;
		return 1;
		break;
	}

	return 0;
}

// •`‰æˆ—
void Scene::Draw()
{
	switch (m_state)
	{
	case MAIN:
	case ENDWAIT:
		m_player.Draw();
		m_stage.Draw();
		break;
	}
}

