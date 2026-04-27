#pragma once
#include "../lib/fade.h"
#include "stage.h"
#include "player.h"
#include "hitcheck.h"



class Scene
{
private:
	enum tagSceneGame {
		SCENEGAME_INIT,		// 初期化
		SCENEGAME_LOAD,		// データロード
		SCENEGAME_STARTWAIT,
		SCENEGAME_MAIN,		// メイン処理
		SCENEGAME_ENDWAIT,
		SCENEGAME_END,		// 終了処理

		SCENEGAME_NUM
	};
	tagSceneGame m_state;
	int m_res;
	FADE m_fade;
public:
	void Init();
	int Step();
	void Draw();
	int Loop();
	void Load();
	void Exit();
	//void HitCheck();
};




//void StepGame();
//void DrawGame();

