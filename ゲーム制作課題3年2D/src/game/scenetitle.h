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
	Input m_nowKey, m_prevKey, m_input;
	int m_hdl;
public:
	void Init();
	void Draw();
	int Loop();
};



