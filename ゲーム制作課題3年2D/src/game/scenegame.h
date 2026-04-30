#pragma once
#include "stage.h"
#include <DxLib.h>
#include "../lib/fade.h"
#include "../common.h"
#include"../lib/input.h"
#include "Sound.h"
#include "player.h"


static const int END_WAIT = 80;

class Scene
{
private:
	enum tagSceneGame {
		INIT,		// 初期化
		LOAD,		// データロード
		STARTWAIT,
		MAIN,		// メイン処理
		ENDWAIT,
		END,		// 終了処理

		NUM
	};
	tagSceneGame m_state;
	int m_res;
	int m_endWaitCount;
	Sound m_sound;
	FADE m_fade;
public:
	void Init();
	int Step();
	void Draw();
};