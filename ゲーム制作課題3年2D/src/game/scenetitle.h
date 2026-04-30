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
	int m_hndl;
public:
	void Init();
	void Draw();
	int Step();
};



