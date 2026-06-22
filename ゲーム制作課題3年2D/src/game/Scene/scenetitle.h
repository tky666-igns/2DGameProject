#pragma once
#include <DxLib.h>
#include "../lib/fade.h"
#include "../common.h"
#include"../lib/input.h"
#include "Sound.h"

class SceneTitle
{
private:
	enum tagSceneTITLE {
		INIT,
		LOAD,
		STARTWAIT,
		MAIN,
		ENDWAIT,
		END,

		NUM
	};
	tagSceneTITLE m_state;
	FADE m_fade;
	Sound m_sound;
	int m_hdl;
public:
	// コンストラクタ
	SceneTitle();
	// デストラクタ
	~SceneTitle();
	// 実行処理
	int Loop();
	// 描画処理
	void Draw();
};



