#pragma once
#include <DxLib.h>
#include "../lib/fade.h"
#include "../common.h"

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
	int m_hndl;
public:
	void Init();
	int Loop();
	void Draw();
	void Load();
	int Step();
	void Exit();
};



