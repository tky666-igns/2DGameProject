#include "scene.h"


void SceneMana::Init() {
	m_state = SCENE_TITLE;
	m_title.Init();
	m_game.Init();
	m_resualt.Init();
	InitFade();
}



