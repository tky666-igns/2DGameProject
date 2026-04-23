#include <DxLib.h>
#include "../common.h"
#include "fade.h"




//-------------------------------
//		フェードリセット
//-------------------------------
void FADE::ResetFade()
{
	m_sate = FADE_NON;
	m_cnt = 0;
}


//-------------------------------
//		フェード更新
//-------------------------------
void FADE::UpdateFade()
{
	switch (m_sate)
	{
	case FADE_IN:
		m_cnt -= FADE_SPD;
		if (m_cnt <= 0)
		{
			m_cnt = 0;
			m_sate = FADE_NON;
		}
		break;
	case FADE_OUT:
		m_cnt += FADE_SPD;
		if (m_cnt >= 255)
		{
			m_cnt = 255;
			m_sate = FADE_OUT_WAIT;
		}
		break;
	}
}


//-------------------------------
//		フェード描画
//-------------------------------
void FADE::DrawFade()
{
	switch (m_sate)
	{
	case FADE_IN:
	case FADE_OUT:
	case FADE_OUT_WAIT:
		// ここでアルファ値をセットする
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_cnt);
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
void FADE::RequestFadeIn()
{
	m_cnt = 255;
	m_sate = FADE_IN;
}


//-------------------------------
//		フェードアウトリクエスト
//-------------------------------
void FADE::RequestFadeOut()
{
	m_cnt = 0;
	m_sate = FADE_OUT;
}


//-------------------------------
//		フェードインが終了したか
//-------------------------------
int FADE::IsEndFadeIn()
{
	if (m_sate == FADE_IN)
		return 0;
	else
		return 1;
}


//-------------------------------
//		フェードアウトが終了したか
//-------------------------------
int FADE::IsEndFadeOut()
{
	if (m_sate == FADE_OUT)
		return 0;
	else
		return 1;
}