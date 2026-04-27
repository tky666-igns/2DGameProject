#pragma once

static const int FADE_SPD(10);	// フェードイン・アウトの速度


class FADE
{
public:
	enum tagFadeScene
	{
		FADE_NON,
		FADE_IN,
		FADE_OUT,
		FADE_OUT_WAIT,
	};

	tagFadeScene m_state;
	int m_count;

	//フェードの初期化
	void Init();
	//フェードの処理更新
	int Step();
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

