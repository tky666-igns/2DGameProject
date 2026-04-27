#pragma once
#include <DxLib.h>
#include "../lib/fade.h"
#include "../common.h"

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

public:
	void Init();
	int Loop();
	void Draw();
	void Load();
	int Step();
	void Exit();
};



