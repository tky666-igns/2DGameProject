#pragma once
#include "../Stage/stage.h"
#include <DxLib.h>
#include "../../lib/fade.h"
#include "../../common.h"
#include"../../lib/input.h"
#include "../Sound/Sound.h"
#include "../Player/player.h"
#include "../Hitcheck/hitcheck.h"


static const int END_WAIT = 60;

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
	Player m_player;
	Stage m_stage;
	Hit m_hit;
public:
	int Step();
	void Draw();
	void Init();

};