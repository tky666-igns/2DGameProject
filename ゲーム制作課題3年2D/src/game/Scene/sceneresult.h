#pragma once
#include <DxLib.h>
#include "../../lib/fade.h"
#include "../../common.h"
#include"../../lib/input.h"
#include "../Sound/Sound.h"

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
	FADE m_fade;
	Sound m_sound;
	Input m_in;
	int m_hdl;

public:
	// ‰Šú‰»
	void Init();
	// Àsˆ—
	int Step();
	// •`‰æˆ—
	void Draw();
};



