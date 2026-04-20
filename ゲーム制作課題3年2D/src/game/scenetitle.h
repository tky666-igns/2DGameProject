#pragma once
#include <DxLib.h>

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
	int m_hndl;
public:
	void Init();
	int Step();
	void Draw();

};



