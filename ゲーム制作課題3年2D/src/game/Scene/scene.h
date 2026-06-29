#pragma once
#include <DxLib.h>
#include "scenetitle.h"
#include "scenegame.h"
#include "sceneresult.h"
#include "../../lib/fade.h"
#include "../Sound/Sound.h"

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
	SceneResult m_res;
	Sound m_sound;

	tagScene m_sceneID;
public:
	void Init();
	int Loop();
	void Draw();
};




