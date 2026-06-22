#pragma once
#include <DxLib.h>
#include "../common.h"

class FADE
{
public:
	enum tagFadeScene
	{
		FADE_NON,		// フェードなし
		FADE_IN,		// フェードイン中(徐々に画面が出現)
		FADE_OUT,		// フェードアウト中(徐々に画面が消える)
		FADE_OUT_WAIT,	// フェードアウト後の真っ暗状態
	};

	tagFadeScene m_state;
	int m_count;

	//フェードの初期化
	void Init();
	//フェードの処理更新
	void Update();
	//フェードの描画管理
	void Draw();
	//フェードインリクエスト
	void RequestFadeIn();
	//フェードアウトリクエスト
	void RequestFadeOut();
	//フェードインが終了したか
	bool IsEndFadeIn();
	//フェードアウトが終了したか
	bool IsEndFadeOut();
};

