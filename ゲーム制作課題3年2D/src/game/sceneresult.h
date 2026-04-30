#pragma once
#include <DxLib.h>
#include "../lib/fade.h"
#include "../common.h"
#include"../lib/input.h"
#include "Sound.h"

class SceneResult
{
private:
	enum tagSceneRESULT {
		INIT,
		LOAD,
		STARTWAIT,
		MAIN,
		ENDWAIT,
		END,

		NUM
	};
	tagSceneRESULT m_state;
	int m_hndl;
	FADE m_fade;
	Sound m_sound;

public:
	void Init();
	void Draw();
	int Step();
};



