#pragma once
#include <DxLib.h>
#include "../../lib/fade.h"
#include "../../common.h"
#include"../../lib/input.h"
#include "../Sound/Sound.h"

class SceneTitle
{
private:
	enum tagScene {
		INIT,		// データ初期化
		LOAD,		// データ読み込み
		STARTWAIT,	// 開始前の演出
		MAIN,		// ゲーム本編実行
		ENDWAIT,	// 終了前の演出
		END,		// 終了前のデータ破棄

		NUM
	};
	tagScene m_state;	// 現在の状態遷移
	Sound m_sound;
	int m_hdl;
public:
	// コンストラクタ・デストラクタ
	SceneTitle();
	~SceneTitle();

	// 実行処理
	int Loop();
	// 描画処理
	void Draw();

private:
	//初期化
	void Init();
	//画像読み込み
	void Load();
	//毎フレーム処理
	void Step();
	//終了
	void Exit();
};



