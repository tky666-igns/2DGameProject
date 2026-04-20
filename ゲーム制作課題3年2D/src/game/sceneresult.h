#pragma once
#include <DxLib.h>

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
public:
	void Init();
	int Step();
	void Draw();

};



