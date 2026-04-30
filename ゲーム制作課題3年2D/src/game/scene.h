#pragma once
#include <DxLib.h>
#include "scenetitle.h"
#include "scenegame.h"
#include "sceneresult.h"
#include "../lib/fade.h"

class SceneMana
{
private:
	enum tagScene {
		SCENE_TITLE,
		SCENE_GAME,
		SCENE_RESULT,

		SCENE_NUM
	};

	SceneTitle m_title;
	Scene m_game;
	SceneResult m_resualt;
	FADE m_fade;

	tagScene m_state;
public:
	void Init();
	int Step();
	void Draw();

};




