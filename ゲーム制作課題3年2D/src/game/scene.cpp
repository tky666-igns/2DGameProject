#include "scene.h"


void SceneMana::Init() {
	m_state = SCENE_TITLE;
	m_title.Init();
	m_game.Init();
	m_resualt.Init();
	m_fade.Init();
}

int SceneMana::Loop()
{
	// ƒQ[ƒ€‚ªI—¹‚µ‚½‚©‚ğŠO•”‚É“`‚¦‚é‚½‚ß
	int result = -1;

	switch (m_state)
	{
	case SceneMana::SCENE_TITLE:
		if (m_title.Step() != -1)
		{
			m_state = SceneMana::SCENE_GAME;
		}
		break;
	case SceneMana::SCENE_GAME:
		if (m_game.Step() != -1)
		{
			m_state = SceneMana::SCENE_RESULT;
		}
		break;
	case SceneMana::SCENE_RESULT:
		if (m_resualt.Step() != -1)
		{
			m_state = SceneMana::SCENE_TITLE;
		}

	}

}


