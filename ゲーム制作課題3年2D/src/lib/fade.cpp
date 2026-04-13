#include <DxLib.h>
#include "../common.h"

#define FADE_SPD	(10)	// フェードイン・アウトの速度

enum tagFade{
	FADE_NON,		// フェード無し
	FADE_IN,		// フェードイン(徐々に明るくなる)
	FADE_OUT,		// フェードアウト(徐々に暗くなる)
	FADE_OUT_WAIT,	// フェードアウト後の真っ暗状態
};

typedef struct{
	tagFade m_sate;	// フェードを行うかどうか
	int		m_cnt;		// フェードの時間カウント
}FADE_DATA;

FADE_DATA g_fade = { FADE_NON };


//-------------------------------
//		フェードリセット
//-------------------------------
void ResetFade()
{
	g_fade.m_sate = FADE_NON;
	g_fade.m_cnt = 0;
}


//-------------------------------
//		フェード更新
//-------------------------------
void UpdateFade()
{
	switch (g_fade.m_sate)
	{
	case FADE_IN:
		g_fade.m_cnt -= FADE_SPD;
		if (g_fade.m_cnt <= 0)
		{
			g_fade.m_cnt = 0;
			g_fade.m_sate = FADE_NON;
		}
		break;
	case FADE_OUT:
		g_fade.m_cnt += FADE_SPD;
		if (g_fade.m_cnt >= 255)
		{
			g_fade.m_cnt = 255;
			g_fade.m_sate = FADE_OUT_WAIT;
		}
		break;
	}
}


//-------------------------------
//		フェード描画
//-------------------------------
void DrawFade()
{
	switch (g_fade.m_sate)
	{
	case FADE_IN:
	case FADE_OUT:
	case FADE_OUT_WAIT:
		// ここでアルファ値をセットする
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, g_fade.m_cnt);
		// フェード用の黒い四角を表示
		DrawBox(0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y,
			GetColor(0, 0, 0), TRUE);
		// 他に影響を及ぼさないように、ここで設定を無効にする
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		break;
	}
}


//-------------------------------
//		フェードインリクエスト
//-------------------------------
void RequestFadeIn()
{
	g_fade.m_cnt = 255;
	g_fade.m_sate = FADE_IN;
}


//-------------------------------
//		フェードアウトリクエスト
//-------------------------------
void RequestFadeOut()
{
	g_fade.m_cnt = 0;
	g_fade.m_sate = FADE_OUT;
}


//-------------------------------
//		フェードインが終了したか
//-------------------------------
int IsEndFadeIn()
{
	if (g_fade.m_sate == FADE_IN)
		return 0;
	else
		return 1;
}


//-------------------------------
//		フェードアウトが終了したか
//-------------------------------
int IsEndFadeOut()
{
	if (g_fade.m_sate == FADE_OUT)
		return 0;
	else
		return 1;
}