#include "stage.h"
#include "player.h"
#include "hitcheck.h"
#include "scenegame.h"

void Scene::Step()
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
		m_state = SCENEGAME_MAIN;
		break;
	case SCENEGAME_MAIN:
		UpdateStage();
		UpdatePlayer();
		//HitCheckPlayerToStage();
		break;
	case SCENEGAME_END:
		ExitStage();
		ExitPlayer();
		m_state = SCENEGAME_INIT;
		break;
	}
}


void Scene::Draw(void)
{
	switch (m_state)
	{
	case SCENEGAME_MAIN:
		DrawStage();
		DrawPlayer();
		break;
	}
}