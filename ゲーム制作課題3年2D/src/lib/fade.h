#pragma once

static const int FADE_SPD(10);	// フェードイン・アウトの速度


class FADE
{
public:
	enum tagFade {
		FADE_NON,		// フェード無し
		FADE_IN,		// フェードイン(徐々に明るくなる)
		FADE_OUT,		// フェードアウト(徐々に暗くなる)
		FADE_OUT_WAIT,	// フェードアウト後の真っ暗状態
	};
	tagFade m_sate;	// フェードを行うかどうか
	int		m_cnt;		// フェードの時間カウント

public:
	//	フェードリセット
	void ResetFade();
	//	フェード更新
	void UpdateFade();
	//	フェード描画
	void DrawFade();


	//	フェードインリクエスト
	void RequestFadeIn();
	//	フェードアウトリクエスト
	void RequestFadeOut();
	//	フェードインが終了したか
	int IsEndFadeIn();
	//	フェードアウトが終了したか
	int IsEndFadeOut();

};

