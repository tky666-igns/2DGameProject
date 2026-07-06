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
		SCENE_TITLE,	// タイトル画面
		SCENE_GAME,		// ゲーム本編
		SCENE_RESULT,	// リザルト画面

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




