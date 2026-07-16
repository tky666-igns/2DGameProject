#pragma once
#include <DxLib.h>
#include "../Stage/stage.h"
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
	enum tagScene	{
		INIT,		// データ初期化
		LOAD,		// データ読み込み
		STARTWAIT,	// 開始前の演出
		MAIN,		// ゲーム本編実行
		ENDWAIT,	// 終了前の演出
		END,		// 終了前のデータ破棄

		NUM
	};
	tagScene m_state;
	int m_endWaitCount;
	Sound m_sound;
	Stage m_stage;
	Player m_player;
	//Hit m_hit;
public:
	// コンストラクタ・デストラクタ
	Scene();
	~Scene();

	// 実行処理
	int Loop();
	// 描画処理
	void Draw();

private:
	// 初期化
	void Init();
	// データロード
	void Load();
	// メイン処理
	void Step();
	// 終了前処理
	void Exit();

};